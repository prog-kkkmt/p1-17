{*
  Учебная программа.
  Переделал Бобнев Алексей П1-17.
  03.06.2020
*}
program Uchebnaia_peredelanaia;///Название файла

uses
  crt,
  FileUtil,
  LazUtf8,
  SysUtils,
  Windows;

const
  MaxVSize = 200; { Максимальный размер массива номеров записей }

type
  TAuto = string[20]; { Тип - авто } /// 20
  TMarka = string[30];  {Марка авто}
  TYear = integer;      { Тип - Год выпуска }
  TCar = record         ///Запсись
    auto: TAuto;    { Авто }
    marka : TMarka;     { Марка }
    year  : TYear;      { Год выпуска }
  end;
  TFileName   = string[30]; { Тип - Имя файла } /// 30
  TVector     = array[1..MaxVSize] of integer; { Тип - Массив номеров записей }
  TCarsFile  = file of TCar; ///Файл

  TIndex      = record ///Запись
    v: TVector;
    vSize: integer; { Используемый размер массива (число записей) }
  end;

var   ///Элементы
  iChoice  : integer;    { Выбранный пункт меню }
  IsReady  : boolean;    { Файл открыт для работы }
  idx      : TIndex;     { Массив номеров записей }
  f        : TCarsFile;
  fname    : TFileName;
  Memcar  : Tcar;

procedure append(var f: TCarsFile; car: Tcar);
{ Добавление записи в файл }
begin
  seek(f, filesize(f)); { В конец файла }
  write(f, car);
end; { append }

procedure OpenOrCreate(const fname: TFileName; var f: TCarsFile; var IsReady: boolean);
{ Открытие или создание файла }
begin
  if fName='' then  ///Условие
    IsReady := false
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

procedure GetAuto(var car: Tcar);
{ Получение значения записи с клавиатуры }
var
  auto: UTF8string;///Элемент
begin
  clrscr;
  write(UTF8ToAnsi('Авто       > '));
  readln(auto);
  car.auto:=auto;
end; { GetAuto }

procedure Getcar(var car: Tcar);
{ Получение значения записи с клавиатуры }
var
  auto: UTF8string;
  marka: UTF8string;
  year: integer;
begin ///Ввод
  clrscr;
  write(UTF8ToAnsi('Марка авто       > '));
  readln(auto);

  write(UTF8ToAnsi('Модель автомобиля    > '));
  readln(marka);

  write(UTF8ToAnsi('Год выпуска > '));
  readln(year);

  car.auto:=auto;
  car.marka:=marka;
  car.year:=year;
end;

procedure menu;
{ Меню }
begin
  clrscr;
  Writeln(UTF8ToAnsi(' 0.Выход'));
  Writeln(UTF8ToAnsi(' 1.Cоздание / открытие файла'));
  Writeln(UTF8ToAnsi(' 2.Добавление записи'));
  Writeln(UTF8ToAnsi(' 3.Все марки авто'));
  Writeln(UTF8ToAnsi(' 4.Все авто'));
  Write  (UTF8ToAnsi(' Выбран пункт:'));
end; { Menu }

procedure PrintCar(
  const car: TCar;
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
      writeln(UTF8ToAnsi('Авто               Марка                      Год выпуска'));///Вывод на экран
    end;
  writeln(
    UTF8ToConsole(car.auto), ' ':20-length(car.auto),
    UTF8ToConsole(car.marka),' ':30-length(car.marka),
    car.year); { Располагаем по левому краю. Лучше написать функцию padl }
end; { PrintBook }

procedure PrintAll(var f: TCarsFile; const lines: integer);
{ Построчная печать файла }
var
  i: integer;
  fSize: integer;
  car: TCar;
begin
  ClrScr;
  fSize:= filesize(f)-1; { Число записей }
  seek(f,0);             { На начало файла }
  for i:= 0 to fSize do  { Обрабатываем каждую запись }
    begin
      read(f,car);///Читаем из файла
      PrintCar(car,lines,i);
    end;
  write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
  readln;
end; { show }

procedure PrintIdx(
  var f: TCarsFile;
  const idx: TIndex; ///Константа
  const lines: integer);
{ Печать файла с использованием массива номеров записей }
var
  i: integer;
  car: Tcar;
begin
  for i:= 1 to idx.vSize do { Для каждого используемого элемента массива номеров записей }
    begin
      seek(f,idx.v[i]); { Переходим к записи, указанной в массиве }
      read(f,car);     { Читаем }
      PrintCar(car,lines,i-1); { Печатаем }
    end;
  write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
  readln;
end; { PrintIdx }

procedure swap(var i1, i2: integer);
{ Обмен содержимого двух целых переменных }
var
  tmp: integer;
begin
  tmp := i1;///Обмен
  i1 := i2;
  i2 := tmp;
end; { swap }

procedure sort(var f: TCarsFile; var idx: TIndex);
{ Сортировка индексного массива "пузырьком"}
{ Эта процедура неоптимальна. Число чтений из файла можно уменьшить }
var
  i,j : integer;
  car1, car2: Tcar;
begin
  for i:= 1 to idx.vSize-1 do
    for j:= idx.vSize downto i+1 do
        begin
          { Это место программы самое слабое }
          { Фактически запись из файла читается дважды }
          seek(f,idx.v[j-1]);
          read(f,car1);
          seek(f,idx.v[j]);
          read(f,car2);
          if (car2.year<car1.year) then { Если записи не упорядочены, меняем их номера в массиве }
            swap(idx.v[j], idx.v[j-1]);
        end;
end; { sort }

procedure LoadIdx(var f: TCarsFile; var idx: TIndex; const etalon: TCar);
{ Загрузка номеров записей в индексный массив }
var
  i: integer;
  car: Tcar;
  fSize: integer;
begin
  idx.vSize := 0;
  fSize := filesize(f)-1;
  seek(f,0);
  for i:= 0 to fSize do { Обрабатываем файл }
    begin
      read(f,car);
      if car.auto = etalon.auto then { В массив заносим номера строк по фильтру }
        begin
          inc(idx.vSize); { Заполняем следующий элемент массива }
          idx.v[idx.vSize] := filepos(f)-1;
        end;
    end;
end; { LoadIdx }

begin { main }
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  writeln(UTF8ToConsole('Программа про автомобили'));///Название программы

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
            GetCar(MemCar);  { Прочли карточку книги }
            append(f,Memcar); { Добавили в конец файла }
          end
        else
          begin
            write(UTF8ToAnsi('Файл не открыт'));
            readln;
          end;
      end;
      3: { Выбор автора и печать его книг в хронологическом порядке }
      begin
        if IsReady then
          begin
            GetAuto(MemCar); { Получили фамилию автора }
            LoadIdx(f, idx, MemCar); { Загрузили массив номеров строк из файла }
            Sort(f, idx);        { Сортируем массив }
            PrintIdx(f, idx, 10);
            { Печатаем записи файла в порядке следования в массиве, по 10 строк на экране }
          end
        else
          write(UTF8ToAnsi('Файл не открыт'));
        readln;
      end;
      4: { Печать исходного файла }
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

