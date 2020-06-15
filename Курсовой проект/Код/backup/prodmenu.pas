unit prodmenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TFProdMenu }

  TFProdMenu = class(TForm)
    ButMenuBack: TButton;
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

