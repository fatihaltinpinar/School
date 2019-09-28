PROGRAM reverse_array;
VAR
   dizi,reversed_array : array [1..99] of integer;
   n,tmp,i:integer;
BEGIN
     writeln('HOW MANY ELEMENTS YOU WILL ENTER? ');  (* Kaç deðer girileceðini soruyor*)
     readln(n);

     for i:=1 to n do                                    (* Deðerleri tek tek alýyor*)
     begin
          writeln('Please enter the ',i,'. number:  ');
          readln(tmp);
          dizi[i]:=tmp;
     end;

     writeln('');                                 (*Girilen diziyi teyit için yazdýrýyor *)
     writeln('THE ARRAY THAT YOU JUST ENTERED');
     for i:=1 to n do
     begin
          write(dizi[i], ' ');
     end;

     for i:=1 to n do
     begin
          reversed_array[i] := dizi[(n-i+1)];
     end;







     (*                                              Dizinin sýrayla i. elemanýný sondan i. elemaný ile yer deðiþtiriyor
                                                  Bu iþlem dizinin yarýsý kadar yapýlýyor.
     for i:=1 to (n div 2) do
     begin
          tmp := dizi[i];
          dizi[i] := dizi[(n - i + 1)];
          dizi[(n - i +1)] := tmp;
     end;
             *)
     writeln(' ');
     writeln('');
     writeln('THE ARRAY THAT HAS BEEN REVERSED');
     for i:=1 to n do
     begin
          write(reversed_array[i],   ' ' );
          (*write(dizi[i], ' ');  *)
     end;

     writeln(' ');
     writeln(' ');
     writeln('PRESS ENTER TO CLOSE THE PROGRAM...');
     readln();
END.
