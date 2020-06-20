unit openform;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TOpen_Form }

  TOpen_Form = class(TForm)  //класс главной формы
    Label1: TLabel;          //текст
    Label2: TLabel;          //текст
    Label3: TLabel;          //текст
    Label4: TLabel;          //текст
    Label5: TLabel;          //текст
    Open: TButton;           //кнопка открытия
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

