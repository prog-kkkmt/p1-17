unit MainForm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  DBGrids, DBCtrls;

type

  { TMain_Form }

  TMain_Form = class(TForm) //класс формы с таблицами БД
    DBGrid1: TDBGrid;
    DBGrid2: TDBGrid;
    DBNavigator1: TDBNavigator;
    DBNavigator2: TDBNavigator;
    Label1: TLabel;
    Label2: TLabel;
  private

  public

  end;

var
  Main_Form: TMain_Form;

implementation

{$R *.lfm}


end.

