program Planner;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, MainForm, DBC, openform
  { you can add units after this };

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Scaled:=True;
  Application.Initialize;   //инициализация
  Application.CreateForm(TOpen_Form, Open_Form); //создание экземпляра формы Open_Form
  Application.CreateForm(TMain_Form, Main_Form); //создание экземпляра формы Main_Form
  Application.CreateForm(TDataModule1, DataModule1); //создание экземпляра модуля данных DataModule1
  Application.Run;
end.

