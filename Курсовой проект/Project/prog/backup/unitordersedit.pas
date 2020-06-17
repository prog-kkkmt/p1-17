unit unitOrdersEdit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls,
  IBTable;

type

  { TFormOrdersEdit }

  TFormOrdersEdit = class(TForm)
    DBGrid1: TDBGrid;
    DBNavigator1: TDBNavigator;
  private

  public

  end;

var
  FormOrdersEdit: TFormOrdersEdit;

implementation

{$R *.lfm}

end.

