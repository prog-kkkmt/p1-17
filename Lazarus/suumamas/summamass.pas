unit summamass;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, Grids;

type

  { TForm1 }

  TForm1 = class(TForm)    //объявление форм
    StringGrid1: TStringGrid;//ввод таблицы под массив
    StringGrid2: TStringGrid;//ввод таблицы под сумму
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.FormCreate(Sender: TObject);
var
   i, j, sum: Integer;
begin
     sum := 0;
     for i := 0 to 4 do begin
         for j := 0 to 4 do begin //цикл на ввод двумерного массива
             StringGrid1.Cells[i, j] := IntToStr(Random(100));//присвоение элемнтам массива рандомным значениям
             sum := sum + StrToInt(StringGrid1.Cells[i, j]); //подсчет суммы элементов столбца
             StringGrid2.Cells[i, 0] := IntToStr(sum); //вывод суммы
         end;
         sum := 0;
     end;


   end;
end;
end.

