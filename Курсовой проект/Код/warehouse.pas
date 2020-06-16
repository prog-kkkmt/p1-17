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
    dbnWarehouse: TDBNavigator;
    MainMenu1: TMainMenu;
    MenuItem4: TMenuItem;
    procedure BackFromWarehouseClick(Sender: TObject);
    procedure dbnWarehouseClick(Sender: TObject; Button: TDBNavButtonType);
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  FWarehouse: TFWarehouse;

implementation
uses AppMenu;
{$R *.lfm}

{ TFWarehouse }

procedure TFWarehouse.BackFromWarehouseClick(Sender: TObject);
begin
     Close;
     AppMenu1.Show;
end;

procedure TFWarehouse.dbnWarehouseClick(Sender: TObject;
  Button: TDBNavButtonType);
begin

end;

procedure TFWarehouse.FormCreate(Sender: TObject);
begin

end;

end.

