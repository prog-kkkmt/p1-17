unit LokAllStudents;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, StdCtrls;

type

  { TLookinst }

  TLookinst = class(TForm)
    ComboBox1: TComboBox;   //комбобокс используемый для сортировки
    DBGrid1: TDBGrid;      //встроенный навигатор используемый для взаимодействия с таблицей и бд
    Label1: TLabel;         //заголовок
    procedure ComboBox1Change(Sender: TObject);         //производим сортировку по выбранному значению при выборе элемента из комбобокса
    procedure FormCreate(Sender: TObject);     //заполняем комбобокс соответствующими значениями при открытии формы
  private

  public

  end;

var
  Lookinst: TLookinst;

implementation
           uses maindata;
{$R *.lfm}

{ TLookinst }

procedure TLookinst.FormCreate(Sender: TObject);
begin
      maindata.MainDatas.QuaryNameGR.close;
      maindata.MainDatas.QueryStudents.close;
      maindata.MainDatas.QueryStudents.open;
      maindata.MainDatas.QuaryNameGR.open;
      while not(maindata.MainDatas.QuaryNameGR.eof) do //проходим по запросу с именами групп
           begin
             {DBGrid1.Columns[1].PickList.Add(maindata.MainDatas.Qdstud.FieldByName('idstudents').AsString);    }
             {students.LookStudents.GroupsSort.Items.Add(maindata.MainDatas.quaryNameGR.FieldByName('namegroups').AsString); }
             ComboBox1.Items.add(maindata.MainDatas.QuaryNameGR.FieldByName('namegroups').AsString);//в наш комбобокс добавляем значение с данного указателя из колонки название группы
             maindata.MainDatas.QuaryNameGR.next; //сдвуигаем указатель
           end;
end;

procedure TLookinst.ComboBox1Change(Sender: TObject);
begin
           maindata.MainDatas.QueryStudents.close; //закрываем таблицу
           if not (ComboBox1.Text = 'Все') then  //проверяем на выбранный элемент
               maindata.MainDatas.QueryStudents.SQL[3]:='and  Groups.namegroups='+ chr(39) +ComboBox1.Text+ chr(39)  //добавляем часть кода
            else
                 maindata.MainDatas.QueryStudents.SQL[3]:='';//очищаем
              maindata.MainDatas.QueryStudents.open;  //открываем таблицы
end;

end.

