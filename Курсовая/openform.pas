unit openform;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TOpen_Form }

  TOpen_Form = class(TForm)  //класс главной формы
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Open: TButton;
    procedure OpenClick(Sender: TObject);
  private

  public

  end;

var
  Open_Form: TOpen_Form;

implementation
uses
  MainForm;

{$R *.lfm}

{ TOpen_Form }

procedure TOpen_Form.OpenClick(Sender: TObject);
begin
  Main_Form.Show;  //открытие главной формы
end;

end.

