unit Groups;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls;

type

  { TFGroup }

  TFGroup = class(TForm)
    DBGrid1: TDBGrid;
    DBNavigator1: TDBNavigator;
  private

  public

  end;

var
  FGroup: TFGroup;

implementation

{$R *.lfm}

end.

