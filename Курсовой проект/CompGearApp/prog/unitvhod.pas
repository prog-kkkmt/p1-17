unit unitVhod;

{$mode objfpc}{$H+}

interface

uses
  unitOrders, Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TFormVhod }

  TFormVhod = class(TForm)
    ButtonVhod: TButton;
    EditPassword: TEdit;
    EditLogin: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    procedure ButtonVhodClick(Sender: TObject);
  private

  public

  end;

var
  FormVhod: TFormVhod;

implementation

{$R *.lfm}

uses unitDM;

{ TFormVhod }

procedure TFormVhod.ButtonVhodClick(Sender: TObject);
//при нажатии на кнопку "вход"
begin
  unitDM.DM.QueryVhod.Close;
  unitDM.DM.QueryVhod.Open;
  while not(unitDM.DM.QueryVhod.eof) do
  //проходим по запросу с логинами и паролями
     begin
          if (editLogin.Text = unitDM.DM.QueryVhod.FieldByName('LOGIN_WORKER').AsString) and (editPassword.Text = unitDM.DM.QueryVhod.FieldByName('PASSWORD_WORKER').AsString) then
          //если связка логина и пароля обнаружена
          begin
             FormOrdersShow.Show;
             //окрываем нужную форму
             exit;
             //заканчиваем поиск
          end;
          unitDM.DM.QueryVhod.next;
          //сдвигаем указатель
     end;
  ShowMessage('Неверно введен логин или пароль. Повторите попытку.');
end;

end.

