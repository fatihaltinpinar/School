function q4
    
    function x_trun = trunc(x, n)
        x_trun = x - rem(x,10^-n);
    end

    function result = fppo(x0, h)
    result = (sin(x0 + h) - 2 * sin(x0) + sin(x0 - h)) / h.^2;
    end

    function error = total_error(x0, h)
    error = abs(-sin(x0) - fppo(x0, h)) + abs(fppo(x0, h) - trunc(fppo(x0, h), 10));
    % error = abs(fppo(x0, h) - trunc(fppo(x0, h), 8));
    
    end
    
    x0 = 1.2;
    error = [];
    for k = 0:0.5:8
        error = [error, total_error(x0, 10.^-k)];
    end
    k = 0:0.5:8;
    loglog(10.^-k, error);
end