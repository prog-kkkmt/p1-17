program proekt;
{Таблица "ежедневник"
 1.Дата
 2.Заметки
}
uses
  crt,

  SysUtils,
  Windows;

const
  MaxVSize = 30; { Максимальное количество записей }
type

    Tday = integer;              {тип - день}
    Tmonth = integer;            {тип - месяц}
    Tyear = integer;             {тип - год}
    Tnotes = string[30];         {тип - заметки}
    Tplanner = record            {тип - структура записи о ежедневнике}
    day : Tday;         {день}
    month : Tmonth;     {месяц}
    year :  Tyear;      {год}
    notes : Tnotes;     {заметки}
    end;

  TFileName   = string[30]; { Тип - Имя файла } /// 30
  TVector     = array[1..MaxVSize] of integer; { Тип - Массив номеров записей }
  TPlannerFile  = file of Tplanner; { Тип - Файл записей о ежедневнике}

  { Храним в одной переменной и массив номеров записей, и фактический размер массива }
  { Таких массивов может быть несколько, если потребуется упорядочить список книг
    еще по каким-то критериям, например, по названию книг в алфавитном порядке }

  TIndex      = record
    v: TVector;
    vSize: integer; { Используемый размер массива (число записей) }
  end;
  var
  iChoice  : integer;    { Выбранный пункт меню }
  IsReady  : boolean;    { Файл открыт для работы }
  idx      : TIndex;     { Массив номеров записей }
  f        : TPlannerFile; { Файл записей о ежедневнике }
  fname    : TFileName;  { Имя файла записей о ежедневнике }
  Membook  : Tplanner;      { Карточка книги или шаблон для поиска / упорядочения }




