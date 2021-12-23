
x = 0:0.1:3;
y = 0:0.1:3;
[X, Y] = meshgrid(x,y);
res = importdata('RES.dat')
mesh(X, Y, res);