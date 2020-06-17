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
    DBGrid2: TDBGrid;
    DBNavigator1: TDBNavigator;
    dbnFinance: TDBNavigator;
    Edit1: TEdit;
    Label1: TLabel;
    MainMenu1: TMainMenu;
    MenuItem4: TMenuItem;
    procedure BackFromFinanceClick(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
  private

  public

  end;

var
  FormFinance: TFormFinance;

implementation
 uses AppMenu, dmd;
{$R *.lfm}

{ TFormFinance }

procedure TFormFinance.BackFromFinanceClick(Sender: TObject);
begin
  Close;
  AppMenu1.Show;
end;

procedure TFormFinance.Edit1Change(Sender: TObject);  // Запрос к таблице Finance
  var buff, strSearch: string;
begin
     buff := '%' + FormFinance.Edit1.Text + '%';
     strSearch := QuotedStr(buff);
     with dmd.DataModule2.ibqFinance do
     begin
       Close;
       SQL.Clear;
       SQL.Add('select * from FINANCE where CDATE like' + strSearch + ' or INCOME like' + strSearch + ' or EXPENDITURE like'+ strSearch + ' order by CDATE');
       open;
     end;
end;

end.

