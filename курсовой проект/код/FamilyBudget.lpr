program FamilyBudget;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, fmain, money, dm, budget, aboutProgram
  { you can add units after this };

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Scaled:=True;
  Application.Initialize;
  Application.CreateForm(Tumain, umain);//экземпляр формы umain
  Application.CreateForm(Tumain2, umain2); //экземпляр формы umain2
  Application.CreateForm(Tdmb, dmb);//экземпляр формы dmb
  Application.CreateForm(Tumain3, umain3);//экземпляр формы umain3
  Application.CreateForm(Tumain4, umain4);//экземпляр формы umain4
  Application.Run;
end.

