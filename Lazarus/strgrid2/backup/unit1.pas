unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Grids;

type

  { TForm1 }

  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    StringGrid1: TStringGrid;
    procedure Edit2EditingDone(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }


procedure TForm1.Edit2EditingDone(Sender: TObject);
  var
  A:array [0..20, 0..20] of integer;
  i,j, len1, len2, max, maxi, maxj: integer;
  st: string;
  strg: TStringGrid;

  begin
  len1:=StrToInt(Edit1.Text)-1;
  len2:=StrToInt(Edit2.Text)-1;
  for i := 0 to len1 do
    for j := 0 to len2 do begin
      A[i,j]:=Random(len1);
      insert(IntToStr(A[i,j]), st, Length(st)+1);
      insert(' ', st, Length(st)+1);
    end;
  Edit3.Text:=st;
  max:=A[0, 0];
  for i := 0 to len1 do
    for j := 0 to len2 do begin
        if (A[i,j] > max) then begin
           max:=A[i, j];
           maxi:=i;
           maxj:=j;
        end;
    end;
  StringGrid1.ColCount:=max+2;
  StringGrid1.RowCount:=max+2;
  for i := 1 to max+1 do
    for j := 1 to max+1 do
        StringGrid1.Cells[i,j]:="x";
  end;

end.

