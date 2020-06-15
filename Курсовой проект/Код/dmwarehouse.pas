unit dmwarehouse;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBTable, IBDatabase, IBCustomDataSet;

type

  { TDataModule1 }

  TDataModule1 = class(TDataModule)
    dtsWarehouse: TDataSource;
    ibdb: TIBDatabase;
    ibWarehouse: TIBTable;
    ibtr: TIBTransaction;
    ibWarehousePROD_NAME: TIBStringField;
    ibWarehousePROD_QUANTITY: TIBIntegerField;
    procedure DataModuleCreate(Sender: TObject);
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
end;

end.

