program inverse_of_matrix;

var
  i,j,n,sira,k:integer;
  temp:real;
  a,b,c:array [1..100,1..100] of real;

begin
  //user input
  write('Kare matrisin satir(sutun) sayisi: ');
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      write('A(',i,')(',j,'): ');
      readln(a[i,j]);
    end;
  end;

  //I(n) matrisi olusturma
  for i:=1 to n do
  begin
      c[i,i]:=1;
  end;

  //IxI'nin 0 olmasi durumunda kontrol
  for i:=1 to n do
  begin
    if a[i,i]=0 then
    begin
      for j:=1 to i-1 do
      begin
        if a[j,i]<>0 then
        begin
          for k:=1 to n do
          begin
            a[i,k]:=a[i,k]+a[j,k];
          end;
        end;
      end;
    end;
  end;

  //A'yi B'ye kopyala
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      b[i,j]:=a[i,j];
    end;
  end;

  //indirgenmis forma getirme
  for sira:=1 to n do
  begin
    for i:=sira to n do
    begin
      for j:=1 to n do
      begin
        b[i,j]:= a[i,j] / a[i,sira];
      end;
        //surasi flowcharttan az farkli bura uzerinde oynamak gerekiyo
        for j:=1 to n do
        begin
          b[j,i]:=b[j,i]-b[j,sira]*b[sira,sira];
        end;
    end;
  end;

  //ciktilar...
  writeln;
  writeln('A Matrisi: ');
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      write(a[i,j]:0:3,'  ');
    end;
    writeln;
  end;
  writeln;
  writeln('A Matrisinin Indirgenmis Esolon Formu: ');
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      write(b[i,j]:0:3,'  ');
    end;
    writeln;
  end;
  writeln;
  writeln('A Matrisinin Inversi: ');
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      write(c[i,j]:0:3,'  ');
    end;
    writeln;
  end;
  readln;
end.
