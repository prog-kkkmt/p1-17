program rate;
{ Таблица "Тариф"
1. Код тарифа
2. Макс расстояние
3. Мин расстояние
4. Цена}
uses windows,
     CRT;
const
  MaxR = 50;//макс кол-во возможный записей

type
  RCode = integer; //Код тарифа
  RMinDist = integer; //Мин расстояние
  RMaxDist = integer; //Макс расстояние
  RPrice = integer;  //Цена
  RBook = record //struct rate's record
        code: RCode; //код тарифа
        minDist : RMinDist; //min distance
        maxDist  : RMaxDist; //max distance
        price : RPrice //price
  end;

NameFile = string[30];  // Имя файла
RMas = array[1..MaxR] of integer; //массив колва записей
RBookFile = file of RBook; //file of rate's records

RIndex = record //запись из переменных : массив колва записей и размер массива(фактический)
r: Rmas;  //mas of number records
rSize: integer;
end;

 var
  number : integer; //menu's point
  IsReady : boolean; //file is open
  index : RIndex;  // mas of record RIndex ( Rmas, rSize )
  f : RBookFile; //file of rate's records
  fname : NameFile; //file's records name
  Membook  : RBook; //rate's card

procedure append(var f: RBookFile; Membook: Rbook); //append and write record to file
begin
  seek(f, filesize(f)); //to the end of file
  write(f, Membook);//writing record
end;
procedure orc(const fname: NameFile; var f: RBookFile; var IsReady: boolean);//open/create file
begin
  if fname = '' then
    IsReady := false
  else
    begin
      {$I-} //compiler directive
      Assign(f, fname); //Для связи файла в коде программы и действительного файла на внешнем носителе
      Reset(f); //open fo reading
      {$I+}
      IsReady := IOResult = 0;
      if IOResult <> 0 then //create new file
        begin
          {$I-}
          Rewrite(f);//create file
          {$I+}
          IsReady := IOResult = 0;
        end;
    end;
end;
procedure GetRbook(var Membook: Rbook); //reading from keybord
var
  code: integer;
  minDist : integer;
  maxDist: integer;
  price: integer;
begin
  write('code: ');
  readln(code);

  write('min distance: ');
  readln(minDist);

  write('max distance: ');
  readln(maxDist);

  write('price: ');
  readln(price);

  Membook.code := code;
  Membook.minDist := minDist;
  Membook.maxDist := maxDist;
  Membook.price := price;
end;

procedure menu;
begin
  Writeln('Menu');
  Writeln(' 0.Exit');
  Writeln(' 1.Create/Open file');
  Writeln(' 2.Append record');
  Writeln(' 3.Print all');
  Write(' Number : ');
end; { Menu }

procedure PrintRBook(const Membook: RBook; const lines: integer; const i: integer); //print record
begin
  if i mod lines = 0 then
    begin
      if i <> 0 then
        begin
          write('Press any key to continue...');
          readln;
        end;
      writeln('Code Rate/Min distance/Max distance/Price');
    end;
  writeln(      //output
  Membook.code, '    ',
  Membook.minDist, '    ',
  Membook.maxDist, '    ',
  Membook.price);
end;

procedure PrintRBooks(var f: RBookFile; const lines: integer); //print file content
var
  i: integer;
  fSize: integer;
  Membook: RBook;
begin
  fSize:= filesize(f)-1; //number of records
  seek(f,0); //to start of file
  for i := 0 to fSize do  //treatment
    begin
      read(f,Membook);
      PrintRBook(Membook,lines,i);// print record
    end;
  writeln('Press any key to continue...');
  readln;
  ClrScr;
end;
begin //main
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  writeln('Table: Rate');
  writeln('Press any key to continue...');
  readln;
  ClrScr;
  number := 0;
  IsReady := false;

  while true do begin
    menu;
    readln( number );
    case number of
      0: //exit
      begin
        write('Exit');
        readln;
        if isReady then close(f);
        exit;
      end;
      1: //open/create file
      begin
        If isReady then
          write('File is open')
        else
          begin
            write('Enter the path to file : ');
            readln(fname);
            Orc(fname, f, IsReady);
            writeln('Press any key to continue...');
            readln;
            ClrScr;
          end;
      end;
      2:
      begin
        if IsReady then
          begin
            GetRBook(MemBook);
            append(f,Membook);
          end
        else
          begin
            writeln('File is not open');
            writeln('Press any key to continue...');
            readln;
            ClrScr;
          end;
      end;
      3: //print all
      begin
        if IsReady then
          PrintRBooks(f, 15)  //вывод по 15 строк
        else
          begin
          writeln('File is not open');
          writeln('Press any key to continue...');
          readln;
          ClrScr;
          end
      end;
    end;
  end;
end.
