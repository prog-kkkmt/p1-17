unit WorkOcenki;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls;

type

  { TWorkOc }

  TWorkOc = class(TForm)
    DBGrid1: TDBGrid;   //шгрид для вывода оценок
    DBGrid2: TDBGrid;      //грид для вывода  студентов
    DBNavigator1: TDBNavigator;   ////встроенный навигатор используемый для взаимодействия с таблицей и бд
    procedure FormCreate(Sender: TObject);       //заполнение выпадающих списков таблицы
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
          maindata.MainDatas.Qdstud.close; //переоткрываем запрсо студентов
          maindata.MainDatas.Qdstud.open;
          while not(maindata.MainDatas.Qdstud.eof) do  //проходим по всему запросу по студентам
           begin
             DBGrid1.Columns[1].PickList.Add(maindata.MainDatas.Qdstud.FieldByName('idstudents').AsString);//из первой колоник делаем комбобокс и всавляем туда соответсвующее значение
             {students.LookStudents.GroupsSort.Items.Add(maindata.MainDatas.quaryNameGR.FieldByName('namegroups').AsString); }
             maindata.MainDatas.Qdstud.next;  //сдвигаем указатель
           end;

end;

end.

