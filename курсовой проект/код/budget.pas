unit budget;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, DBGrids,
  ComCtrls,  Types;

type

  { Tumain3 }

  Tumain3 = class(TForm)
    cmb1: TComboBox; //комбобокс для категорий доходов
    cmb2: TComboBox; //комбобокс для категорий расходов
    DBGrid1: TDBGrid; //компонент отображения результата запроса фильтрации доходов по категориям
    DBGrid2: TDBGrid; //компонент отображения результата запроса фильтрации расходов по категориям
    DBGrid3: TDBGrid; //компонент отображения результата запроса суммы доходов по категориям
    DBGrid4: TDBGrid; //компонент отображения результата запроса суммы расходов по категориям
    Label1: TLabel;
    Label2: TLabel;
    IncomeSum: TLabel; //отображение результата запроса суммы доходов
    Label3: TLabel;
    Label4: TLabel;
    outgoSum: TLabel; //отображение результата запроса суммы расходов
    PageControl1: TPageControl; //окно с вкладками
    TabSheet1: TTabSheet; //вкладка Доходы
    TabSheet2: TTabSheet; //вкладка Расходы
    procedure cmb1Change(Sender: TObject);  //вывод доходов по категориям
    procedure cmb2Change(Sender: TObject); //вывод расходов по категориям
    procedure FormCreate(Sender: TObject); //обработчик события OnCreate
  private
  public
     procedure loadtable(tablename : string; cmb : TCombobox); //создание выпадающего списка в комбобоксе
  end;

var
  umain3: Tumain3;

implementation
uses dm;

{$R *.lfm}

{ Tumain3 }

procedure Tumain3.FormCreate(Sender: TObject);
begin
  loadtable('income', cmb1); //комбобокс для таблицы доходов
  loadtable('outgo', cmb2);  //комбобокс для таблицы расходов
  outgoSum.Caption := 'Итого расходов : ' + IntToStr(dm.dmb.ibqOutgoSum.FieldValues['d']); // выводим в текст label значение запроса суммы расходов
  IncomeSum.Caption := 'Итого доходов : ' + IntToStr(dm.dmb.ibqIncomeSum.FieldValues['d']);// выводим в текст label значение запроса суммы доходов
end;

procedure Tumain3.cmb1Change(Sender: TObject); //вывод доходов по категориям
var
  ind:string;
begin
  dm.dmb.ibqIncome.close;
  if cmb1.ItemIndex <> 0 then  //если выбран пункт "всего"
  begin
    ind := cmb1.text;
    dm.dmb.ibqIncome.sql[1] := 'where category='+chr(39)+ind+chr(39);
  end
  else dm.dmb.ibqIncome.SQL[1]:=''; //иначе оставляем запрос как есть и выводим все категории
  dm.dmb.ibqIncome.open;
end;

procedure Tumain3.cmb2Change(Sender: TObject); //вывод расходов по категориям
var
  ind:string;
begin
  dm.dmb.ibqOutgo.close;
  if cmb2.ItemIndex <> 0 then  //если выбран пункт "всего"
  begin
    ind := cmb2.text;
    dm.dmb.ibqOutgo.sql[1] := 'where category='+chr(39)+ind+chr(39);
  end
  else dm.dmb.ibqOutgo.SQL[1]:=''; //иначе оставляем запрос как есть и выводим все категории
  dm.dmb.ibqOutgo.open;
end;

procedure Tumain3.loadtable(tablename : string; cmb : TCombobox); // создаем комбобокс с выпадающим списком
begin
   dm.dmb.ibq.close(); //закрыть запрос
   if not (dm.dmb.ibq.Transaction.Active) then dm.dmb.ibq.Transaction.StartTransaction; //запустить транзакцию , если неактивна
   dm.dmb.ibq.SQL.Text := 'select distinct category from ' + tablename; //запрос на список неповторяющихся категорий
   dm.dmb.ibq.open; //открыть запрос
   while not (dm.dmb.ibq.eof) do  //пока не конец запроса
         begin
           cmb.items.add(dm.dmb.ibq.FieldByName('CATEGORY').AsString); //берем навание поля и добавляем в свойство items
           dm.dmb.ibq.next; //сдвиг
         end;
end;
end.

