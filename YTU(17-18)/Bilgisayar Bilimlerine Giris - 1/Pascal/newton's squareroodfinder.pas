PROGRAM karekok;
VAR
   n:integer;
   E,oldA,newA,difference:real;
BEGIN
     writeln('Karekokunu bulmak istediðiniz sayiyi giriinz:  ');
     readln(n);
     writeln('Hassasiyeti giriniz: ');
     readln(E);

     oldA:=1;
     newA:= ( oldA + (N/oldA) ) / 2;
     difference := abs(oldA - newA);



     (*if difference < 0 then
     begin
          difference := difference * -1;
     end;*)


     while difference > E do
     begin
          oldA := newA;
          newA:= ( oldA + (N/oldA) ) / 2;
          difference := abs(oldA - newA);


          (*if difference < 0 then
          begin
               difference := difference * -1;
          end;*)
           (* writeln(newA:0:6); *)
     end;

     writeln('Square root of ', n ,' is = ',newA:0:6);
     writeln('Press ENTER to close the program.. ');
     readln();

END.
