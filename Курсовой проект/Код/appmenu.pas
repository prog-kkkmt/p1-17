unit AppMenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus;

type

  { TAppMenu1 }

  TAppMenu1 = class(TForm)             //Класс главной формы "ФастФуд"
    ButProdMenu: TButton;
    ButWarehouse: TButton;
    ButFunance: TButton;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    procedure ButFunanceClick(Sender: TObject);
    procedure ButProdMenuClick(Sender: TObject);
    procedure ButWarehouseClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Label1Click(Sender: TObject);
    procedure MenuItem1Click(Sender: TObject);
  private

  public

  end;

var
  AppMenu1: TAppMenu1;

implementation

uses finance, prodmenu, warehouse, AboutProgramm;
{$R *.lfm}

{ TAppMenu1 }

procedure TAppMenu1.ButProdMenuClick(Sender: TObject);  // Кнопка "Меню заведения"
begin
     AppMenu1.Hide;
     FProdMenu.Show;
end;

procedure TAppMenu1.ButFunanceClick(Sender: TObject);  // Кнопка "Финансы"
begin
     AppMenu1.Hide;
     FormFinance.Show;
end;

procedure TAppMenu1.ButWarehouseClick(Sender: TObject);  // Кнопка "Склад"
begin
     AppMenu1.Hide;
     FWarehouse.Show;
end;

procedure TAppMenu1.FormCreate(Sender: TObject);
begin

end;


procedure TAppMenu1.Label1Click(Sender: TObject);
begin

end;

procedure TAppMenu1.MenuItem1Click(Sender: TObject);
begin
  FAboutProgramm.Show;
end;


end.

