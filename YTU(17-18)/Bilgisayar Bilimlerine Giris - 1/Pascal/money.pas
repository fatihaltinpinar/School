PROGRAM money;
VAR
   x,remain,thundred,hundred,fifty,twenty,ten,five:integer;
BEGIN
     writeln('Please enter amount of the cash:  ');
     readln(x);

     thundred := x div 200;
     remain := x mod 200;

     hundred := remain div 100;
     remain := remain mod 100;

     fifty := remain div 50;
     remain := remain mod 50;

     twenty := remain div 20;
     remain := remain mod 20;

     ten := remain div 10;
     remain := remain mod 10;

     five := remain div 5;
     remain := remain mod 5;

     writeln(thundred,' x 200TL');
     writeln(hundred,' x 100TL');
     writeln(fifty,' x 50TL');
     writeln(twenty,' x 20TL');
     writeln(ten,' x 10TL');
     writeln(five,' x 5TL');
     writeln(remain,' x 1TL');

     writeln('');
     writeln('Press ENTER to close the program.');
     readln();
END.
