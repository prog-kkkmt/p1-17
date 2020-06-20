program FastFood;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, AppMenu, finance, prodmenu, warehouse, dmd, aboutprogramm;

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Scaled:=True;
  Application.Initialize;
  Application.CreateForm(TAppMenu1, AppMenu1);     //Создание экземпляра формы AppMenu
  Application.CreateForm(TFormFinance, FormFinance);    //Создание экземпляра формы FormFinance
  Application.CreateForm(TFProdMenu, FProdMenu);     //Создание экземпляра формы FProdMenu
  Application.CreateForm(TFWarehouse, FWarehouse);    //Создание экземпляра формы FWarehouse
  Application.CreateForm(TDataModule2, DataModule2);    //Создание экземпляра формы модуля данных DataModule2
  Application.CreateForm(TFAboutProgramm, FAboutProgramm); //Создание экземпляра формы FAboutProgramm
  Application.Run;
end.

