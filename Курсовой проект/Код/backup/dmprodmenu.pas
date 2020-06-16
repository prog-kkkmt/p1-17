unit dmprodmenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBDatabase, IBTable, IBCustomDataSet;

type

  { TDataModule2 }

  TDataModule2 = class(TDataModule)
    dtsProdMenu: TDataSource;
    ibdb: TIBDatabase;
    ibProdMenuCOOKING_TIME: TIBStringField;
    ibProdMenuFOOD_NAME: TIBStringField;
    ibProdMenuPRICE: TIBIntegerField;
    ibt: TIBTransaction;
    ibProdMenu: TIBTable;
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
   ibt.StartTransaction;
   ibProdMenu.Open;
end;

end.

