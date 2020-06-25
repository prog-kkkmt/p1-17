unit unitVhod;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, unitOrders;

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
begin
  unitDM.DM.QueryVhod.Close;
  unitDM.DM.QueryVhod.Open;
  while not(unitDM.DM.QueryVhod.eof) do //проходим по запросу с именами групп
           begin
             if (editLogin.Text = unitDM.DM.QueryVhod.FieldByName('LOGIN_WORKER').AsString) and (editPassword.Text = unitDM.DM.QueryVhod.FieldByName('PASSWORD_WORKER').AsString) then
             begin
                  FormOrdersShow.Show;
                  exit;
             end;
             unitDM.DM.QueryVhod.next; //сдвуигаем указатель
           end;
  ShowMessage('Неверно введен логин или пароль. Повторите попытку.');
end;

end.

