unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, ExtCtrls,
  StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    lblNewGame: TLabel;
    lblExit: TLabel;
    lblRecord: TLabel;
    lblMenu: TLabel;
    lblScore: TLabel;
    lblGameOver: TLabel;
    lblRestart: TLabel;
    Paddle: TShape;
    Ball: TShape;
    tmrGame: TTimer;
    procedure ControlPaddle(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure FormCreate(Sender: TObject);
    procedure lblExitClick(Sender: TObject);
    procedure lblExitMouseEnter(Sender: TObject);
    procedure lblExitMouseLeave(Sender: TObject);
    procedure lblMenuClick(Sender: TObject);
    procedure lblMenuMouseEnter(Sender: TObject);
    procedure lblMenuMouseLeave(Sender: TObject);
    procedure lblRecordClick(Sender: TObject);
    procedure lblRecordMouseEnter(Sender: TObject);
    procedure lblRecordMouseLeave(Sender: TObject);
    procedure lblNewGameClick(Sender: TObject);
    procedure lblNewGameMouseEnter(Sender: TObject);
    procedure lblNewGameMouseLeave(Sender: TObject);
    procedure lblRestartClick(Sender: TObject);
    procedure lblRestartMouseEnter(Sender: TObject);
    procedure lblRestartMouseLeave(Sender: TObject);
    procedure PaddleMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer
      );
    procedure tmrGameTimer(Sender: TObject);
  private
    procedure InitGame;
    procedure UpdateScore;
    procedure GameOver;
    procedure IncSpeed;
  public
    { public declarations }
  end;

var
  Form1: TForm1;
  Score: Integer;
  SpeedX, SpeedY: Integer;

implementation

{$R *.lfm}

{ TForm1 }



procedure TForm1.ControlPaddle(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
  Paddle.Left:= X - Paddle.Width div 2;
  Paddle.Top:= ClientHeight - Paddle.Height - 3;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  DoubleBuffered:= True;
  lblGameOver.Visible:=False;
  lblRestart.Visible:=False;
  lblMenu.Visible:=False;
  lblScore.Visible:=False;
  Ball.Visible:=False;
  Paddle.Visible:=False;
  tmrGame.Enabled:=False;
end;

procedure TForm1.lblExitClick(Sender: TObject);
begin
  Close;
end;

procedure TForm1.lblExitMouseEnter(Sender: TObject);
begin
  lblExit.Font.Style:=[fsBold];
end;

procedure TForm1.lblExitMouseLeave(Sender: TObject);
begin
  lblExit.Font.Style:=[];
end;

procedure TForm1.lblMenuClick(Sender: TObject);
begin
  lblNewGame.Visible:=True;
  lblRecord.Visible:=True;
  lblExit.Visible:=True;
  lblGameOver.Visible:=False;
  lblRestart.Visible:=False;
  lblMenu.Visible:=False;
  lblScore.Visible:=False;
  Ball.Visible:=False;
  Paddle.Visible:=False;
  tmrGame.Enabled:=False;
end;

procedure TForm1.lblMenuMouseEnter(Sender: TObject);
begin
  lblMenu.Font.Style:=[fsBold];
end;

procedure TForm1.lblMenuMouseLeave(Sender: TObject);
begin
  lblMenu.Font.Style:=[];
end;

procedure TForm1.lblRecordClick(Sender: TObject);
begin

end;

procedure TForm1.lblRecordMouseEnter(Sender: TObject);
begin
  lblRecord.Font.Style:=[fsBold];
end;

procedure TForm1.lblRecordMouseLeave(Sender: TObject);
begin
  lblRecord.Font.Style:=[];
end;

procedure TForm1.lblNewGameClick(Sender: TObject);
begin
  Ball.Visible:=True;
  Paddle.Visible:=True;
  lblScore.Visible:=True;
  lblNewGame.Visible:=False;
  lblExit.Visible:=False;
  lblRecord.Visible:=False;
  InitGame;
end;

procedure TForm1.lblNewGameMouseEnter(Sender: TObject);
begin
  lblNewGame.Font.Style:=[fsBold];
end;

procedure TForm1.lblNewGameMouseLeave(Sender: TObject);
begin
  lblNewGame.Font.Style:=[];
end;

procedure TForm1.lblRestartClick(Sender: TObject);
begin
  InitGame;
end;

procedure TForm1.lblRestartMouseEnter(Sender: TObject);
begin
  lblRestart.Font.Style:=[fsBold];
end;

procedure TForm1.lblRestartMouseLeave(Sender: TObject);
begin
  lblRestart.Font.Style:=[];
end;

procedure TForm1.PaddleMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
  ControlPaddle(sender,Shift,X+Paddle.Left,Y+Paddle.Top);
end;

procedure TForm1.tmrGameTimer(Sender: TObject);
begin
  Ball.Left:=Ball.Left+SpeedX;
  Ball.Top:=Ball.Top+SpeedY;

  if Ball.Top <= 0 then
    SpeedY:=-SpeedY;
  if (Ball.Left <= 0) or (Ball.Left + Ball.Width >= ClientWidth) then
    SpeedX:=-SpeedX;

  if Ball.Top + Ball.Height >= ClientHeight then GameOver;

  if (Ball.Left + Ball.Width >= Paddle.Left) and (Ball.Left <= Paddle.Left + Paddle.Width)
    and (Ball.Top + Ball.Height >= Paddle.Top) then
  begin
    IncSpeed;
    SpeedY:= -SpeedY;
    Inc(Score);
    UpdateScore;
  end;

end;

procedure TForm1.InitGame;
begin
  Score:= 0;
  SpeedX:= 4;
  SpeedY:= 4;

  lblGameOver.Visible:=False;
  lblRestart.Visible:=False;
  lblMenu.Visible:=False;
  lblRestart.Font.Style:=[];

  Ball.Left:=10;
  Ball.Top:=10;

  UpdateScore;

  tmrGame.Enabled:=True;

end;

procedure TForm1.UpdateScore;
begin
  lblScore.Caption:= 'Score: ' + IntToStr(Score);
end;

procedure TForm1.GameOver;
begin
  tmrGame.Enabled:=False;

  lblGameOver.Visible:=True;
  lblRestart.Visible:=True;
  lblMenu.Visible:=True;
end;

procedure TForm1.IncSpeed;
begin
  if SpeedX > 0 then Inc(SpeedX) else Dec(SpeedX);
  if SpeedY > 0 then Inc(SpeedY) else Dec(SpeedY);
end;


end.

