unit LokAllStudents;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    ComboBox1: TComboBox;
    DBGrid1: TDBGrid;
    Label1: TLabel;
    procedure ComboBox1Change(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation
           uses maindata;
{$R *.lfm}

{ TForm1 }

procedure TForm1.FormCreate(Sender: TObject);
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

procedure TForm1.ComboBox1Change(Sender: TObject);
begin
           maindata.MainDatas.QueryStudents.close; //закрываем таблицу
           if not (ComboBox1.Text = 'Все') then  //проверяем на выбранный элемент
               maindata.MainDatas.QueryStudents.SQL[3]:='and  Groups.namegroups='+ chr(39) +ComboBox1.Text+ chr(39)  //добавляем часть кода
            else
                 maindata.MainDatas.QueryStudents.SQL[3]:='';//очищаем
              maindata.MainDatas.QueryStudents.open;  //открываем таблицы
end;

end.

