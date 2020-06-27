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
    MainMenu: TMainMenu;
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
//вызов формы справки о программе
begin
  FormProg.Show;
end;

procedure TFormOrdersShow.MenuItem4Click(Sender: TObject);
//сортировка таблицы по статусу заказа
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         //очищаем sql-запрос
         SQL.Add('select * from CLIENTS_AND_ORDERS order by STATUS_ORDER');
         //добавляем новый sql-запрос с сортировкой
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem5Click(Sender: TObject);
//сортировка таблицы по ID заказа
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         //очищаем sql-запрос
         SQL.Add('select * from CLIENTS_AND_ORDERS order by ID_ORDER');
         //добавляем новый sql-запрос с сортировкой
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem6Click(Sender: TObject);
//сортировка таблицы по дате приёма заказа
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         //очищаем sql-запрос
         SQL.Add('select * from CLIENTS_AND_ORDERS order by DATE_RECEIPT');
         //добавляем новый sql-запрос с сортировкой
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem7Click(Sender: TObject);
//сортировка таблицы по дате выдачи заказа
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         //очищаем sql-запрос
         SQL.Add('select * from CLIENTS_AND_ORDERS order by DATE_ISSUE');
         //добавляем новый sql-запрос с сортировкой
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem8Click(Sender: TObject);
//сортировка таблицы по поставщику комплектующих
begin
  with unitDM.DM.QueryOrders do
       begin
         Close;
         SQL.Clear;
         //очищаем sql-запрос
         SQL.Add('select * from CLIENTS_AND_ORDERS order by PROVIDER');
         //добавляем новый sql-запрос с сортировкой
         Open;
       end;
end;

procedure TFormOrdersShow.MenuItem1Click(Sender: TObject);
//вызов формы с деталями заявок
begin
  FormDetails.Show;
end;

procedure TFormOrdersShow.ButtonEditClick(Sender: TObject);
//вызов формы с возможностью редактирования таблицы
begin
  FormOrdersEdit.Show;
end;

end.

