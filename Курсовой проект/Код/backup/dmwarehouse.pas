unit dmWarehouse;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBTable, IBDatabase, IBCustomDataSet, IBQuery;

type

  { TDataModule1 }

  TDataModule1 = class(TDataModule)
    dsWarehouse: TDataSource;
    dsProdmenu: TDataSource;
    dsFinance: TDataSource;
    ibdb: TIBDatabase;
    ibFinanceCDATE: TIBStringField;
    ibFinanceEXPENDITURE: TIBIntegerField;
    ibFinanceINCOME: TIBIntegerField;
    ibProdmenuCOOKING_TIME: TIBStringField;
    ibProdmenuFOOD_NAME: TIBStringField;
    ibProdmenuPRICE: TIBIntegerField;
    ibWarehouse: TIBTable;
    ibProdmenu: TIBTable;
    ibFinance: TIBTable;
    ibtr: TIBTransaction;
    ibWarehousePROD_NAME: TIBStringField;
    ibWarehousePROD_QUANTITY: TIBIntegerField;
    procedure DataModuleCreate(Sender: TObject);
    procedure dsWarehouseDataChange(Sender: TObject; Field: TField);
  private

  public

  end;

var
  DataModule1: TDataModule1;

implementation

{$R *.lfm}

{ TDataModule1 }

procedure TDataModule1.DataModuleCreate(Sender: TObject);
begin
     ibtr.StartTransaction;
     ibWarehouse.Open;
     ibProdmenu.Open;
     ibFinance.Open;
end;

procedure TDataModule1.dsWarehouseDataChange(Sender: TObject; Field: TField);
begin

end;

end.

