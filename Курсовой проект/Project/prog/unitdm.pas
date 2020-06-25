unit unitDM;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBDatabase, IBQuery, IBTable, IBCustomDataSet;

type

  { TDM }

  TDM = class(TDataModule)
    DSOrderShow: TDataSource;
    DataSourceDetails: TDataSource;
    DSOrderEdit: TDataSource;
    DB: TIBDatabase;
    QueryOrders: TIBQuery;
    tableDetails: TIBTable;
    tableDetailsDETAILS: TIBStringField;
    tableDetailsFIO_CLIENT: TIBStringField;
    tableDetailsID_ORDER: TIBIntegerField;
    tableOrders: TIBTable;
    QueryVhod: TIBQuery;
    tableOrdersDATE_ISSUE: TDateField;
    tableOrdersDATE_RECEIPT: TDateField;
    tableOrdersEXPENSES: TIBStringField;
    tableOrdersFIO_CLIENT: TIBStringField;
    tableOrdersID_ORDER: TIBIntegerField;
    tableOrdersMASTER: TIBStringField;
    tableOrdersPHONE_CLIENT: TIBStringField;
    tableOrdersPROVIDER: TIBStringField;
    tableOrdersREQUEST: TIBStringField;
    tableOrdersSTATUS_ORDER: TIBStringField;
    tableOrdersTOTAL_PAYABLE: TIBStringField;
    Trans: TIBTransaction;
    procedure DataModuleCreate(Sender: TObject);
  private

  public

  end;

var
  DM: TDM;

implementation

{$R *.lfm}

{ TDM }

procedure TDM.DataModuleCreate(Sender: TObject);
begin
  Trans.StartTransaction;
  tableOrders.Open;
  QueryOrders.Open;
  tableDetails.Open;
end;

end.

