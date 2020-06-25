unit unitOrders;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, ComCtrls,
  DBCtrls, Menus, StdCtrls, unitProg, unitDetails, unitOrdersEdit, unitDM;

type

  { TFormOrdersShow }

  TFormOrdersShow = class(TForm)
    ButtonEdit: TButton;
    DBGrid1: TDBGrid;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    MenuItem5: TMenuItem;
    MenuItem6: TMenuItem;
    MenuItem7: TMenuItem;
    MenuItem8: TMenuItem;
    procedure ButtonEditClick(Sender: TObject);
    procedure MenuItem1Click(Sender: TObject);
    procedure MenuItem3Click(Sender: TObject);
    procedure MenuItem4Click(Sender: TObject);
    procedure MenuItem5Click(Sender: TObject);
    procedure MenuItem6Click(Sender: TObject);
    procedure MenuItem7Click(Sender: TObject);
    procedure MenuItem8Click(Sender: TObject);
  private

  public

  end;

var
  FormOrdersShow: TFormOrdersShow;

implementation

{$R *.lfm}

{ TFormOrdersShow }

procedure TFormOrdersShow.MenuItem3Click(Sender: TObject);
begin
  FormProg.Show;
end;

procedure TFormOrdersShow.MenuItem4Click(Sender: TObject);
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         SQL.Add('select * from CLIENTS_AND_ORDERS order by STATUS_ORDER');
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem5Click(Sender: TObject);
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         SQL.Add('select * from CLIENTS_AND_ORDERS order by ID_ORDER');
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem6Click(Sender: TObject);
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         SQL.Add('select * from CLIENTS_AND_ORDERS order by DATE_RECEIPT');
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem7Click(Sender: TObject);
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         SQL.Add('select * from CLIENTS_AND_ORDERS order by DATE_ISSUE');
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem8Click(Sender: TObject);
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         SQL.Add('select * from CLIENTS_AND_ORDERS order by PROVIDER');
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem1Click(Sender: TObject);
begin
  FormDetails.Show;
end;

procedure TFormOrdersShow.ButtonEditClick(Sender: TObject);
begin
  FormOrdersEdit.Show;
end;

end.

