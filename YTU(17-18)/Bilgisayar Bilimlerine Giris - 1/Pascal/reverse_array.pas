PROGRAM reverse_array;
VAR
   dizi,reversed_array : array [1..99] of integer;
   n,tmp,i:integer;
BEGIN
     writeln('HOW MANY ELEMENTS YOU WILL ENTER? ');  (* Ka� de�er girilece�ini soruyor*)
     readln(n);

     for i:=1 to n do                                    (* De�erleri tek tek al�yor*)
     begin
          writeln('Please enter the ',i,'. number:  ');
          readln(tmp);
          dizi[i]:=tmp;
     end;

     writeln('');                                 (*Girilen diziyi teyit i�in yazd�r�yor *)
     writeln('THE ARRAY THAT YOU JUST ENTERED');
     for i:=1 to n do
     begin
          write(dizi[i], ' ');
     end;

     for i:=1 to n do
     begin
          reversed_array[i] := dizi[(n-i+1)];
     end;







     (*                                              Dizinin s�rayla i. eleman�n� sondan i. eleman� ile yer de�i�tiriyor
                                                  Bu i�lem dizinin yar�s� kadar yap�l�yor.
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
