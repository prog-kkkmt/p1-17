program FastFood;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, AppMenu, finance, prodmenu, warehouse, dmFinance, dmwarehouse, dmprodmenu
  { you can add units after this };

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Scaled:=True;
  Application.Initialize;
  Application.CreateForm(TAppMenu1, AppMenu1);
  Application.CreateForm(TFormFinance, FormFinance);
  Application.CreateForm(TFProdMenu, FProdMenu);
  Application.CreateForm(TFWarehouse, FWarehouse);
  Application.CreateForm(TDataMFinance, DataMFinance);
  Application.CreateForm(TDataModule1, DataModule1);
  Application.CreateForm(TDataModule2, DataModule2);
  Application.Run;
end.

