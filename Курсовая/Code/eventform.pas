unit EventForm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TEventForm }

  { TEvent_Form }

  TEvent_Form = class(TForm)
    Back: TButton;
    ShowEventsTable: TButton;
    AddEvent: TButton;
    EditEvent: TButton;
    DeleteEvent: TButton;
    CaptionEventForm: TLabel;
    procedure BackClick(Sender: TObject);
  private

  public

  end;

var
  Event_Form: TEvent_Form;

implementation
uses
  MainForm;


{$R *.lfm}

{ TEvent_Form }

procedure TEvent_Form.BackClick(Sender: TObject);
begin
  Close;
  Main_Form.Show;
end;

end.

