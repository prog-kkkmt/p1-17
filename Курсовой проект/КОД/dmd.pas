unit dmd;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, IBDatabase, IBTable, IBCustomDataSet, IBQuery, db, INIFiles;

type

  { TDataModule2 }

  TDataModule2 = class(TDataModule)    // Класс "Модуль данных"
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
  IniF : TINIFile;
  DBname : string;

implementation

{$R *.lfm}

{ TDataModule2 }

procedure TDataModule2.DataModuleCreate(Sender: TObject);    // Запуск транзакции и открытие таблиц
begin
     IF(FileExists('DataBase.ini'))then // Проверка ini-файла
     begin
          IniF := TINIFile.Create('DataBase.ini');
          DBname := IniF.ReadString('db', 'dbname', ''); // Считывание путя файла

          ibdb.DatabaseName := DBname;
          ibdb.Connected := True;
          ibdb.AllowStreamedConnected := True;
          ibtr.StartTransaction;   // Запуск транзакции
          ibWarehouse.Open;        // Открытие таблицы Warehouse
          ibqWarehouse.Open;       // Открытие таблицы Warehouse для запроса поиска
          ibProdmenu.Open;         // Открытие таблицы Prodmenu
          ibqProdmenu.Open;        // Открытие таблицы Prodmenu для запроса поиска
          ibFinance.Open;          // Открытие таблицы Finance
          ibqFinance.Open;         // Открытие таблицы Finance для запроса поиска
     end;
end;

end.

