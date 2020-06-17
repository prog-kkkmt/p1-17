unit dmd;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, IBDatabase, IBTable, IBCustomDataSet, IBQuery, db;

type

  { TDataModule2 }

  TDataModule2 = class(TDataModule)
    dtsWarehouseQ: TDataSource;
    dtsFinanceQ: TDataSource;
    dtsProdmenuQ: TDataSource;
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
    ibqFinanceCDATE: TIBStringField;
    ibqFinanceEXPENDITURE: TIBIntegerField;
    ibqFinanceINCOME: TIBIntegerField;
    ibqProdmenuCOOKING_TIME: TIBStringField;
    ibqProdmenuFOOD_NAME: TIBStringField;
    ibqProdmenuPRICE: TIBIntegerField;
    ibqWarehouse: TIBQuery;
    ibqFinance: TIBQuery;
    ibqProdmenu: TIBQuery;
    ibqWarehousePROD_NAME: TIBStringField;
    ibqWarehousePROD_QUAN: TIBIntegerField;
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

procedure TDataModule2.DataModuleCreate(Sender: TObject);    // Запуск транзакции и открытие таблиц
begin
     ibtr.StartTransaction;
     ibWarehouse.Open;
     ibqWarehouse.Open;
     ibProdmenu.Open;
     ibqProdmenu.Open;
     ibFinance.Open;
     ibqFinance.Open;
end;

end.

