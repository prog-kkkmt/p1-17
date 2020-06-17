unit warehouse;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus,
  DBGrids, DBCtrls;

type

  { TFWarehouse }

  TFWarehouse = class(TForm)
    BackFromWarehouse: TButton;
    DBGrid1: TDBGrid;
    DBGrid2: TDBGrid;
    DBNavigator1: TDBNavigator;
    dbnWarehouse: TDBNavigator;
    Edit1: TEdit;
    Label1: TLabel;
    MainMenu1: TMainMenu;
    MenuItem4: TMenuItem;
    procedure BackFromWarehouseClick(Sender: TObject);
    procedure DBNavigator1Click(Sender: TObject; Button: TDBNavButtonType);
    procedure dbnWarehouseClick(Sender: TObject; Button: TDBNavButtonType);
    procedure Edit1Change(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  FWarehouse: TFWarehouse;

implementation
uses AppMenu, dmd;
{$R *.lfm}

{ TFWarehouse }

procedure TFWarehouse.BackFromWarehouseClick(Sender: TObject);
begin
     Close;
     AppMenu1.Show;
end;

procedure TFWarehouse.DBNavigator1Click(Sender: TObject;
  Button: TDBNavButtonType);
begin

end;

procedure TFWarehouse.dbnWarehouseClick(Sender: TObject;
  Button: TDBNavButtonType);
begin

end;

procedure TFWarehouse.Edit1Change(Sender: TObject); // Запрос к таблице Warehouse
var buff, strSearch: string;
begin
     buff := '%' + FWarehouse.Edit1.Text + '%';
     strSearch := QuotedStr(buff);
     with dmd.DataModule2.ibqWarehouse do
     begin
       Close;
       SQL.Clear;
       SQL.Add('select * from WAREHOUSE where PROD_NAME like' + strSearch + ' or PROD_QUAN like' + strSearch + ' order by PROD_NAME');
       open;
     end;
end;

procedure TFWarehouse.FormCreate(Sender: TObject);
begin
  dmd.DataModule2.ibtr.StartTransaction;
end;

end.

