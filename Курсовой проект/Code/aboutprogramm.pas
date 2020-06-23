unit AboutProgramm;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TFAboutProgramm }

  TFAboutProgramm = class(TForm)   //Класс формы "О программе"
    Label1: TLabel;   //  надпись "Курсовой проект на тему:"
    Label2: TLabel;   //  надпись "Разработка приложения"
    Label3: TLabel;   //  надпись ""Предприятие быстрого питания""
    Label4: TLabel;   //  надпись "Разработчик: студент П1-17 Попкова Алена"

  private

  public

  end;

var
  FAboutProgramm: TFAboutProgramm;

implementation

{$R *.lfm}

{ TFAboutProgramm }


end.

