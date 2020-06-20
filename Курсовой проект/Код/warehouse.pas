unit warehouse;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus,
  DBGrids, DBCtrls;

type

  { TFWarehouse }

  TFWarehouse = class(TForm)                  // Класс формы "Склад"
    BackFromWarehouse: TButton;         // кнопка "Назад"
    DBGrid1: TDBGrid;                   // компонент для отображения данных таблицы БД
    DBGrid2: TDBGrid;                   // компонент для отображения данных таблицы БД
    dbnWarehouse: TDBNavigator;         // компонент для работы с данными таблицы БД
    Edit1: TEdit;                       // поле ввода
    Label1: TLabel;                     // надпись
    MainMenu1: TMainMenu;               // невизиальный компонент меню
    MenuItem4: TMenuItem;               // пункт меню
    procedure BackFromWarehouseClick(Sender: TObject);  // процедура события кнопки "Назад"
    procedure dbnWarehouseClick(Sender: TObject; Button: TDBNavButtonType);
    procedure Edit1Change(Sender: TObject);    // обработчик события Edit
    procedure FormCreate(Sender: TObject);    // процедура создания формы
    procedure MenuItem4Click(Sender: TObject);
  private

  public

  end;

var
  FWarehouse: TFWarehouse;

implementation
uses AppMenu, dmd, AboutProgramm;
{$R *.lfm}

{ TFWarehouse }

procedure TFWarehouse.BackFromWarehouseClick(Sender: TObject);  // Процедура события кнопки "Назад"
begin
     Close;
     AppMenu1.Show;
end;

procedure TFWarehouse.dbnWarehouseClick(Sender: TObject;
  Button: TDBNavButtonType);
begin

end;

procedure TFWarehouse.Edit1Change(Sender: TObject); // Процедура запроса поиска к таблице Warehouse
var buff, strSearch: string;
begin
     buff := '%' + FWarehouse.Edit1.Text + '%';  // Строка принимающая значение, введенное пользователем
     strSearch := QuotedStr(buff); // Подготовленная строка для запроса поиска
     with dmd.DataModule2.ibqWarehouse do
     begin
       Close;
       SQL.Clear; // Очищение предыдущего запроса
       SQL.Add('select * from WAREHOUSE where PROD_NAME like' + strSearch + ' or PROD_QUAN like' + strSearch + ' order by PROD_NAME');  // Запрос поиска
       open;
     end;
end;

procedure TFWarehouse.FormCreate(Sender: TObject);
begin

end;

procedure TFWarehouse.MenuItem4Click(Sender: TObject);    // Процедура события кнопка меню "О программе"
begin
  FAboutProgramm.Show;
end;

end.

