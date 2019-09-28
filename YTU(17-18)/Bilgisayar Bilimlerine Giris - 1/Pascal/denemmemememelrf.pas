PROGRAM alfabetik_sira ;

VAR
   kelimeler:array[1..100] of string;
   n,i,bakilan_harf:integer;
   sirali:boolean;

BEGIN
     write('Kac kelime gireceksiniz: ');
     readln(n);

     for i:=1 to n do
     begin
          write('1. Kelime= ');
          readln(kelimeler[i]);
     end;

     for i:=1 to n-1 do
     begin
          write(kelimeler[i] , ' - ');
     end;
     write(kelimeler[n]);
     writeln;

     writeln('Kelimeler siralanýyor...');
     sirali := false;
     bakilan_harf:=1;
     while sirali = false do
     begin
          for i:=1 to n do
          begin

          end;

     end;


     readln;



END.

