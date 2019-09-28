PROGRAM triangle;
VAR
   a,b,c:integer;
BEGIN
     writeln('Please enter the first edge:  ');
     readln(a);
     writeln('Please enter the second edge:  ');
     readln(b);
     writeln('Please enter the third edge: ');
     readln(c);

     if a = b then
     begin
        if a = c then
        begin;
              writeln('ESKENAR!');
        end
        else
            begin
            writeln('IKIZKENAR!');
        end;
     end
     else
     begin
          if b = c then
          begin
               writeln('IKIZKENAR!');
          end
          else
          begin
               if a = c then
               begin
                   writeln('IKIZKENAR!');
               end
               else
               begin
                   writeln('CESIT KENAR!');
               end;
          end;
     end;


     writeln('Press enter the to close the program... ');
     readln();
END.
