unit DBC;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBDatabase, IBTable, IBCustomDataSet, INIFiles;

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
    procedure DataModuleCreate(Sender: TObject);
  private

  public

  end;

var
  DataModule1: TDataModule1;
  IniF:TINIFile;
  DBname: String;

implementation

{$R *.lfm}

{ TDataModule1 }

procedure TDataModule1.DataModuleCreate(Sender: TObject);
begin
    IF(FileExists('db.ini'))then
    begin
      IniF := TINIFile.Create('db.ini');
      DBname := IniF.ReadString('db','dbname', '');


      ibdb.DatabaseName:=DBname;
      ibdb.Connected:=True;
      ibdb.AllowStreamedConnected:=True;
      IBEVENTS.Active:=True;
      IBPHONEBOOK.Active:=True;

    end;
end;

end.
