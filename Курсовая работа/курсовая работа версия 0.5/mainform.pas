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
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
  private

  public

  end;

var
  Formmain: TFormmain;

implementation
          uses Groups, WorkStudentsForms, WorkStudents, lookocenki, workocenki, lokallstudents;
{$R *.lfm}

{ TFormmain }

procedure TFormmain.Button1Click(Sender: TObject);
begin
       Groups.FGroup.ShowModal;     //открываем таблицу групп
end;

procedure TFormmain.Button2Click(Sender: TObject);
begin
       lokallstudents.Form1.showmodal;   //открываем таблицу просмотр студентов
end;

procedure TFormmain.Button3Click(Sender: TObject);
begin
      WorkStudents.FWorkStd.showmodal;     //открываем таблицу работа со студентами
end;

procedure TFormmain.Button4Click(Sender: TObject);
begin
            lookocenki.LookinOc.ShowModal;   //открываем форму с таблицой просмотр оценок
end;

procedure TFormmain.Button5Click(Sender: TObject);
begin
      workocenki.WorkOc.ShowModal;    //открываем форму с таблицой работа с оценками
end;

procedure TFormmain.Button6Click(Sender: TObject);
begin
     showmessage('В разработке');
end;

procedure TFormmain.Button7Click(Sender: TObject);
begin
         showmessage('В разработке');
end;

procedure TFormmain.Button8Click(Sender: TObject);
begin
  showmessage('В разработке');
end;



end.

