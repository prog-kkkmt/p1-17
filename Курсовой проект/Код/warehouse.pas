unit warehouse;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus,
  DBGrids;

type

  { TFWarehouse }

  TFWarehouse = class(TForm)
    BackFromWarehouse: TButton;
    DBGrid1: TDBGrid;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    procedure BackFromWarehouseClick(Sender: TObject);
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

end.

