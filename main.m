clear all;

# Load control points and make triangulation
raw_points = importdata("data/hctr.pts");
nb_lines = raw_points(1,1);
points = raw_points(2:nb_lines, :);

trig = delaunay(points);
save("data/hgtr.tri",  "trig" ) ;

#figure(1)
#triplot(trig, points(:,1), points(:, 2))

# Make mesh grid
xmin = min(points(:,1));
xmax = max(points(:,1));
ymin = min(points(:,2));
ymax = max(points(:,2));

x_points = 19;
y_points = 19;
h_x = abs(xmax - xmin)/x_points;
h_y = abs(ymax - ymin)/y_points;

x = xmin:h_x:xmax;
y = ymin:h_y:ymax;

[X, Y] = meshgrid(x,y);

save "data/X.msh"  "X"  -ascii;
save "data/Y.msh" "Y"  -ascii;

# Run c++ program

# Import solution
res = importdata('data/TEST.dat');
size(X)
size(Y)
size(res)

res_sol = exp(X + Y);

figure(2)
subplot(1, 3, 1);
surf(X, Y, res_sol);
subplot(1, 3, 2);
surf(X, Y, res);
scatter3(points);
subplot(1, 3, 3);
surf(X, Y, res-res_sol);
