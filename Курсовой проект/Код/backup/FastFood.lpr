program FastFood;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, AppMenu, finance, prodmenu, warehouse;

{$R *.res}

begin
  RequireDerivedFormResource:=True;
  Application.Scaled:=True;
  Application.Initialize;
  Application.CreateForm(TAppMenu1, AppMenu1);
  Application.CreateForm(TFormFinance, FormFinance);
  Application.CreateForm(TFProdMenu, FProdMenu);
  Application.CreateForm(TFWarehouse, FWarehouse);
  Application.Run;
end.

