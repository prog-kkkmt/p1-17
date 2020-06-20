unit WorkStudents;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls;

type

  { TFWorkStd }

  TFWorkStd = class(TForm)
    Stud: TDBGrid;
    DBGrid2: TDBGrid;
    DBNavigator1: TDBNavigator;
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  k:integer;
  FWorkStd: TFWorkStd;

implementation
         uses maindata;
{$R *.lfm}

{ TFWorkStd }

procedure TFWorkStd.FormCreate(Sender: TObject);
begin
          maindata.MainDatas.MainGroups.close;
          maindata.MainDatas.MainGroups.open;
          maindata.MainDatas.quaryNameGR.Close;
          maindata.MainDatas.quaryNameGR.open;
          while not(maindata.MainDatas.quaryNameGR.eof) do   //проходим по запросу с именами групп
           begin
             Stud.Columns[4].PickList.Add(maindata.MainDatas.quaryNameGR.FieldByName('idgroups').AsString);       //из 4 колонки делаем выпадающий список с добавлением соответсвующих значений
             {students.LookStudents.GroupsSort.Items.Add(maindata.MainDatas.quaryNameGR.FieldByName('namegroups').AsString); }
             maindata.MainDatas.quaryNameGR.next; //сдвигаем указатель
           end;

end;

end.

