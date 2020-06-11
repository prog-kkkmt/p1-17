unit MainForm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, DBGrids,
  Menus, ActnList, ComCtrls, Types;

type

  { TFormmain }

  TFormmain = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private

  public

  end;

var
  Formmain: TFormmain;

implementation
          uses Groups, students, WorkStudents;
{$R *.lfm}

{ TFormmain }

procedure TFormmain.Button1Click(Sender: TObject);
begin
       Groups.FGroup.ShowModal;
end;

procedure TFormmain.Button2Click(Sender: TObject);
begin
  students.LookStudents.showmodal;
end;

procedure TFormmain.Button3Click(Sender: TObject);
begin
      WorkStudents.FWorkStd.showmodal;
end;


end.

