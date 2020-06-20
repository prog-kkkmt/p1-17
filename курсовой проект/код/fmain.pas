unit fmain;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, money,  budget, aboutProgram;

type

  { Tumain }

  Tumain = class(TForm)
    budget: TButton; //бюджет
    about: TButton; // о программе
    tables: TButton; // таблицы
    procedure aboutClick(Sender: TObject);  //обработчик О программе
    procedure budgetClick(Sender: TObject); // обработчик бюджет
    procedure tablesClick(Sender: TObject);  // обработчик ввод дохода/расхода
  private

  public

  end;

var
  umain: Tumain;

implementation
 uses dm;

{$R *.lfm}

{ Tumain }

procedure Tumain.tablesClick(Sender: TObject);
begin
  umain2.Show();// форма ввода дохода/расхода
end;

procedure Tumain.budgetClick(Sender: TObject);
begin
  umain3.show(); // форма бюджета
end;

procedure Tumain.aboutClick(Sender: TObject);
begin
   umain4.show();//форма о программе
end;

end.

