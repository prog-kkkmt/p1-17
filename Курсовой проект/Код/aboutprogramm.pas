unit AboutProgramm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TFAboutProgramm }

  TFAboutProgramm = class(TForm)   //Класс формы "О программе"
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  FAboutProgramm: TFAboutProgramm;

implementation

{$R *.lfm}

{ TFAboutProgramm }

procedure TFAboutProgramm.FormCreate(Sender: TObject);
begin

end;

end.

