unit prodmenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus,
  DBGrids, DBCtrls;

type

  { TFProdMenu }

  TFProdMenu = class(TForm)             // Класс формы "Меню предприятия"
    ButMenuBack: TButton;               // кнопка "Назад"
    DBGrid1: TDBGrid;                  // компонент для отображения данных таблицы БД
    DBGrid2: TDBGrid;                  // компонент для отображения данных таблицы БД
    dbnProdMenu: TDBNavigator;         // компонент для работы с данными таблицы БД
    Edit1: TEdit;                     // поле ввода
    Label1: TLabel;                   // надпись "Поиск"
    MainMenu1: TMainMenu;             // невизуальный компонент меню
    MenuItem4: TMenuItem;            // пункт меню
    procedure ButMenuBackClick(Sender: TObject);   // процедура события кнопки "Назад"
    procedure Edit1Change(Sender: TObject);      // обработчик события Edit
    procedure MenuItem4Click(Sender: TObject);
  private

  public

  end;

var
  FProdMenu: TFProdMenu;

implementation
uses AppMenu, dmd, AboutProgramm;
{$R *.lfm}

{ TFProdMenu }

procedure TFProdMenu.ButMenuBackClick(Sender: TObject); // Процедура события кнопки "Назад"
begin
  Close;
  AppMenu1.Show;
end;


procedure TFProdMenu.Edit1Change(Sender: TObject);  // Процедура запроса поиска к таблице ProdMenu
var buff, strSearch: string;
begin
     buff := '%' + FProdMenu.Edit1.Text + '%';   // Строка принимающая значение, введенное пользователем
     strSearch := QuotedStr(buff);    // Подготовленная строка для запроса поиска
     with dmd.DataModule2.ibqProdmenu do
     begin
       Close;
       SQL.Clear; //Очищение предыдущего запроса
       SQL.Add('select * from PROD_MENU where FOOD_NAME like' + strSearch + ' or COOKING_TIME like' + strSearch + ' or PRICE like' + strSearch + ' order by FOOD_NAME');  // Запрос поиска
       open;
     end;
end;

procedure TFProdMenu.MenuItem4Click(Sender: TObject);     // Процедура события кнопка меню "О программе"
begin
  FAboutProgramm.Show;
end;

end.

