clear all;

# Load control points and make triangulation
raw_points = importdata("data/hctr.pts");
nb_lines = raw_points(1,1)+1;
points = raw_points(2:nb_lines, :)

trig = delaunay(points);
dlmwrite ("data/hctr.tri", trig, "delimiter", " ", "newline", "\n")

figure(1)
triplot(trig, points(:,1), points(:, 2))

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
command = sprintf("./launch.sh %d %d %d", size(trig)(1),  x_points+1, y_points+1)
system(command);

# Import solution
res = importdata('data/plot.dat');

# Evaluate exact solution
res_sol = exp(X + Y);


# Plot results
figure(2)
subplot(1, 3, 1);
surf(X, Y, res_sol);
subplot(1, 3, 2);
surf(X, Y, res);
subplot(1, 3, 3);
surf(X, Y, res-res_sol);
