unit finance;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus,
  DBGrids, DBCtrls, IBTable;

type

  { TFormFinance }

  TFormFinance = class(TForm)
    BackFromFinance: TButton;
    DBGrid1: TDBGrid;
    dbnFinance: TDBNavigator;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    procedure BackFromFinanceClick(Sender: TObject);
  private

  public

  end;

var
  FormFinance: TFormFinance;

implementation
 uses AppMenu;
{$R *.lfm}

{ TFormFinance }

procedure TFormFinance.BackFromFinanceClick(Sender: TObject);
begin
  Close;
  AppMenu1.Show;
end;

end.

