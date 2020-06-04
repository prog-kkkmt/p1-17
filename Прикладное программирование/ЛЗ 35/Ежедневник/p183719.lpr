program p183719;
{ Таблица: Ежедневник
  1.Дата
  2.Заметки
}
uses
  crt,
  FileUtil,
  LazUtf8,
  SysUtils,
  Windows;

const
  MaxVSize = 30; { Максимальное количество записей }
type

    Tday = Word;              {тип - день}
    Tmonth = Word;            {тип - месяц}
    Tyear = Word;             {тип - год}
    Tnotes = string[30];         {тип - заметки}
    Tplanner = record            {тип - структура записи о ежедневнике}
    day : Tday;         {день}
    month : Tmonth;     {месяц}
    year :  Tyear;      {год}
    notes : Tnotes;     {заметки}
    end;

  TFileName   = string[30]; { Тип - Имя файла } /// 30
  TVector     = array[1..MaxVSize] of integer; { Тип - Массив номеров записей }
  TPlannerFile  = file of Tplanner; { Тип - Файл записей о ежедневнике}

  { Храним в одной переменной и массив номеров записей, и фактический размер массива }
  { Таких массивов может быть несколько, если потребуется упорядочить список книг
    еще по каким-то критериям, например, по названию книг в алфавитном порядке }

  TIndex      = record
    v: TVector;
    vSize: integer; { Используемый размер массива (число записей) }
  end;
  var
  iChoice  : integer;    { Выбранный пункт меню }
  IsReady  : boolean;    { Файл открыт для работы }
  idx      : TIndex;     { Массив номеров записей }
  f        : TPlannerFile; { Файл записей о ежедневнике }
  fname    : TFileName;  { Имя файла записей о ежедневнике }
  Memplanner  : Tplanner;      { Карточка книги или шаблон для поиска / упорядочения }
  procedure append(var f: TPlannerFile; planner: Tplanner);
{ Добавление записи в файл }
begin
  seek(f, filesize(f)); { В конец файла }
  write(f, planner);
end; { append }

procedure OpenOrCreate(const fname: TFileName; var f: TPlannerFile; var IsReady: boolean);
{ Открытие или создание файла }
begin
  if fName='' then
    begin

    IsReady := false
    end
  else
    begin
      {$I-}
      Assign(f, fName);
      Reset(f);
      {$I+}
      IsReady := IOResult = 0;

      if not IsReady then { Если файл не сушествует, пробуем создать новый файл с таким именем }
        begin
          {$I-}
          Rewrite(f);
          {$I+}
          IsReady := IOResult = 0;

          { Если не удалось ни открыть, ни создать, дальнейшая работа будет невозможна }
        end;
    end;
end;  { OpenOrCreate }

procedure GetNote(var planner: Tplanner);
{ Получение значения записи с клавиатуры }
var

  notes: UTF8string;
begin
  clrscr;

  write(UTF8ToAnsi('Заметки  > '));
  readln(notes);
  DecodeDate(Now, planner.year, planner.month, planner.day);
  planner.notes:=notes;
end; { Planner }

procedure menu;
{ Меню }
begin
  clrscr;
  Writeln(UTF8ToAnsi(' 0.Выход'));
  Writeln(UTF8ToAnsi(' 1.Cоздание / открытие файла'));
  Writeln(UTF8ToAnsi(' 2.Добавление записи'));
  Writeln(UTF8ToAnsi(' 3.Вывод заметок'));
  Write  (UTF8ToAnsi(' Выбран пункт:'));
end; { Menu }

procedure PrintPlanner(
  const planner: Tplanner;
  const lines: integer;
  const i: integer);
{ Печать одной книги, возможно, включая строку заголовка и подсказку для продолжения }
begin
  if i mod lines = 0 then { Печатаем по lines строк на экране }
    begin
      if i<>0 then
        begin
          write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
          readln;
        end;
      ClrScr;
      writeln(UTF8ToAnsi('Дата              Заметки'));
    end;
  writeln(
    planner.day, '.', planner.month, '.',
    planner.year, UTF8ToConsole('        '),  UTF8ToConsole(planner.notes));
  { Располагаем по левому краю. Лучше написать функцию padl }
end; { PrintPlanner }

