clear all;

# Load control points and make triangulation
raw_points = importdata("data/hctr.pts");
nb_lines = raw_points(1,1);
points = raw_points(2:nb_lines, :);

trig = delaunay(points);
save("data/hgtr.tri",  "trig" ) ;

figure(1)
triplot(trig, points(:,1), points(:, 2))

# Make mesh grid
xmin = min(points(:,1));
xmax = max(points(:,1));
ymin = min(points(:,2));
ymax = max(points(:,2));

h = 0.1;

x = xmin:h:xmax;
y = ymin:h:ymax;

[X, Y] = meshgrid(x,y);

save "data/X.msh"  "X"  -ascii;
save "data/Y.msh" "Y"  -ascii;

# Run c++ program
# TODO

# Import solution
res = importdata('data/RES.dat');

figure(2)
mesh(X, Y, res);
