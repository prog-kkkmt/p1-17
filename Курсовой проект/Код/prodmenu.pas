unit prodmenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus;

type

  { TFProdMenu }

  TFProdMenu = class(TForm)
    ButMenuBack: TButton;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    procedure ButMenuBackClick(Sender: TObject);
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

end.

