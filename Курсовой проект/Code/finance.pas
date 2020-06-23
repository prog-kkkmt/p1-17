unit finance;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus,
  DBGrids, DBCtrls, IBTable;

type

  { TFormFinance }

  TFormFinance = class(TForm)         // Клас формы "Финансы"
    BackFromFinance: TButton;         // кнопка "Назад"
    DBGrid1: TDBGrid;                 // компонент для отображения данных таблицы БД
    DBGrid2: TDBGrid;                 // компонент для отображения данных таблицы БД
    dbnFinance: TDBNavigator;         // компонент для работы с данными таблицы БД
    Edit1: TEdit;                     // поле ввода
    Label1: TLabel;                   // надпись "Поиск"
    MainMenu1: TMainMenu;             // невизуальный компонент меню
    MenuItem4: TMenuItem;            // пункт меню
    procedure BackFromFinanceClick(Sender: TObject);    // процедура события кнопки "Назад"
    procedure Edit1Change(Sender: TObject);         // обработчик события Edit
    procedure MenuItem4Click(Sender: TObject);
  private

  public

  end;

var
  FormFinance: TFormFinance;

implementation
 uses AppMenu, dmd, AboutProgramm;
{$R *.lfm}

{ TFormFinance }

procedure TFormFinance.BackFromFinanceClick(Sender: TObject); // Процедура события кнопки "Назад"
begin
  Close;
  AppMenu1.Show;
end;

procedure TFormFinance.Edit1Change(Sender: TObject);  // Процедура запроса поиска к таблице Finance
  var buff, strSearch: string;
begin
     buff := '%' + FormFinance.Edit1.Text + '%';     // Строка принимающая значение, введенное пользователем
     strSearch := QuotedStr(buff);       // Подготовленная строка для запроса поиска
     with dmd.DataModule2.ibqFinance do
     begin
       Close;
       SQL.Clear; //Очищение предыдущего запроса
       SQL.Add('select * from FINANCE where CDATE like' + strSearch + ' or INCOME like' + strSearch + ' or EXPENDITURE like'+ strSearch + ' order by CDATE'); // Запрос поиска
       open;
     end;
end;

procedure TFormFinance.MenuItem4Click(Sender: TObject);   // Процедура события кнопка меню "О программе"
begin
  FAboutProgramm.Show;
end;

end.

