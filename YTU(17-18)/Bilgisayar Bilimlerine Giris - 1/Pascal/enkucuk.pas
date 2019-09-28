PROGRAM enkucuk;
VAR
   a,b,c:integer;
BEGIN
     writeln('Enter first number: ');
     readln(a);
     writeln('Enter second number: ');
     readln(b);
     writeln('Enter third number: ');
     readln(c);

     if a < b then
     begin
          if a < c then
          begin
               writeln('En kucuk deger: ',a);
          end
          else
          begin
               writeln('En kucuk deger: ',c);
          end
     end
     else
     begin
           if b < c then
          begin
               writeln('En kucuk deger: ',b);
          end
          else
          begin
               writeln('En kucuk deger: ',c);
          end
     end;



     writeln('Press ENTER to close program: ');
     readln();
END.
