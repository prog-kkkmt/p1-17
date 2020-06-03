{*
  Знакомство с Lazarus.
  Выполнил Бобнев Алексей П1-17.
  03.06.2020
*}
program Primer_1;

var
  a, menu : integer;
  b, c: integer;
begin
  writeln('Hello, KKMT');
  writeln('1 - Plus');
  writeln('1 - Minus');
  readln(menu);
  if menu = 1 then
     begin
       readln(a);
       readln(b);
       c := a + b;
       writeln(c);
     end;
  if menu = 2 then
     begin
       readln(a);
       readln(b);
       c := a - b;
       writeln(c);
     end;
  readln();
end.

