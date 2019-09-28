PROGRAM avarege;
VAR
   x,n,i:integer;
   sum:real;
BEGIN
     writeln('How many numbers you will enter?   ');
     readln(n);
     sum := 0;
     for i:=1 to n do
     begin
          writeln('Enter the ', i , '. number: ');
          readln(x);
          sum := sum + x;
     end;
     sum := sum / n;

     writeln('Avarege = ', sum);
     writeln('Press ENTER to close the program:  ');
     readln();
END.
