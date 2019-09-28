close all
figure()
colormap(gray);
load mandrill;
[U,S,V] = svd(X);
for i = 1:6
    r = 2.^i;
    subplot(3,2,i), image(U(:,1:r)*S(1:r,1:r)*V(:,1:r)');
end

figure()
colormap(gray);
load durer;
[U,S,V] = svd(X);
colormap(gray)

for i = 1:6
    r = 2.^i;
    subplot(3,2,i), image(U(:,1:r)*S(1:r,1:r)*V(:,1:r)');
end