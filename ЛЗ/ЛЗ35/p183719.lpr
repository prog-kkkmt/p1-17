program p183719;

uses
  crt,
  FileUtil,
  LazUtf8,
  SysUtils,
  Windows;

const
  MaxVSize = 200;
{
struct Person
	int personiD;
	string Fio;
	string passport;
}
type
  TFio = string[100];
  Tpassport = string[30];
  TpersoniD = integer;
  TPerson = record
    Fio: TFio;
    passport : Tpassport;
    personiD  : TpersoniD;
  end;
  TFileName   = string[30];
  TVector     = array[1..MaxVSize] of integer;
  TPersonsFile  = file of TPerson;



  TIndex      = record
    v: TVector;
    vSize: integer;
  end;

var
  iChoice  : integer;
  IsReady  : boolean;
  idx      : TIndex;
  f        : TPersonsFile;
  fname    : TFileName;
  Memperson  : Tperson;

procedure append(var f: TPersonsFile; person: Tperson);

begin
  seek(f, filesize(f));
  write(f, person);
end;

procedure OpenOrCreate(const fname: TFileName; var f: TPersonsFile; var IsReady: boolean);

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
end;

procedure GetFio(var person: Tperson);

var
  Fio: UTF8string;
begin
  clrscr;
  write(UTF8ToAnsi('Ф.И.О.       > '));
  readln(Fio);
  person.Fio:=Fio;
end; { GetFio }

procedure Getperson(var person: Tperson);

var
  Fio: UTF8string;
  passport: UTF8string;
  personiD: integer;
begin
  clrscr;

  write(UTF8ToAnsi('Код гражданина > '));
  readln(personiD);

  write(UTF8ToAnsi('Ф.И.О.      > '));
  readln(Fio);

  write(UTF8ToAnsi('Паспорт    > '));
  readln(passport);



  person.Fio:=Fio;
  person.passport:=passport;
  person.personiD:=personiD;
end; { Getperson }

procedure menu;

begin
  clrscr;
  Writeln(UTF8ToAnsi(' 1| Cоздание / открытие файла'));
  Writeln(UTF8ToAnsi(' 2| Добавление записи'));
  Writeln(UTF8ToAnsi(' 3| Поиск по ФИО'));
  Writeln(UTF8ToAnsi(' 4| Все Граждане'));
  Writeln(UTF8ToAnsi(' 0| Выход'));
  Write  (UTF8ToAnsi(' Выбран пункт:'));
  Writeln();
end;

procedure PrintPerson(
  const person: TPerson;
  const lines: integer;
  const i: integer);

begin
  if i mod lines = 0 then
    begin
      if i<>0 then
        begin
          write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
          readln;
        end;
      ClrScr;
      writeln(UTF8ToAnsi('ФИО                       Паспорт                Код гражданина'));
    end;
  writeln(
    UTF8ToConsole(person.Fio), ' ':20-length(person.Fio),
    UTF8ToConsole(person.passport),' ':30-length(person.passport),
    person.personiD);
end; { PrintPerson }

procedure PrintAll(var f: TPersonsFile; const lines: integer);

var
  i: integer;
  fSize: integer;
  person: TPerson;
begin
  ClrScr;
  fSize:= filesize(f)-1;
  seek(f,0);
  for i:= 0 to fSize do
    begin
      read(f,person);
      PrintPerson(person,lines,i);
    end;
  write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
  readln;
end; { show }

procedure PrintIdx(
  var f: TPersonsFile;
  const idx: TIndex;
  const lines: integer);

var
  i: integer;
  person: Tperson;
begin
  for i:= 1 to idx.vSize do
    begin
      seek(f,idx.v[i]);
      read(f,person);
      PrintPerson(person,lines,i-1);
    end;
  write(UTF8ToAnsi('Нажмите клавишу для продолжения >'));
  readln;
end;

procedure swap(var i1, i2: integer);

var
  tmp: integer;
begin
  tmp := i1;
  i1 := i2;
  i2 := tmp;
end; { swap }

procedure sort(var f: TPersonsFile; var idx: TIndex);

var
  i,j : integer;
  person1, person2: Tperson;
begin
  for i:= 1 to idx.vSize-1 do
    for j:= idx.vSize downto i+1 do
        begin

          seek(f,idx.v[j-1]);
          read(f,person1);
          seek(f,idx.v[j]);
          read(f,person2);
          if (person2.personiD<person1.personiD) then
            swap(idx.v[j], idx.v[j-1]);
        end;
end; { sort }

procedure LoadIdx(var f: TPersonsFile; var idx: TIndex; const etalon: TPerson);

var
  i: integer;
  person: Tperson;
  fSize: integer;
begin
  idx.vSize := 0;
  fSize := filesize(f)-1;
  seek(f,0);
  for i:= 0 to fSize do
    begin
      read(f,person);
      if person.Fio = etalon.Fio then
        begin
          inc(idx.vSize);
          idx.v[idx.vSize] := filepos(f)-1;
        end;
    end;
end; { LoadIdx }

begin { main }
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  iChoice    := 0;
  IsReady    := false;
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
            GetPerson(MemPerson);
            append(f,Memperson);
          end
        else
          begin
            write(UTF8ToAnsi('Файл не открыт'));
            readln;
          end;
      end;
      3:
      begin
        if IsReady then
          begin
            GetFio(MemPerson);
            LoadIdx(f, idx, MemPerson);
            Sort(f, idx);
            PrintIdx(f, idx, 10);

          end
        else
          write(UTF8ToAnsi('Файл не открыт'));
        readln;
      end;
      4:
      begin
        if IsReady then
          PrintAll(f, 10)

        else
          write(UTF8ToAnsi('Файл не открыт'));
        readln;
      end;
    end; { case }
  end;
end.