procedure PrintAll(var f: TPlannerFile; const lines: integer);
{ Построчная печать файла }
var
  i: integer;
  fSize: integer;
  planner: Tplanner;
begin
  ClrScr;
  fSize:= filesize(f)-1; { Число записей }
  seek(f,0);             { На начало файла }
  for i:= 0 to fSize do  { Обрабатываем каждую запись }
    begin
      read(f,planner);
      PrintPlanner(planner,lines,i);
    end;
  write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
  readln;
end; { show }

procedure PrintIdx(
  var f: TPlannerFile;
  const idx: TIndex;
  const lines: integer);
{ Печать файла с использованием массива номеров записей }
var
  i: integer;
  planner: Tplanner;
begin
  for i:= 1 to idx.vSize do { Для каждого используемого элемента массива номеров записей }
    begin
      seek(f,idx.v[i]); { Переходим к записи, указанной в массиве }
      read(f,planner);     { Читаем }
      PrintPlanner(planner,lines,i-1); { Печатаем }
    end;
  write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
  readln;
end; { PrintIdx }

procedure swap(var i1, i2: integer);
{ Обмен содержимого двух целых переменных }
var
  tmp: integer;
begin
  tmp := i1;
  i1 := i2;
  i2 := tmp;
end; { swap }

procedure sort(var f: TPlannerFile; var idx: TIndex);
{ Сортировка индексного массива "пузырьком"}
{ Эта процедура неоптимальна. Число чтений из файла можно уменьшить }
var
  i,j : integer;
  planner1, planner2: Tplanner;
begin
  for i:= 1 to idx.vSize-1 do
    for j:= idx.vSize downto i+1 do
        begin
          { Это место программы самое слабое }
          { Фактически запись из файла читается дважды }
          seek(f,idx.v[j-1]);
          read(f,planner1);
          seek(f,idx.v[j]);
          read(f,planner2);
          if (planner2.year<planner1.year) then { Если записи не упорядочены, меняем их номера в массиве }
            swap(idx.v[j], idx.v[j-1]);
        end;
end; { sort }

procedure LoadIdx(var f: TPlannerFile; var idx: TIndex; const etalon: Tplanner);
{ Загрузка номеров записей в индексный массив }
var
  i: integer;
  planner: Tplanner;
  fSize: integer;
begin
  idx.vSize := 0;
  fSize := filesize(f)-1;
  seek(f,0);
  for i:= 0 to fSize do { Обрабатываем файл }
    begin
      read(f,planner);
      if planner.notes = etalon.notes then { В массив заносим номера строк по фильтру }
        begin
          inc(idx.vSize); { Заполняем следующий элемент массива }
          idx.v[idx.vSize] := filepos(f)-1;
        end;
    end;
end; { LoadIdx }

begin { main }
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  writeln(UTF8ToConsole('Выполнила: Саполетова Анастасия П1-17'));
  writeln(UTF8ToConsole('Тема: Ежедневник'));
  readln;

  iChoice    := 0;      { По умолчанию устанавливаем "Выход" }
  IsReady    := false;  { Файл не открыт }
  while true do begin
    menu;
    readln( iChoice );
    case iChoice of
      0: { выход }
      begin
        write(UTF8ToConsole('Завершение работы'));
        readln;
        if isReady then close(f);
        exit;
      end;
      1: { открытие/создание файла }
      begin
        If isReady then
          write(UTF8ToConsole('Файл уже открыт'))
        else
          begin
            write(UTF8ToConsole('Полный путь к файлу > '));
            readln(fName);
            OpenOrCreate(fName, f, IsReady);
            readln;
          end;
      end;
      2: { добавление записи }
      begin
        if IsReady then
          begin
            GetNote(Memplanner);  { Прочли карточку книги }
            append(f,Memplanner); { Добавили в конец файла }
          end
        else
          begin
            write(UTF8ToAnsi('Файл не открыт'));
            readln;
          end;
      end;

      3: { Печать исходного файла }
      begin
        if IsReady then
          PrintAll(f, 10)
          { Печатаем все записи файла в исходном порядке, по 10 строк на экране }
        else
          write(UTF8ToAnsi('Файл не открыт'));
        readln;
      end;
    end; { case }
  end;
end.








