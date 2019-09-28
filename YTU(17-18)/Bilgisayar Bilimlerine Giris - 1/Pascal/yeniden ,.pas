PROGRAM hocanin_derste_soledigi;

VAR

   i,k,n,oldmax,newmax:integer;
   A,B: array [1..100] of integer;

BEGIN
     writeln('Kac elemanli bir dizi istiyorsunuz? ');
     readln(n);

     for i:=1 to n do
     begin
          write(i , '. degeri gir= ');
          (*A[i] := random(n) + 1;*)
          readln(A[i]);
     end;

     for i:=1 to n do
     begin
          (*A[i] := random(n) + 1;*)
          write(A[i], ' ');
     end;
     writeln;


     k:=1;
     i:=2;
     oldmax:=0;
     newmax:=1;

     if n > 1 then
     begin
        while(i <= n) do
          begin
               while A[i] = A[i-1] do
               begin
                     newmax := newmax + 1;
                     if newmax > oldmax then
                     begin
                          oldmax := newmax;
                          k:= 1;
                          B[k]:= A[i-1];
                          end
                          else
                          if newmax = oldmax then
                             begin
                             k := k + 1;
                             B[k] := A[i-1];
                             end;
                     i:= i + 1;
               end;

               i:= i + 1;

               newmax := 1;

          end;
   end;

   writeln;

   if oldmax > 1 then
   begin
        for i:=1 to (k-1) do
        begin
             write(B[i], ', ');
        end;
        write(B[k], ' - ', oldmax , ' defa tekrar etmis');
        writeln;

   end
   else if oldmax <= 1 then
   begin
       for i:=1 to (n-1) do
        begin
             write(A[i], ', ');
        end;
        write(A[n], ' - ', 1 , ' defa tekrar etmis');
        writeln;

   end;


   readln;
END.
