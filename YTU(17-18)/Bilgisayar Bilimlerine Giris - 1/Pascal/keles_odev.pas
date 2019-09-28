PROGRAM passwordfinder;
Uses crt,sysUtils;
VAR
   (*nmbr : array [1..10] of string;
   lcl: array [1..26] of string;
   ucl: array [1..26] of string; *)

   passlibrary:array [1..62] of char;
   guessDigit:array[1..8] of integer;
   hour,min,sec,ms,s_hour,s_min,s_sec,s_ms:word;
   pass,guess:string;

   timeStart,timeStop:TDateTime;

   button:char;

   dc,passtype,trials,i,j,k,maxValueDigit:integer;
   time:real;


BEGIN
     (*
     for i:=0 to 9 do
     begin
          nmbr[i+1] := IntToStr(i);
         // write(nmbr[i], ' ');
     end;
     // writeln;

     for i:=1 to 26 do
     begin
          lcl[i] := char(i+96);
         // write(lcl[i], ' ');
     end;
     // writeln;

     for i:=1 to 26 do
     begin
          ucl[i] := char(i+64);
         // write(ucl[i], ' ');
     end;
     // writeln;
     *)


     write('How many digits your password will have? Please enter [4/6/8]: ');
     readln(dc);

     if (dc = 4) or (dc = 6) or (dc = 8) then
     begin
           writeln;
           writeln('Choose your password tpye:');
           writeln;
           writeln('Your passwold can contain ');
           writeln('     1 just NUMBERS ');
           writeln('     2 just  LOWER CASE LETTERS');
           writeln('     3 both NUMBERS and LOWER CASE LETTERS');
           writeln('     4 NUMBERS, LOWER and UPPER CASE LETTERS');
           writeln;
           write('Choose [1/2/3/4]: ');

           readln(passtype);
           maxValueDigit:=0;

           if passtype = 1 then
           begin
                maxValueDigit := 10;

                for i:=1 to 10 do
                    passlibrary[i] := char(i+47);
                for i:=1 to 10 do
                    write(passlibrary[i] + ' ' );
           end
           else if passtype = 2 then
           begin

                maxValueDigit := 26;

                for i:=1 to 26 do
                    passlibrary[i] := char(i+96);
                for i:=1 to 26 do
                    write(passlibrary[i] + ' ' );
           end
           else if passtype = 3 then
           begin

                maxValueDigit := 36;

                for i:=1 to 10 do
                    passlibrary[i] := char(i+47);

                for i:=11 to 36 do
                    passlibrary[i] := char(i+86);

                for i:=1 to 36 do
                    write(passlibrary[i] + ' ' );

           end
           else if passtype = 4 then
           begin

                maxValueDigit := 62;

                for i:=1 to 10 do
                    passlibrary[i] := char(i+47);

                for i:=11 to 36 do
                    passlibrary[i] := char(i+86);

                for i:=37 to 62 do
                    passlibrary[i] := char(i+28);

                for i:=1 to 62 do
                    write(passlibrary[i] + ' ' );
           end
           else
              writeln('You have entered a invalid password type. ');
           if maxValueDigit <> 0 then
           begin
                writeln;
                writeln('Please enter your password');

                i:=1;
                while i <= dc do
                begin
                     button := readkey;
                     j:=1;
                     while j <= maxValueDigit do
                     begin
                          if passlibrary[j] = button then
                          begin
                               pass:= pass + button;
                               write('*');
                               i:=i+1;
                          end;
                     j:=j+1;
                     end;
                end;
                writeln;

                guessDigit[dc] := 1;
                guess := passlibrary[1];

                for i:=dc-1 downto 1 do
                begin
                     guessDigit[i] := 1;
                     guess:= guess + passlibrary[1];
                end;


                trials:=1;
                //Timer start
                timeStart := now;
                while pass <> guess do
                begin
                     trials:= trials + 1;
                     guessDigit[1] := guessDigit[1] + 1;
                     //writeln('guessdigit1 ' , guessDigit[1]);
                     for i:=1 to dc do
                     begin
                          if guessDigit[i] > maxValueDigit then
                          begin
                               guessDigit[i+1] := guessDigit[i+1] + 1;
                               guessDigit[i]:= guessDigit[i] div maxValueDigit;
                          end;
                     end;
                     //writeln('dc' , dc);
                     guess := passlibrary[guessDigit[dc]];
                     for i:=dc-1 downto 1 do
                         guess:= guess + passlibrary[guessDigit[i]];

                     //writeln('Denenen= ', guess);
                 end;

                 timeStop := now;

                 //Timer stop

                 //time := timeStart - timeStop;



                 writeln('Your password: ',guess);
                 writeln('Trials took to crack your password: ', trials);
                 decodeTime(timeStart,hour,min,sec,ms);
                 decodeTime(timeStop,s_hour,s_min,s_sec,s_ms);
                 writeln('Time took to crack your password: ', s_hour - hour,':',s_min - min,':',s_sec - sec,':',s_ms-ms);
           end;
     end
     else
         writeln('You have entered a invalid digit count.');



     readln;
     readln;
     readln;

END.

