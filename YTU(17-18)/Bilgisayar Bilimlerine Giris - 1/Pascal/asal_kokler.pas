PROGRAM asal_kokler;
VAR
   n,x,i,eksibir:integer;

BEGIN
     writeln('Koklerine ayrilmasini istedigini sayiyi giriniz. ');
     readln(n);

     if n < 0 then
     begin
          x := -1 * n;
          eksibir := 1;
          write('Kokler : -1, ');
     end
     else
     begin
          x := n;
          write('Kokler :');
     end;

     if x = 0 then
     begin
          write(0);
     end
     else if x = 1 then
     begin
        write(1);
     end
     else
     begin
          i := 2;

          while i <= x do
          begin
               if x mod i = 0 then
               begin
                    write(i, ', ');
                    x:=x div i;
                    i:=2;
               end
               else
               begin
                    i:=i+1;

               end;
          end;
     end;



     readln;
END.
