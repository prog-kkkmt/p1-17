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
  IniF:TINIFile; //класс для работы с INI-файлами
  DBname: String;

implementation
uses
  openform;
{$R *.lfm}

{ TDataModule1 }

procedure TDataModule1.DataModuleCreate(Sender: TObject);  //открытие таблиц
begin
    IF(FileExists('db.ini'))then   //проверка ini файла
    begin
      IniF := TINIFile.Create('db.ini');
      DBname := IniF.ReadString('db','dbname', ''); //считывание пути файла

      If (FileExists(DBname))  then  //проверка на существование БД
      begin
          ibdb.DatabaseName:=DBname;
          ibdb.Connected:=True;
          ibdb.AllowStreamedConnected:=True;
          IBEVENTS.Active:=True;
          IBPHONEBOOK.Active:=True;

      end
      Else
      begin
          Open_Form.Label6.Caption:='Неверный путь к БД! База данных не подключена.';
          Open_Form.Label6.Visible:=True;
          Open_Form.Open.Enabled:=False;
      end;


    end
    Else
    begin
       Open_Form.Label6.Caption:='db.ini отсутствует! База данных не подключена.';
       Open_Form.Label6.Visible:=True;
       Open_Form.Open.Enabled:=False;
    end;
end;

end.
