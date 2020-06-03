{*
  Учебная программа.
  03.06.2020
*}
program Uchebnaia;
{ Создать файл, содержащий сведения о книгах в библиотеке.
Формат сведений: фамилия автора, название книги, год издания.
Отчеты.
1. Книги указанного автора в хронологическом порядке.
2. Исходный неупорядоченный список. }
{ Gusyatiner L.B. aka lamed RFPRO, 01.07.2011 / МГОТУ ККМТ, 12.05.2019}
uses
  crt,
  FileUtil,
  LazUtf8,
  SysUtils,
  Windows;

const
  MaxVSize = 200; { Максимальный размер массива номеров записей }

type
  TAuthor = string[20]; { Тип - Фамилия автора } /// 20
  TTitle = string[30];  { Тип - Название книги } /// 30
  TYear = integer;      { Тип - Год издания }
  TBook = record        { Тип - Структура записи о книге }
    author: TAuthor;    { Автор }
    title : TTitle;     { Название }
    year  : TYear;      { Год издания }
  end;
  TFileName   = string[30]; { Тип - Имя файла } /// 30
  TVector     = array[1..MaxVSize] of integer; { Тип - Массив номеров записей }
  TBooksFile  = file of TBook; { Тип - Файл записей о книгах }

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
  f        : TBooksFile; { Файл записей о книгах }
  fname    : TFileName;  { Имя файла записей о книгах }
  Membook  : Tbook;      { Карточка книги или шаблон для поиска / упорядочения }

procedure append(var f: TBooksFile; book: Tbook);
{ Добавление записи в файл }
begin
  seek(f, filesize(f)); { В конец файла }
  write(f, book);
end; { append }

procedure OpenOrCreate(const fname: TFileName; var f: TBooksFile; var IsReady: boolean);
{ Открытие или создание файла }
begin
  if fName='' then
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

procedure GetAuthor(var book: Tbook);
{ Получение значения записи с клавиатуры }
var
  author: UTF8string;
begin
  clrscr;
  write(UTF8ToAnsi('Автор       > '));
  readln(author);
  book.author:=author;
end; { GetAuthor }

procedure Getbook(var book: Tbook);
{ Получение значения записи с клавиатуры }
var
  author: UTF8string;
  title: UTF8string;
  year: integer;
begin
  clrscr;
  write(UTF8ToAnsi('Автор       > '));
  readln(author);

  write(UTF8ToAnsi('Название    > '));
  readln(title);

  write(UTF8ToAnsi('Год издания > '));
  readln(year);

  book.author:=author;
  book.title:=title;
  book.year:=year;
end; { Getbook }

procedure menu;
{ Меню }
begin
  clrscr;
  Writeln(UTF8ToAnsi(' 0.Выход'));
  Writeln(UTF8ToAnsi(' 1.Cоздание / открытие файла'));
  Writeln(UTF8ToAnsi(' 2.Добавление записи'));
  Writeln(UTF8ToAnsi(' 3.Книги автора'));
  Writeln(UTF8ToAnsi(' 4.Все книги'));
  Write  (UTF8ToAnsi(' Выбран пункт:'));
end; { Menu }

procedure PrintBook(
  const book: TBook;
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
      writeln(UTF8ToAnsi('Автор               Название                      Год изд.'));
    end;
  writeln(
    UTF8ToConsole(book.author), ' ':20-length(book.author),
    UTF8ToConsole(book.title),' ':30-length(book.title),
    book.year); { Располагаем по левому краю. Лучше написать функцию padl }
end; { PrintBook }

procedure PrintAll(var f: TBooksFile; const lines: integer);
{ Построчная печать файла }
var
  i: integer;
  fSize: integer;
  book: TBook;
begin
  ClrScr;
  fSize:= filesize(f)-1; { Число записей }
  seek(f,0);             { На начало файла }
  for i:= 0 to fSize do  { Обрабатываем каждую запись }
    begin
      read(f,book);
      PrintBook(book,lines,i);
    end;
  write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
  readln;
end; { show }

procedure PrintIdx(
  var f: TBooksFile;
  const idx: TIndex;
  const lines: integer);
{ Печать файла с использованием массива номеров записей }
var
  i: integer;
  book: Tbook;
begin
  for i:= 1 to idx.vSize do { Для каждого используемого элемента массива номеров записей }
    begin
      seek(f,idx.v[i]); { Переходим к записи, указанной в массиве }
      read(f,book);     { Читаем }
      PrintBook(book,lines,i-1); { Печатаем }
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

procedure sort(var f: TBooksFile; var idx: TIndex);
{ Сортировка индексного массива "пузырьком"}
{ Эта процедура неоптимальна. Число чтений из файла можно уменьшить }
var
  i,j : integer;
  book1, book2: Tbook;
begin
  for i:= 1 to idx.vSize-1 do
    for j:= idx.vSize downto i+1 do
        begin
          { Это место программы самое слабое }
          { Фактически запись из файла читается дважды }
          seek(f,idx.v[j-1]);
          read(f,book1);
          seek(f,idx.v[j]);
          read(f,book2);
          if (book2.year<book1.year) then { Если записи не упорядочены, меняем их номера в массиве }
            swap(idx.v[j], idx.v[j-1]);
        end;
end; { sort }

procedure LoadIdx(var f: TBooksFile; var idx: TIndex; const etalon: TBook);
{ Загрузка номеров записей в индексный массив }
var
  i: integer;
  book: Tbook;
  fSize: integer;
begin
  idx.vSize := 0;
  fSize := filesize(f)-1;
  seek(f,0);
  for i:= 0 to fSize do { Обрабатываем файл }
    begin
      read(f,book);
      if book.author = etalon.author then { В массив заносим номера строк по фильтру }
        begin
          inc(idx.vSize); { Заполняем следующий элемент массива }
          idx.v[idx.vSize] := filepos(f)-1;
        end;
    end;
end; { LoadIdx }

begin { main }
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  writeln(UTF8ToConsole('Минимальный курсовой по МДК.01.02 "Прикладное программирование"'));
  writeln(UTF8ToConsole('П1-16, П2-16, П3-16, 2019 г.'));
  writeln(UTF8ToConsole('Тема: Библиотека'));
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
            GetBook(MemBook);  { Прочли карточку книги }
            append(f,Membook); { Добавили в конец файла }
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
            GetAuthor(MemBook); { Получили фамилию автора }
            LoadIdx(f, idx, MemBook); { Загрузили массив номеров строк из файла }
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

