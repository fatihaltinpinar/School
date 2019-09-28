PROGRAM fibonacci;
VAR
   a,b,c,n,i:integer;
BEGIN
     writeln('Please enter which fibonacci number you want to find:   ');
     readln(n);

     a := 1;
     b := 1;
     c := 1;

     for i:=3 to n do
     begin
          c:= a + b;
          a:= b;
          b:=c;
     end;
     writeln(n, '. fibonacci number is : ', b);

     writeln('Press enter to close the program...');
     readln();
END.

