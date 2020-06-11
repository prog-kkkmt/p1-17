unit students;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls,
  StdCtrls;

type

  { TLookStudents }

  TLookStudents = class(TForm)
    GroupsSort: TComboBox;
    DBGrid1: TDBGrid;
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  LookStudents: TLookStudents;

implementation
       uses maindata;
{$R *.lfm}

{ TLookStudents }


procedure TLookStudents.FormCreate(Sender: TObject);
begin
     maindata.MainDatas.QueryStudents.close;
     maindata.MainDatas.QueryStudents.open;
   maindata.MainDatas.quaryNameGR.close;
   maindata.MainDatas.quaryNameGR.open;
students.LookStudents.GroupsSort.Items.Add('Все');
while not(maindata.MainDatas.quaryNameGR.eof) do
           begin
             {DBGrid1.Columns[4].PickList.Add(maindata.MainDatas.quaryNameGR.FieldByName('namegroups').AsString);  }
             students.LookStudents.GroupsSort.Items.Add(maindata.MainDatas.quaryNameGR.FieldByName('namegroups').AsString);
             maindata.MainDatas.quaryNameGR.next;
           end;
end;


end.

