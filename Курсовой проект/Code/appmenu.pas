unit AppMenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus;

type

  { TAppMenu1 }

  TAppMenu1 = class(TForm)             //Класс главной формы "ФастФуд"
    ButProdMenu: TButton;              // Кнопка "Меню заведения"
    ButWarehouse: TButton;             // Кнопка "Склад"
    ButFunance: TButton;               // Кнопка "Финансы"
    MainMenu1: TMainMenu;              // Невизуалный компонент меню
    MenuItem1: TMenuItem;              // Пункт меню "О программе"
    procedure ButFunanceClick(Sender: TObject);      //  Процедура события кнопки "Финансы"
    procedure ButProdMenuClick(Sender: TObject);     //  Процедура события кнопки "Меню заведения"
    procedure ButWarehouseClick(Sender: TObject);    //  Процедура события кнопки "Склад"
    procedure MenuItem1Click(Sender: TObject);       // Процедура события пункта меню "О программе"
  private

  public

  end;

var
  AppMenu1: TAppMenu1;

implementation

uses finance, prodmenu, warehouse, AboutProgramm;
{$R *.lfm}

{ TAppMenu1 }

procedure TAppMenu1.ButProdMenuClick(Sender: TObject);  //Процедура события кнопки "Меню заведения"
begin
     AppMenu1.Hide;
     FProdMenu.Show;
end;

procedure TAppMenu1.ButFunanceClick(Sender: TObject);  // Процедура события кнопки "Финансы"
begin
     AppMenu1.Hide;
     FormFinance.Show;
end;

procedure TAppMenu1.ButWarehouseClick(Sender: TObject);  // Процедура события кнопки "Склад"
begin
     AppMenu1.Hide;
     FWarehouse.Show;
end;

procedure TAppMenu1.MenuItem1Click(Sender: TObject);  // Процедура события "О программе"
begin
  FAboutProgramm.Show;
end;


end.

