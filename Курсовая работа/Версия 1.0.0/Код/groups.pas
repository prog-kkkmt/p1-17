unit Groups;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, DBGrids, DBCtrls;

type

  { TFGroup }

  TFGroup = class(TForm)
    DBGrid1: TDBGrid;    //грид для вывода таблицы
    DBNavigator1: TDBNavigator; //встроенный навигатор используемый для взаимодействия с таблицей и бд
  private

  public

  end;

var
  FGroup: TFGroup;

implementation

{$R *.lfm}

end.

