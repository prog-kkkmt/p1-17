unit prodmenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus,
  DBGrids, DBCtrls;

type

  { TFProdMenu }

  TFProdMenu = class(TForm)
    ButMenuBack: TButton;
    DBGrid1: TDBGrid;
    DBGrid2: TDBGrid;
    DBNavigator1: TDBNavigator;
    dbnProdMenu: TDBNavigator;
    Edit1: TEdit;
    Label1: TLabel;
    MainMenu1: TMainMenu;
    MenuItem4: TMenuItem;
    procedure ButMenuBackClick(Sender: TObject);
    procedure dbnProdMenuClick(Sender: TObject; Button: TDBNavButtonType);
    procedure Edit1Change(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  FProdMenu: TFProdMenu;

implementation
uses AppMenu, dmd;
{$R *.lfm}

{ TFProdMenu }

procedure TFProdMenu.ButMenuBackClick(Sender: TObject);
begin
  Close;
  AppMenu1.Show;
end;

procedure TFProdMenu.dbnProdMenuClick(Sender: TObject; Button: TDBNavButtonType
  );
begin

end;

procedure TFProdMenu.Edit1Change(Sender: TObject);  // Запрос к таблице ProdMenu
var buff, strSearch: string;
begin
     buff := '%' + FProdMenu.Edit1.Text + '%';
     strSearch := QuotedStr(buff);
     with dmd.DataModule2.ibqProdmenu do
     begin
       Close;
       SQL.Clear;
       SQL.Add('select * from PROD_MENU where FOOD_NAME like' + strSearch + ' or COOKING_TIME like' + strSearch + ' or PRICE like' + strSearch + ' order by FOOD_NAME');
       open;
     end;
end;

procedure TFProdMenu.FormCreate(Sender: TObject);
begin

end;

end.

