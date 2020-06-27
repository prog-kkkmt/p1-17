unit unitDM;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBDatabase, IBQuery, IBTable, IBCustomDataSet, Dialogs;

type

  { TDM }

  TDM = class(TDataModule)
    DSOrderShow: TDataSource;
    DataSourceDetails: TDataSource;
    DSOrderEdit: TDataSource;
    DB: TIBDatabase;
    OpenDialog: TOpenDialog;
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
  if(OpenDialog.Execute) then
  //если выбран файл
     DB.DatabaseName:='127.0.0.1:' + ExtractFileDir(OpenDialog.FileName)+'\DB.FDB';
     //подставляет в базу данных выбранный путь
  DB.Connected:=True;
  //связываемся с бд
  Trans.StartTransaction;
  //активируем транзакцию
  tableOrders.Open;
  QueryOrders.Open;
  tableDetails.Open;
  //активируем таблицы
end;

end.

