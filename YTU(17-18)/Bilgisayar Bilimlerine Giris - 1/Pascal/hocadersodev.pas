PROGRAM hocaodev;

VAR

   i,k,max,n,yenimax:integer;
   A: array [1..100] of integer;
   B: array [1..100] of integer;

BEGIN
   writeln('Kac elementli bir dizi istiyorsunuz? ');
   readln(n);

   for i:=1 to n do
   begin
        write(i , '. degeri gir');
        (*A[i] := random(n) + 1;*)
        readln(A[i]);

   end;

   for i:=1 to n do
   begin
        (*A[i] := random(n) + 1;*)
        write(A[i], ' ');
   end;

   writeln;

   i:=2;
   k:=1;
   max:=0;
   yenimax:=1;

   while i <= n do
   begin
        while A[i] = A[(i-1)] do
        begin
             i := i + 1;
             yenimax := yenimax + 1;
        end;

        if yenimax > max then
        begin
             k := 1;
             B[k] := A[i-1];
             max := yenimax;
        end
        else if yenimax = max then
        begin
             k:=k + 1;
             B[k] := A[i];
            (*write('Debug: ', B[k] ,' ',k ,' ', A[i]);
             write( ' ', A[i - 1]);
             writeln(); *)


        end;

        yenimax := 1;
        i := i + 1;

   end;

   writeln;

   for i:=1 to (k-1) do
   begin
        write(B[i], ', ');
   end;
   write(B[k], ' sayilari ', max , ' defa tekrar etmis');
   writeln;


END.
