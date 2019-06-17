function hw2q1()

% for part 1a
% returnsvalue of f(x)
f = @(x) 2*cosh(x/4) - x;

% returns the value of f'(x)
fd = @(x) (sinh(x/4))/2 - 1;

% for part 1b
    function y = f2e(x)
        if(x ~= 0)
            y = sin(x) / x;
        else
            y = 1;
        end
    end

    function y = f2de(x)
        if (x ~= 0)
            y = (cos(x)*x - sin(x))/x^2;
        else
            y = 0;
        end
    end

f2 = @(x) f2e(x);
f2d = @(x) f2de(x);

    % Function that checks for every interval
    function findroots(f, fd, a, b, nprobe, tol)
        delta = (b - a) / nprobe;
        for n = a:delta:b
            % If the function changes sign in given interval
            % newton function is called
            if ((f(n) * f(n+delta)) < 0) 
                x = (newton(n, n+delta, f, fd, tol)); % Finding roots and
                disp(x);
                % Displaying them.
            end
        end
    end
   
    % Newton method that takes input as a,b interval function and it's
    % derivative, and a tolerance value.
    function x = newton(a, b, f, fd, tol)
        xk = a - f(a)/fd(a);
        xk0 = a;
        while(abs(xk - xk0) >= tol*(1 + abs(xk)) || abs(f(xk)) >= tol)
            xk0 = xk;
            xk = xk0 - f(xk0)/fd(xk0);
            
            if( abs(f(xk)) >= 0.5*abs(f(xk0)))
                % If this statement is satisfied we have to reduce the
                % interval. This is done by applyning bisection method to
                % the given interval over 3 times. Function returns the new
                % interval that newton method will be searching on.
                [a, b] = bisection(a, b, f);
                xk = a;             
            end
        
        end
        x = xk;
    end

    function [a, b] = bisection(a, b, f)
        for i = 0:1:2
            xk = (b-a) / 2;
            if (f(xk) * f(a) <= 0)
                b = xk;
            elseif (f(xk) * f(b) < 0)
                a = xk;
            end
        end
    end
findroots(f, fd, 0, 10, 10, 10^-7);
findroots(f2, f2d, -10, 10, 20, 10^-7)
end