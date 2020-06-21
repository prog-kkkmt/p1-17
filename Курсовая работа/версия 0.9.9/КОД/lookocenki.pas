unit LookOcenki;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, StdCtrls;

type

  { TLookinOc }

  TLookinOc = class(TForm)
    ComboBox1: TComboBox;  //комбобокс используемый для сорнтировки
    Label1: TLabel;       //заголовок
    lookoc: TDBGrid;     //грид для вывода оценок
    procedure ComboBox1Change(Sender: TObject);  //функция сортироввки происходящая при выборе элемента из комбобокса
    procedure FormCreate(Sender: TObject);       //заполнение комбобокса соответсвующими элементами при создании формы
  private

  public

  end;

var
  LookinOc: TLookinOc;

implementation
            uses maindata ;
{$R *.lfm}

{ TLookinOc }

procedure TLookinOc.FormCreate(Sender: TObject);
begin
  begin
      maindata.MainDatas.Qdat.close;      //перезапуск запросов для обновления
      maindata.MainDatas.Qdat.open;
      maindata.MainDatas.QueryOc.close;
      maindata.MainDatas.QueryOc.open;
      while not(maindata.MainDatas.Qdat.eof) do   //проходим по таблице с датами
           begin
             ComboBox1.Items.Add(maindata.MainDatas.Qdat.FieldByName('datas').AsString);  //добавляем в комбобокс соответсвующиее значение из запроса
             maindata.MainDatas.Qdat.next;    //сдвиг указателя
           end;
end;
end;

procedure TLookinOc.ComboBox1Change(Sender: TObject);
begin
           maindata.MainDatas.QueryOc.close;   //закрываем запрос
           if not (ComboBox1.Text = 'Все') then      //проверка на включение всях
               maindata.MainDatas.QueryOc.SQL[3]:=' and ocenki.datas='+ chr(39) +ComboBox1.Text+ chr(39) //добавляем соответсвующий кусок кода
            else
                 maindata.MainDatas.QueryOc.SQL[3]:='';      //иначе удаляем
              maindata.MainDatas.QueryOc.open;       //открываем запрос
end;
end.

