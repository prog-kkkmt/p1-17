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
  Batton_append: TBitBtn;{Добавляем студента}
    AppendDay: TButton;{Добавляем день}
    PrintAll: TBitBtn;{Выводим оценки}
    Setings: TBitBtn;{Изменяем нашего студента}
    PrintNext: TBitBtn;{смотрм следующего}
    PrintLast: TBitBtn;{смотрим предыдущего}
    In_name: TLabeledEdit;{Добавляем студента}
    in_SecondName: TLabeledEdit;{Добавляем студента}
    InFatherName: TLabeledEdit;{Добавляем студента}
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
  Students: array of NOTE;{массив структуры студентов}
  temps :string;
  Kolstudent, Last, kolday: integer;

implementation
uses u_f2;{подсоеденяем вторую форму}
{$R *.lfm}
  {PrintStudents}
{ TForm1 }

procedure TForm1.Batton_appendClick(Sender: TObject);
begin
     KolStudent:=KolStudent + 1;
     setlength(Students,KolStudent);{Изменяем размер динмаческого  массива}
     Students[kolStudent-1].name:=in_name.Text;
     Students[kolStudent-1].secondname :=in_SecondName.Text;
     Students[kolStudent-1].fathername:=InFatherName.Text;
     Last :=  KolStudent-1;
end;

procedure TForm1.AppendDayClick(Sender: TObject);
begin
if(kolStudent<=0)then{проверка на правильность ввода}
                ShowMessage('Сначала введите студентов')
                else begin
                u_f2.Form3.Show;{Показываем следующую форму}
                Main.Form1.Hide;{Скрываем нынешнюю это две команды можно было заменить на showmodel}
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


procedure TForm1.PrintLastClick(Sender: TObject);
begin
     if(kolstudent>0) then begin
     in_name.Text := Students[last].name;
     in_SecondName.Text:= Students[last].secondname;
     InFatherName.Text:= Students[last].fathername;
     last:= last-1;
     if(last<0) then{проверка на уход в низ}
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
     if(last>KolStudent-1) then{прверка на уход в верх}
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

