PROGRAM deneme;
type
    faati = array[1..5] of integer;
VAR
   dedeler:faati;
   n:integer;
BEGIN
     for n:=1 to 5 do
     begin
          dedeler[n] := 2 * n;
     end;
     for n:=1 to 5 do
     begin
          writeln(dedeler[n]);
     end;

END.
