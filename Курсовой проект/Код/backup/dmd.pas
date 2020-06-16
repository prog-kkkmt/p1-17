unit dmd;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, IBDatabase, IBTable, IBCustomDataSet, db;

type

  { TDataModule2 }

  TDataModule2 = class(TDataModule)
    dtsWarehouse: TDataSource;
    dtsFinance: TDataSource;
    dtsProdMenu: TDataSource;
    ibdb: TIBDatabase;
    ibFinanceCDATE: TIBStringField;
    ibFinanceEXPENDITURE: TIBIntegerField;
    ibFinanceINCOME: TIBIntegerField;
    ibProdmenuCOOKING_TIME: TIBStringField;
    ibProdmenuFOOD_NAME: TIBStringField;
    ibProdmenuPRICE: TIBIntegerField;
    ibWarehouse: TIBTable;
    ibFinance: TIBTable;
    ibProdmenu: TIBTable;
    ibtr: TIBTransaction;
    ibWarehousePROD_NAME: TIBStringField;
    ibWarehousePROD_QUAN: TIBIntegerField;
    procedure DataModuleCreate(Sender: TObject);
  private

  public

  end;

var
  DataModule2: TDataModule2;

implementation

{$R *.lfm}

{ TDataModule2 }

procedure TDataModule2.DataModuleCreate(Sender: TObject);
begin
     ibtr.StartTransaction;
     ibWarehouse.Open;
     ibProdmenu.Open;
     ibFinance.Open;
end;

end.

