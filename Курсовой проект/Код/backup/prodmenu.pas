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
    dbnProdMenu: TDBNavigator;
    MainMenu1: TMainMenu;
    MenuItem4: TMenuItem;
    procedure ButMenuBackClick(Sender: TObject);
    procedure dbnProdMenuClick(Sender: TObject; Button: TDBNavButtonType);
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  FProdMenu: TFProdMenu;

implementation
uses AppMenu;
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

procedure TFProdMenu.FormCreate(Sender: TObject);
begin

end;

end.

