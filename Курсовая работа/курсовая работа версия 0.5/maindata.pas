unit maindata;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, IBDatabase, IBTable, IBCustomDataSet, IBQuery, db,
  StdCtrls, Dialogs;

type

  { TMainDatas }

  TMainDatas = class(TDataModule)
    OpenDialog1: TOpenDialog;
    QDatDATAS: TIBStringField;
    QDstudIDGROUPS: TIBIntegerField;
    QDstudIDSTUDENTS: TIBIntegerField;
    QDstudNAMEGROUPS: TIBStringField;
    QDstudSECONDNAME: TIBStringField;
    QueryOcDATAS: TIBStringField;
    QueryOcHAVEWORK: TIBStringField;
    QueryOcIDOC: TIBIntegerField;
    QueryOcNAMEGROUPS: TIBStringField;
    QueryOcOCENKA: TIBStringField;
    QueryOcSECONDNAME: TIBStringField;
    SqDat: TDataSource;
    SQstud: TDataSource;
    QDat: TIBQuery;
    QDstud: TIBQuery;
    SourceOc: TDataSource;
    QueryOc: TIBQuery;
    Workstd: TIBTable;
    SourceWorkStd: TDataSource;
    LookOcenkiDATAS: TIBStringField;
    LookOcenkiHAVEWORK: TIBStringField;
    LookOcenkiIDOC: TIBIntegerField;
    LookOcenkiNAMEGROUPS: TIBStringField;
    LookOcenkiSECONDNAME: TIBStringField;
    LookOcenkiVALUE: TIBIntegerField;
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
    WorkstdDATAS: TIBStringField;
    WorkstdHAVEWORK: TIBStringField;
    WorkstdIDOC: TIBIntegerField;
    WorkstdIDSTUD: TIBIntegerField;
    WorkstdOCENKA: TIBStringField;
    WorkWithOcDATAS: TIBStringField;
    WorkWithOcHAVEWORK: TIBStringField;
    WorkWithOcIDGROUPS: TIBIntegerField;
    WorkWithOcIDOC: TIBIntegerField;
    WorkWithOcIDSTUDENTS: TIBIntegerField;
    WorkWithOcVALUE: TIBStringField;
    procedure DataModuleCreate(Sender: TObject);
  private

  public
               {procedure loadtable();   }
  end;

var
  MainDatas: TMainDatas;

implementation
             uses WorkStudentsForms;
{$R *.lfm}

{ TMainDatas }

procedure TMainDatas.DataModuleCreate(Sender: TObject);
begin                  //поочереди включаем все необходимые нам компоненты
     //C:\Users\asferd\Desktop\workwithbd\MYSTUDENTS.FDB
     //IDData.DatabaseName:='127.0.0.1:C:\Users\asferd\Desktop\workwithbd\MYSTUDENTS.FDB';
     if(opendialog1.Execute) then begin
                             //assignfile(f, opendialog1.FileName);
                             IDData.DatabaseName:='127.0.0.1:' + ExtractFileDir(OpenDialog1.FileName)+'\MYSTUDENTS.FDB';
                             IdTrans.StartTransaction;
                             MainGroups.open;
                             QueryStudents.Open;
                             MainStudent.Open;
                             quaryNameGR.open;
                             workstd.open;
                             QueryOc.Open;
                             Qdstud.open;
                             qdat.Open;

     end;


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

