program RestarauntMenu;
{Таблица Меню заведения
1. Код блюда
2. Название
3. Цена
4. Время приготовления }

uses
  crt,
  SysUtils,
  Windows;

const
  MaxSize = 300; { Максимальное кол-во записей}
type
  DishCode = integer; { Тип - Код блюда }
  DishName = string[30];  {Тип - Название блюда }
  DishPrice = integer;      { Тип - Цена }
  CookingTime = string[10]; { Тип - Время приготовления }

  Dish = record        { Тип - Структура записи Меню заведения }
    code : DishCode;
    name : DishName;
    price  : Dishprice;
    time : CookingTime;
  end;
  FileName = string[30];
var
  f        : file of Dish; { Файл записей о книгах }
  fname    : string[50];  { Имя файла записей о книгах }
  n : integer; {текущее кол-во записей массива}

procedure OpenOrCreate(const fname: FileName; var f: file; var IsReady: boolean);
{ Открытие или создание файла }
begin
  if fname='' then
    IsReady := false
  else
    begin
      {$I-}
      Assign(f, fName);
      write(fName);
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

procedure Input(var dish : array of Dish);
begin
     writeln(UTF8ToAnsi('Введите код блюда'));
     readln(dish[n].code);
     writeln(UTF8ToAnsi('Введите название блюда'));
     readln(dish[n].name);
     writeln(UTF8ToAnsi('Введите цена блюда'));
     readln(dish[n].price);
     writeln(UTF8ToAnsi('Введите время приготовления блюда'));
     readln(dish[n].time);
     n := n + 1;
end;
procedure Output(var dish : array of Dish);
var
  i : integer;
begin
     seek(f, filesize(f));
     for i := 0 to n - 1 do
         write(f, dish[i]);
     for i := 0 to n - 1 do
         writeln(dish[i].code, ' ', dish[i].name, ' ', dish[i].price, ' ', dish[i].time);

end;
procedure Search(var dish : array of Dish);
var
  buf : string[30];
  i : integer;
begin
     writeln(UTF8ToAnsi('Введите название блюда для поиска информации'));
     readln(buf);
     for i := 0 to n - 1  do
         if dish[i].name = buf then
            writeln(dish[i].code, ' ', dish[i].name, ' ', dish[i].price, ' ', dish[i].time);
end;

procedure Menu;
var
   num : integer;
   isReady : boolean;
   dishes : array [0..MaxSize] of Dish;
begin
     n := 0;
     fName := '';
     IsReady := false;
     writeln(UTF8ToAnsi('0. Открытие/создание файла'));
     writeln(UTF8ToAnsi('1. Добваление записей'));
     writeln(UTF8ToAnsi('2. Запись в файл'));
     writeln(UTF8ToAnsi('3. Поиск записи в файле'));
     writeln(UTF8ToAnsi('4. Выход'));

     while true do
     begin
     writeln(UTF8ToAnsi('Введите номер выполняемого действия'));
     readln(num);
     case num of
          0:
          begin
               If isReady then
                  write(UTF8ToAnsi('Файл уже открыт'))
               else
                   begin
                        readln(fName);
                        OpenOrCreate(fName, f, IsReady);
                        readln;
                   end;
          end;
          1:
            Input(dishes);
          2:
            Output(dishes);
          3:
            Search(dishes);
          4: exit;

     end;
     end;


end;

begin

       Menu;
end.

