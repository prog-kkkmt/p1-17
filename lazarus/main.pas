unit Main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, Buttons, ExtCtrls,
  MaskEdit, StdCtrls;
type NOTE=record
     name:string;
     secondname:string;
     fathername:string;
     Oc: array of integer;
     end;
type

  { TForm1 }

  TForm1 = class(TForm)
    Batton_append: TBitBtn;
    AppendDay: TButton;
    PrintAll: TBitBtn;
    Setings: TBitBtn;
    PrintNext: TBitBtn;
    PrintLast: TBitBtn;
    In_name: TLabeledEdit;
    in_SecondName: TLabeledEdit;
    InFatherName: TLabeledEdit;
    procedure Batton_appendClick(Sender: TObject);
    procedure AppendDayClick(Sender: TObject);
    procedure PrintAllClick(Sender: TObject);
    {procedure PrintFaileClick(Sender: TObject);}
    procedure PrintLastClick(Sender: TObject);
    procedure PrintNextClick(Sender: TObject);
    procedure SetingsClick(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;
  i, j: integer ;
  Students: array of NOTE;
  temps :string;
  Kolstudent, Last, kolday: integer;

implementation
uses u_f2;
{$R *.lfm}
  {PrintStudents}
{ TForm1 }

procedure TForm1.Batton_appendClick(Sender: TObject);
begin
     KolStudent:=KolStudent + 1;
     setlength(Students,KolStudent);
     Students[kolStudent-1].name:=in_name.Text;
     Students[kolStudent-1].secondname :=in_SecondName.Text;
     Students[kolStudent-1].fathername:=InFatherName.Text;
     Last :=  KolStudent-1;
end;

procedure TForm1.AppendDayClick(Sender: TObject);
begin
     if(kolStudent<=0)then
                ShowMessage('Сначала введите студентов')
                else begin
      u_f2.Form3.Show;
      Main.Form1.Hide;
                end;
end;

procedure TForm1.PrintAllClick(Sender: TObject);
begin
          for i :=0 to  kolstudent-1 do begin
              temps := temps +students[i].secondname + ' : ';
              for j:=0 to kolday-1 do
                  temps := temps + IntToStr(students[i].Oc[j]) + ' ';
              ShowMessage('Оценки студента ' + temps);
              temps:='';
          end;

end;


{procedure TForm1.PrintFaileClick(Sender: TObject);
begin
    assign(f,'PrintStudents.txt');
end; }

procedure TForm1.PrintLastClick(Sender: TObject);
begin
     if(kolstudent>0) then begin
     in_name.Text := Students[last].name;
     in_SecondName.Text:= Students[last].secondname;
     InFatherName.Text:= Students[last].fathername;
     last:= last-1;
     if(last<0) then
                last :=0;
     end;
end;

procedure TForm1.PrintNextClick(Sender: TObject);
begin
     if(kolstudent>0) then begin
     in_name.Text := Students[last].name;
     in_SecondName.Text:= Students[last].secondname;
     InFatherName.Text:= Students[last].fathername;
     last:= last+1;
     if(last>KolStudent-1) then
                last :=KolStudent-1;
     end;
end;

procedure TForm1.SetingsClick(Sender: TObject);
begin
     setlength(Students,KolStudent);
     Students[last].name:=in_name.Text;
     Students[last].secondname :=in_SecondName.Text;
     Students[last].fathername:=InFatherName.Text;
end;

end.

