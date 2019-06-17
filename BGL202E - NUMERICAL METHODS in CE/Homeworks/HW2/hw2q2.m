function hw2q2()
    function x = solve_tridiagonal(n, lower_d, d, upper_d, b)
        
        % Gaussian elemination
        upper_d(n) = 0;
        for i = 1:n-1    
            k = lower_d(i)/d(i);
            d(i+1) = d(i+1) - upper_d(i)*k;
            b(i+1) = b(i+1) - b(i)*k;
            lower_d(i) = 0;
        end
        
        % Finding x[n];
        x(n) = b(n)/d(n);
        
        % Backward substitution
        for i = n-1:-1:1
            x(i) = (b(i) - x(i+1) * upper_d(i))/d(i);
        end
    end
    
    % Inputs
    n = 10;
    lower_d = [-1;-2;-3;-4;-5;-6;-7;-8;-9];
    d = [3;6;9;12;15;18;21;24;27;30];
    upper_d = [-2;-3;-4;-5;-6;-7;-8;-9;-10];
    % Chosen b
    b = [1;2;3;4;5;6;7;8;9;10];
    % Displaying result
    x = (solve_tridiagonal(n, lower_d, d, upper_d, b));
    disp(x);
end