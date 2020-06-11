program MainForms;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, MainForm, maindata, Groups, students, WorkStudents
  { you can add units after this };

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Scaled:=True;
  Application.Initialize;
  Application.CreateForm(TFormmain, Formmain);
  Application.CreateForm(TMainDatas, MainDatas);
  Application.CreateForm(TFGroup, FGroup);
  Application.CreateForm(TLookStudents, LookStudents);
  Application.CreateForm(TFWorkStd, FWorkStd);
  Application.Run;
end.

