unit MainMenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus, prodmenu, finance, warehouse;

type

  { TAppMenu }

  TAppMenu = class(TForm)
    MenuComp: TButton;
    ButFinance: TButton;
    ButWarehouse: TButton;
    Label1: TLabel;
    procedure ButFinanceClick(Sender: TObject);
    procedure ButWarehouseClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Label1Click(Sender: TObject);
    procedure MenuCompClick(Sender: TObject);
  private

  public

  end;

var
  AppMenu: TAppMenu;

implementation

{$R *.lfm}

{ TAppMenu }

procedure TAppMenu.Label1Click(Sender: TObject);
begin

end;

procedure TAppMenu.FormCreate(Sender: TObject);
begin

end;

procedure TAppMenu.ButFinanceClick(Sender: TObject);
begin
     Form1.Show;
     AppMenu.Hide;
end;

procedure TAppMenu.ButWarehouseClick(Sender: TObject);
begin
     Form3.Show;
     AppMenu.Hide;
end;

procedure TAppMenu.MenuCompClick(Sender: TObject);
begin
     Form2.Show;
     AppMenu.Hide;
end;

end.

