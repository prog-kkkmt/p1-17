unit DBC;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBDatabase, IBTable, IBCustomDataSet;

type

  { TDataModule1 }

  TDataModule1 = class(TDataModule)     //класс модуля подключения БД
    IBPHONEBOOKADDRESS: TIBStringField;
    IBPHONEBOOKID: TIBIntegerField;
    IBPHONEBOOKNAME: TIBStringField;
    IBPHONEBOOKNOTE: TIBStringField;
    IBPHONEBOOKPHONE: TIBStringField;
    PhoneBookS: TDataSource;
    EventsS: TDataSource;
    ibdb: TIBDatabase;
    IBEVENTS: TIBTable;
    IBEVENTSDATA: TDateField;
    IBEVENTSDBEVENT: TIBStringField;
    IBEVENTSID: TIBIntegerField;
    IBPHONEBOOK: TIBTable;
    ibtr: TIBTransaction;
  private

  public

  end;

var
  DataModule1: TDataModule1;

implementation

{$R *.lfm}

{ TDataModule1 }

end.
