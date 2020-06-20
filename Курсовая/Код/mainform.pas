unit MainForm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  DBGrids, DBCtrls;

type

  { TMain_Form }

  TMain_Form = class(TForm) //класс формы с таблицами БД
    DBGrid1: TDBGrid;       //компонент для отображения данных таблицы
    DBGrid2: TDBGrid;       //компонент для отображения данных таблицы
    DBNavigator1: TDBNavigator;   //компонент для работы с таблицей
    DBNavigator2: TDBNavigator;   //компонент для работы с таблицей
    Label1: TLabel;               //текст
    Label2: TLabel;               //текст
  private

  public

  end;

var
  Main_Form: TMain_Form;

implementation

{$R *.lfm}


end.

