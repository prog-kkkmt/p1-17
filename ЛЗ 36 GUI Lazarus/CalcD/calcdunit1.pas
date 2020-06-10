unit CalcDUnit1;

{$mode objfpc}{$H+}

interface

uses
 Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
 ExtCtrls, Math;

type

 { TForm1 }

 TForm1 = class(TForm)
  BtnNum0: TButton;
  BtnNum1: TButton;
  BtnNum2: TButton;
  BtnNum3: TButton;
  BtnNum4: TButton;
  BtnNum5: TButton;
  BtnNum6: TButton;
  BtnNum7: TButton;
  BtnNum8: TButton;
  BtnNum9: TButton;
  BtnP: TButton;
  BtnRes: TButton;
  BacSpBtn: TButton;
  KorBtn: TButton;
  MLetterPan: TPanel;
  StepBtn: TButton;
  ProcBtn: TButton;
  MFlbl: TLabel;
  MCBtn: TButton;
  MRBtn: TButton;
  MSBtn: TButton;
  MPlusBtn: TButton;
  MMiBtn: TButton;
  CEBtn: TButton;
  CBtn: TButton;
  PlMiBtn: TButton;
  EdRes: TEdit;
  BtnM: TButton;
  BtnD: TButton;
  BtnU: TButton;
  procedure BacSpBtnClick(Sender: TObject);
  procedure BtnNum1Click(Sender: TObject);
  procedure BtnPClick(Sender: TObject);
  procedure BtnResClick(Sender: TObject);
  procedure CBtnClick(Sender: TObject);
  procedure CEBtnClick(Sender: TObject);
  procedure KorBtnClick(Sender: TObject);
  procedure MCBtnClick(Sender: TObject);
  procedure MMiBtnClick(Sender: TObject);
  procedure MPlusBtnClick(Sender: TObject);
  procedure MRBtnClick(Sender: TObject);
  procedure MSBtnClick(Sender: TObject);
  procedure PlMiBtnClick(Sender: TObject);
  procedure ProcBtnClick(Sender: TObject);
  procedure StepBtnClick(Sender: TObject);
 private
  { private declarations }
 public
  { public declarations }
 end;

var
 Form1: TForm1;
 opr1,opr2,res:Integer;
 mathf:String;
 Clear:Boolean;
 Mem:Integer;
 vozv:Integer;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.BtnNum1Click(Sender: TObject);
begin
 If (EdRes.Text='0') or (clear) then EdRes.Text:='';
 EdRes.Text:=EdRes.Text+(Sender as TButton).Caption;
 Clear:=False;
end;

procedure TForm1.BacSpBtnClick(Sender: TObject);
begin
 If (EdRes.Text<>'0') or (clear=False) then EdRes.Text:=IntToStr(StrToInt(EdRes.Text)  div 10);
end;

procedure TForm1.BtnPClick(Sender: TObject);
begin
 opr1:=StrToInt(EdRes.Text);
 mathf:=(Sender as TButton).Caption;
 Clear:=True;
end;

procedure TForm1.BtnResClick(Sender: TObject);
begin
 If (Clear=False) then opr2:=StrToInt(EdRes.Text);
 Case mathf of
 '+':res:=opr1+opr2;
 '-':res:=opr1-opr2;
 '*':res:=opr1*opr2;
 '/':res:=opr1 div opr2;
 '^i':res:=round(Math.Power(opr1,opr2));
 end;
 opr1:=res;
 EdRes.Text:=IntToStr(res);
 Clear:=True;
end;

procedure TForm1.CBtnClick(Sender: TObject);
begin
 opr1:=0;
 opr2:=0;
 res:=0;
 mathf:='';
 Clear:=True;
 EdRes.Text:='0';
end;

procedure TForm1.CEBtnClick(Sender: TObject);
begin
 EdRes.Text:='0';
end;

procedure TForm1.KorBtnClick(Sender: TObject);
begin
 opr1:=round(Sqrt(StrToInt(EdRes.Text)));
 EdRes.Text:=IntToStr(opr1);
end;

procedure TForm1.MCBtnClick(Sender: TObject);
begin
 Mem:=0;
 MLetterPan.Visible:=False;
end;

procedure TForm1.MMiBtnClick(Sender: TObject);
begin
 Mem:=Mem-StrToInt(EdRes.Text);
 If Mem=0 then MLetterPan.Visible:=False;
 If Mem<>0 then MLetterPan.Visible:=True;
end;

procedure TForm1.MPlusBtnClick(Sender: TObject);
begin
 Mem:=Mem+StrToInt(EdRes.Text);
 If Mem=0 then MLetterPan.Visible:=False;
 If Mem<>0 then MLetterPan.Visible:=True;
end;

procedure TForm1.MRBtnClick(Sender: TObject);
begin
 EdRes.Text:=IntToStr(Mem);
end;

procedure TForm1.MSBtnClick(Sender: TObject);
begin
 Mem:=StrToInt(EdRes.Text);
 If Mem=0 then MLetterPan.Visible:=False;
 If Mem<>0 then MLetterPan.Visible:=True;
end;

procedure TForm1.PlMiBtnClick(Sender: TObject);
begin
 EdRes.Text:=IntToStr(StrToInt(EdRes.Text)*-1);
end;

procedure TForm1.ProcBtnClick(Sender: TObject);
begin
 opr2:=StrToInt(EdRes.Text)*(opr1 div 100);
 EdRes.Text:=IntToStr(opr2);
end;

procedure TForm1.StepBtnClick(Sender: TObject);
begin
 opr1:=StrToInt(EdRes.Text);
 mathf:=(Sender as TButton).Caption;
 Clear:=True;
end;

end.

