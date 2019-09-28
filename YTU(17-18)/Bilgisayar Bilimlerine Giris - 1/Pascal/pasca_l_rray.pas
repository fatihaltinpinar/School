PROGRAM pasca_l_rray;



VAR
   sicaklik: array[1..99] of integer;
   x_y_duzlemi : array [1..99, 1..99] of CHAR;
   k,eb,ek,x,y,i,n,tmp:integer;
BEGIN
     eb := 1;
     ek := 1;
     write('Kaç günlük deðerler gireceksiniz: ');
     read(n);

     writeln('');
     for i:=1 to n do
     begin
          readln(tmp);
          sicaklik[i] := tmp;
     end;
     for i:=1 to n do
     begin
          if sicaklik[eb]<sicaklik[i] then
          begin
               eb := i;
          end;
          if sicaklik[ek]>sicaklik[i] then
          begin
               ek :=i
          end;
     end;

     x := 1;
     y := sicaklik[eb] - sicaklik[1] + 1;

     for i:=1 to (sicaklik[eb]-sicaklik[ek] + 1) do
     begin
          for k:=1 to (n+1) do
          begin
               x_y_duzlemi[k,i] := ' ';
          end;
     end;

     for i:=1 to (n-1) do
     begin
         if sicaklik[i] = sicaklik [(i + 1)] then
         begin
              x_y_duzlemi[x,y] := '_';
              x := x + 1;

         end
         else if sicaklik[i] > sicaklik [(i + 1)] then
         begin
              for  k:=1 to (sicaklik[i] - sicaklik[(i+1)]) do
              begin
                   x_y_duzlemi[x,y] := '/';
                   x := x + 1;
                   y := y - 1;
              end;
         end
         else
         begin
              for k:=1 to (sicaklik[i] - sicaklik[(i+1)]) do
              begin
                   x_y_duzlemi[x,y] := '\';
                   x := x + 1;
                   y := y - 1;
              end;
         end;

     end;

     for i:=1 to y do
     begin
          for k:=1 to x do
          begin
               write(x_y_duzlemi[i,k]);
          end;
     end;


     writeln('Kapatmak için enter a basýnýz plx');
     read(n);
END.
