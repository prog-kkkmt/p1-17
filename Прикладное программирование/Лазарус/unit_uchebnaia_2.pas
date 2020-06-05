unit Unit_uchebnaia_2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    CheckBox1: TCheckBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    RadioButton1: TRadioButton;
    RadioButton2: TRadioButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure CheckBox1Change(Sender: TObject);
    procedure RadioButton1Change(Sender: TObject);
    procedure RadioButton2Change(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button2Click(Sender: TObject);
begin
  close;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  Form1.Width := Form1.Width + 5;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
   Form1.Height := Form1.Height + 5;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  Form1.Width := Form1.Width - 5;
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
  Form1.Height := Form1.Height - 5;
end;

procedure TForm1.CheckBox1Change(Sender: TObject);
begin
   Button3.Enabled := not CheckBox1.Checked;
end;

procedure TForm1.RadioButton1Change(Sender: TObject);
begin
   label3.Caption := '1';
end;

procedure TForm1.RadioButton2Change(Sender: TObject);
begin
  label3.Caption := '2';
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  label2.Caption := 'Hello, world!';
end;

end.

