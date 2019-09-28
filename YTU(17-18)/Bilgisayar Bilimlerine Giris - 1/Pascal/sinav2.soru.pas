PROGRAM ikincisoru;

VAR

   y,i,t,n,tmax:integer;
   A:array [1..100] of integer;

BEGIN
     write('Kac elemanli bir dizi istiyorsunuz? ');
     read(n);

     for i:=1 to n do
     begin
          write('A[' , i , ']');
          readln(A[i]);

     end;

     for i:=1 to n do
     begin
          write('A[',i,'] = ', A[i], ' ');

     end;
     writeln;

     t:=1;
     tmax:=1;


     for i:=2 to n do
     begin
          writeln('i=',i);
          writeln('n=',n);
          writeln('t=',t);
          writeln('tmax=',tmax);
          if A[i-1] = A[i] then
          begin
               t := t + 1;
               writeln('if icindeki t=',t);
               writeln('A(', i-1, ')  = A (', i,')');
          end else if t > tmax then
          begin
               writeln('t > tmax cikti ', t, tmax);
               tmax := t;
               y:=i-t;
               t:=1;
          end else
              t:=1;

     end;

     if t > tmax then
     begin
          tmax := t;
          y:=n - t + 1;
     end;

     writeln(y);
     writeln(A[y], 'sayisi ', y, ' den baslayarak ', tmax , 'defa tekrar etmis');
     readln;
END.
