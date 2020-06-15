unit dmFinance;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBDatabase, IBTable, IBCustomDataSet;

type

  { TDataMFinance }

  TDataMFinance = class(TDataModule)
    dtsFinance: TDataSource;
    ibdb: TIBDatabase;
    ibFinanceDATE: TDateField;
    ibFinanceEXPENDITURE: TIBIntegerField;
    ibFinanceINCOME: TIBIntegerField;
    ibFinance: TIBTable;
    ibtr: TIBTransaction;
    procedure DataModuleCreate(Sender: TObject);
    procedure dtsFinanceDataChange(Sender: TObject; Field: TField);
  private

  public

  end;

var
  DataMFinance: TDataMFinance;

implementation

{$R *.lfm}

{ TDataMFinance }

procedure TDataMFinance.dtsFinanceDataChange(Sender: TObject; Field: TField);
begin

end;

procedure TDataMFinance.DataModuleCreate(Sender: TObject);
begin
     ibtr.StartTransaction;
     ibFinance.Open;
end;

end.

