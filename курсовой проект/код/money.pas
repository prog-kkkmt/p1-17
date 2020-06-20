unit money;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ComCtrls, DBCtrls,
  DBGrids, dm;

type

  { Tumain2 }

  Tumain2 = class(TForm)
    DBGrid1: TDBGrid; //компонент отображения таблицы доходов
    DBGrid2: TDBGrid; //компонент отображения таблицы расходов
    DBNavigator1: TDBNavigator; //компонент для работы с полями т. доходов
    DBNavigator2: TDBNavigator; //компонент для работы с полями т. расходов
    PageControl1: TPageControl; //окно с вкладками
    TabSheet1: TTabSheet; //вкладка "Доходы"
    TabSheet2: TTabSheet; //вкладка "Расходы"
  private

  public

  end;

var
  umain2: Tumain2;

implementation

{$R *.lfm}

end.

