unit maindata;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, IBDatabase, IBTable, IBCustomDataSet, IBQuery, db, StdCtrls;

type

  { TMainDatas }

  TMainDatas = class(TDataModule)
    SourceNameGR: TDataSource;
    QuaryNameGR: TIBQuery;
    MainStudentFATHERNAME: TIBStringField;
    MainStudentIDGROUPS: TIBIntegerField;
    MainStudentIDSTUDENTS: TIBIntegerField;
    MainStudentNAME: TIBStringField;
    MainStudentNAMEINGIT: TIBStringField;
    MainStudentSECONDNAME: TIBStringField;
    QueryStudentsFATHERNAME: TIBStringField;
    QueryStudentsIDSTUDENTS: TIBIntegerField;
    QueryStudentsNAME: TIBStringField;
    QueryStudentsNAMEGROUPS: TIBStringField;
    QueryStudentsNAMEINGIT: TIBStringField;
    QueryStudentsSECONDNAME: TIBStringField;
    SourceStudent: TDataSource;
    MainStudent: TIBTable;
    SourceQSt: TDataSource;
    QueryStudents: TIBQuery;
    MainGroupsIDGROUPS: TIBIntegerField;
    MainGroupsNAMEGROUPS: TIBStringField;
    SourceGroupe: TDataSource;
    MainGroups: TIBTable;
    IdTrans: TIBTransaction;
    IDData: TIBDatabase;
    procedure DataModuleCreate(Sender: TObject);
  private

  public
               {procedure loadtable();   }
  end;

var
  MainDatas: TMainDatas;

implementation
             uses students;
{$R *.lfm}

{ TMainDatas }

procedure TMainDatas.DataModuleCreate(Sender: TObject);
begin
     IdTrans.StartTransaction;
     MainGroups.open;
     QueryStudents.Open;
     MainStudent.Open;
     quaryNameGR.open;
end;

{procedure TMainDatas.loadtable();
begin
     {QueryStudents.Close;
  QueryStudents.SQL.text := 'select * from ' + 'groups';
     QueryStudents.open;
     while not(QueryStudents.eof) do
           begin
             students.LookStudents.test.Items.Add(QueryStudents.FieldByName('idgroups').AsString);
             QueryStudents.next;
           end;
       }
end;   }

end.

