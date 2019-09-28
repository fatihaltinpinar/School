Program dedeler;
uses DateUtils,SysUtils;
Var
   fromtime,totime:TDateTime;
   difference:integer;

begin
     fromtime:=now;
     for i:=1 to 100 do
     begin
          writeln('slq');
     end;

     totime:=now;

     DiffMinutes := MinutesBetween(toTime,fromTime);
end.
