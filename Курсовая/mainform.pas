unit MainForm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TMain_Form }

  TMain_Form = class(TForm)
    EventsOpen: TButton;
    PhoneBookOpen: TButton;
    CaptionMainForm: TLabel;
  private

  public

  end;

var
  Main_Form: TMain_Form;

implementation

{$R *.lfm}

{ TMainForm }

end.

