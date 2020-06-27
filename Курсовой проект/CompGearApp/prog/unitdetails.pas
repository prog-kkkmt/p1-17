unit unitDetails;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls;

type

  { TFormDetails }

  TFormDetails = class(TForm)
    DBGrid1: TDBGrid;
    DBNavigator1: TDBNavigator;
  private

  public

  end;

var
  FormDetails: TFormDetails;

implementation

{$R *.lfm}

end.

