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
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  Event_Form: TEvent_Form;

implementation

{$R *.lfm}

{ TEvent_Form }

procedure TEvent_Form.FormCreate(Sender: TObject);
begin
  ShowModal;
end;

end.

