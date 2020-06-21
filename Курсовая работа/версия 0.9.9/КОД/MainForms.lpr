program MainForms;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, MainForm, maindata, Groups, WorkStudentsForms, WorkStudents,
  LookOcenki, WorkOcenki, LokAllStudents
  { you can add units after this };

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Title:='automatic education';
  Application.Scaled:=True;
  Application.Initialize;
  Application.CreateForm(TFormmain, Formmain);
  Application.CreateForm(TMainDatas, MainDatas);
  Application.CreateForm(TFGroup, FGroup);
  Application.CreateForm(TFWorkStd, FWorkStd);
  Application.CreateForm(TLookinOc, LookinOc);
  Application.CreateForm(TWorkOc, WorkOc);
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.

