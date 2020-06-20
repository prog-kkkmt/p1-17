unit WorkOcenki;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls;

type

  { TWorkOc }

  TWorkOc = class(TForm)
    DBGrid1: TDBGrid;
    DBGrid2: TDBGrid;
    DBNavigator1: TDBNavigator;
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  WorkOc: TWorkOc;

implementation
           uses maindata;
{$R *.lfm}

{ TWorkOc }

procedure TWorkOc.FormCreate(Sender: TObject);
begin
          maindata.MainDatas.Qdstud.close;
          maindata.MainDatas.Qdstud.open;
          while not(maindata.MainDatas.Qdstud.eof) do  //проходим по всему запросу по студентам
           begin
             DBGrid1.Columns[1].PickList.Add(maindata.MainDatas.Qdstud.FieldByName('idstudents').AsString);//из первой колоник делаем комбобокс и всавляем туда соответсвующее значение
             {students.LookStudents.GroupsSort.Items.Add(maindata.MainDatas.quaryNameGR.FieldByName('namegroups').AsString); }
             maindata.MainDatas.Qdstud.next;  //сдвигаем указатель
           end;

end;

end.

