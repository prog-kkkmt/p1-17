unit openform;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TOpen_Form }

  TOpen_Form = class(TForm)  //класс главной формы
    Label1: TLabel;          //курсовой проект
    Label2: TLabel;          //тема: "Ежедневник"
    Label3: TLabel;          //выполнила: Саполетова Анастасия
    Label4: TLabel;          //студентка группы П1-17
    Label5: TLabel;          //17.06.2020
    Label6: TLabel;          //текст
    Open: TButton;           //кнопка открытия "Базы данных"
    procedure OpenClick(Sender: TObject); //процедура открытия
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

procedure TOpen_Form.OpenClick(Sender: TObject);  //процедура события
begin
  Main_Form.Show;  //открытие главной формы
end;

end.

