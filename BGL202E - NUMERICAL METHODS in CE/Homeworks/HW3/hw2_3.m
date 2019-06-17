function hw2_3()

function vk = power_method(inputMatrix, initialGuess, iterationCount)
    vk = initialGuess;
    for i = 1:iterationCount
        tmp = inputMatrix * vk;
        vk = tmp / norm(tmp);
        disp(-vk);
    end
end
A = [-2 1 4; 1 1 1; 4 1 -2];
v0 = [1; 2; -1];
vt = [1; 2; 1];
power_method(A,v0,20);
power_method(A,vt,5);
end