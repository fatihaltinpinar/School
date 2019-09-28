function hw1q4()
x = 1.92:0.001:2.08;

figure();
plot(x,f1(x));
title('Graph of expanded form of f(x)=(x-2)^9');
xlabel('x');
ylabel('f(x)');

figure();
plot(x,f2(x));
title('Graph of f(x)=(x-2)^9');
xlabel('x');
ylabel('f(x)');

function y = f1(x)
% This function returns %y = x^9 - 18*x^8 + 144*x^7 - 627*x^6 + 2016*x^5 - 4032*x^4 + 5376*x^3 - 4608x^2 + 2304*x - 512
y = x.^9 - 18*x.^8 + 144*x.^7 - 672*x.^6 + 2016*x.^5 ... 
    - 4032*x.^4 + 5376*x.^3 - 4608*x.^2 + 2304*x - 512;
end

function y = f2(x)%This function returns 
% y = (x-2)^9
y = (x-2).^9;
end
end