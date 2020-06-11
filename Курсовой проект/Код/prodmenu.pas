unit prodmenu;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Menus;

type

  { TForm2 }

  TForm2 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    memo1: TMemo;
    Memo2: TMemo;
    Memo3: TMemo;
    procedure FormCreate(Sender: TObject);
    procedure Label2Click(Sender: TObject);
  private

  public

  end;

var
  Form2: TForm2;

implementation

{$R *.lfm}

{ TForm2 }

procedure TForm2.FormCreate(Sender: TObject);
begin

end;

procedure TForm2.Label2Click(Sender: TObject);
begin

end;

end.

