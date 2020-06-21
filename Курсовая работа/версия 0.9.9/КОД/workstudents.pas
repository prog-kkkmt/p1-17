unit WorkStudents;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls;

type

  { TFWorkStd }

  TFWorkStd = class(TForm)
    Stud: TDBGrid;      //грид для вывода таблицы стужентов
    DBGrid2: TDBGrid;      //грид для вывода таблицы групп
    DBNavigator1: TDBNavigator;            //встроенный навигатор используемый для взаимодействия с таблицей и бд
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  FWorkStd: TFWorkStd;

implementation
         uses maindata;
{$R *.lfm}

{ TFWorkStd }

procedure TFWorkStd.FormCreate(Sender: TObject);
begin
          maindata.MainDatas.MainGroups.close; //переоткрываем тадблицу
          maindata.MainDatas.MainGroups.open;
          maindata.MainDatas.quaryNameGR.Close;
          maindata.MainDatas.quaryNameGR.open;     //переоткрываем запрос для обновления
          while not(maindata.MainDatas.quaryNameGR.eof) do   //проходим по запросу с именами групп
           begin
             Stud.Columns[4].PickList.Add(maindata.MainDatas.quaryNameGR.FieldByName('idgroups').AsString);       //из 4 колонки делаем выпадающий список с добавлением соответсвующих значений
             {students.LookStudents.GroupsSort.Items.Add(maindata.MainDatas.quaryNameGR.FieldByName('namegroups').AsString); }
             maindata.MainDatas.quaryNameGR.next; //сдвигаем указатель
           end;

end;

end.

