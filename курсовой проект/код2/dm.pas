unit dm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, db, IBDatabase, IBTable, IBCustomDataSet, IBQuery,
  StdCtrls, Dialogs;

type

  { Tdmb }

  Tdmb = class(TDataModule)
    //ресурсы запросов
    dsqOutgoCat: TDataSource;
    dsqIncomeCat: TDataSource;
    dsqOutgoSum: TDataSource;
    dsqIncomeSum: TDataSource;
    dsqOutgo: TDataSource;
    dsqIncome: TDataSource;
    dsOutgo: TDataSource;
    dsIncome: TDataSource;

    ibdb: TIBDatabase;  //база данных
    ibtr: TIBTransaction; //транзакция

    ibIncome: TIBTable; //таблица доходов бд

    //поля таблицы доходов
    ibIncomeCATEGORY: TIBStringField;
    ibIncomeDATA: TDateField;
    ibIncomeID: TIBIntegerField;
    ibIncomeMEMBER: TIBStringField;
    ibIncomePROFIT: TIBBCDField;

    ibOutgo: TIBTable;  //таблица расходов

    //поля таблицы расходов
    ibOutgoCATEGORY: TIBStringField;
    ibOutgoCOST: TIBBCDField;
    ibOutgoDATA: TDateField;
    ibOutgoID: TIBIntegerField;
    ibOutgoMEMBER: TIBStringField;

    ibqIncome: TIBQuery; //запрос к таблице Доходов

    //поля запроса
    ibqIncomeCATEGORY: TIBStringField;
    ibqIncomeDATA: TDateField;
    ibqIncomeMEMBER: TIBStringField;
    ibqIncomePROFIT: TIBBCDField;

    ibqIncomeSum: TIBQuery; //запрос на сумму доходов
    ibqIncomeSumD: TIBBCDField; //поле запроса

    ibq: TIBQuery; //запрос для комбобокса

    ibqOutgo: TIBQuery; //запрос к таблице Расходов

    //поля запроса
    ibqOutgoCATEGORY: TIBStringField;
    ibqOutgoCOST: TIBBCDField;
    ibqOutgoDATA: TDateField;
    ibqOutgoMEMBER: TIBStringField;

    ibqOutgoSum: TIBQuery; //запрос на сумму расходов
    ibqOutgoSumD: TIBBCDField; //поле запроса

    ibqIncomeCat: TIBQuery; //запрос по категориям доходов

    //поля запроса
    ibqIncomeCatCATEGORY: TIBStringField;
    ibqIncomeCatTOTAL: TIBBCDField;

    ibqOutgoCat: TIBQuery;  //запрос по категориям расходов

    //поля запроса
    ibqOutgoCatCATEGORY: TIBStringField;
    ibqOutgoCatTOTAL: TIBBCDField;
    OpenDialog1: TOpenDialog;

    procedure DataModuleCreate(Sender: TObject); //дата-модуль

  private

  public
  end;

var
  dmb: Tdmb;

implementation
uses budget ;

{$R *.lfm}

{ Tdmb }

procedure Tdmb.DataModuleCreate(Sender: TObject);   //дата-модуль
begin
   if(opendialog1.Execute) then
   ibdb.DatabaseName := ExtractFileDir(OpenDialog1.FileName)+'\BQ.FDB'; //выбор пути бд
   ibtr.StartTransaction; //транзакция
   ibIncome.Open; // таблица доходов
   ibOutgo.Open;  // таблица расходов
   ibqIncome.open;  // запрос к таблице доходов для комбобокса
   ibqOutgo.open; // запрос к таблице расходов для комбобокса
   ibqOutgoSum.Open;  // запрос для общей суммы расходов
   ibqIncomeSum.Open;  // запрос для общей суммы расходов
   ibqIncomeCat.Open; //  запрос для суммы доходов по каждой категории дохода
   ibqOutgoCat.Open; // запрос для суммы расходов по каждой категории расхода
end;


end.

