unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Grids,
  ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    StringGrid1: TStringGrid;
    procedure Edit3EditingDone(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;
  rows, columns: integer;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Edit3EditingDone(Sender: TObject);
begin
     rows:=StrToInt(Edit2.Text);
     columns:=StrToInt(Edit3.Text);
     StringGrid1.RowCount:=rows+1;
     StringGrid1.ColCount:=columns+1;
     StringGrid1.Cells[columns,rows]:=Edit1.Text;
end;

end.

