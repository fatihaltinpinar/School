PROGRAM invers;

VAR
   i,j,satir,sutun,n,k,y,x:integer;
   tmp:real;
   a,b:array [1..100 , 1..100] of real;
BEGIN
     writeln('kare matirisin satir sutun sayisi= ');
     readln(n);

     for i:=1 to n do
     begin
          for j:=1 to n do
          begin
               write('B', i ,',' , j, '= ' );
               readln(B[i,j]);
          end;
     end;

     for i:=1 to n do
     begin
          for j:=1 to n do
          begin
               A[i,j] := B[i,j];
               write(A[i,j]:2:0, ' ');
          end;
          writeln;
     end;

     for i:=n+1 to 2*n do
     begin
          A[i-n,i] := 1;
     end;

     writeln;
     for i:=1 to n do
     begin
          for j:=1 to 2*n do
          begin
               write(A[i,j]:2:1, ' ');
          end;
          writeln;
     end;

     for sutun:=1 to n do
     begin
          satir := sutun + 1;
          while (satir <= n) AND (A[sutun,sutun] = 0) do
          begin
               for i:=1 to 2*n do
               begin
                    tmp := A[sutun,i];
                    A[sutun,i]:=A[satir,i];
                    A[satir,i]:=tmp;
               end;
               satir := satir + 1;
          end;
          for i:=1 to 2*n do
          begin
               if i <> sutun then
               begin
                    A[sutun,i] := A[sutun,i] / A[sutun,sutun];
                    writeln;
     for k:=1 to n do
     begin
          for j:=1 to 2*n do
          begin
               write(A[k,j]:2:1, ' ');
          end;
          writeln;
     end;
               end;
          end;

          A[sutun,sutun] := 1;

          for i:=1 to n do
          begin
               tmp := A[i,sutun] / A[sutun,sutun];
               if i <> sutun then
               begin
                    for k:=1 to 2*n do
                    begin
                         A[i,k] := A[i,k] - A[sutun,k]*tmp;
                         writeln;
                         writeln('sifirlanan: ',i,' ',k);
     for y:=1 to n do
     begin
          for x:=1 to 2*n do
          begin
               write(A[y,x]:2:1, ' ');
          end;
          writeln;
     end;

                    end;
               end;
          end;


     end;
     writeln;
     for i:=1 to n do
     begin
          for j:=1 to 2*n do
          begin
               write(A[i,j]:2:1, ' ');
          end;
          writeln;
     end;




readln;
END.
