unit u_f2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, MaskEdit;

type

  { TForm3 }

  TForm3 = class(TForm)
    Input: TButton;
    InputFamily: TStaticText;
    procedure InputClick(Sender: TObject);
  private

  public

  end;

var
  Form3: TForm3;
  i:integer;
  l,k:string;

implementation
      uses Main;
{$R *.lfm}

      { TForm3 }

      procedure TForm3.InputClick(Sender: TObject);
      begin
        Main.kolday :=  Main.kolday  +1;
        for i:=0 to Main.Kolstudent-1 do begin
        setlength(Students[i].Oc,Main.kolday);{Расширяем динамический массив оценок}
          k:=InputBox('Введите оценку для студента ' + Students[i].secondname, 'Введите оценку', ' ');
               Students[i].Oc[j] := StrToInt(k);
        end;
        Main.Form1.Show;
        u_f2.Form3.Hide;
      end;

{ TForm3 }


end.

