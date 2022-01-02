clear all;
clf;

# Load control points and make triangulation
raw_points = importdata("data/hctr.pts");
nb_lines = raw_points(1,1)+1;
points = raw_points(2:nb_lines, :)

trig = delaunay(points);
dlmwrite ("data/hctr.tri", trig, "delimiter", " ", "newline", "\n");

figure(1)
triplot(trig, points(:,1), points(:, 2))

# Make mesh grid
xmin = min(points(:,1));
xmax = max(points(:,1));
ymin = min(points(:,2));
ymax = max(points(:,2));

x_res = 49 ;
y_res = 99;
h_x = abs(xmax - xmin)/x_res;
h_y = abs(ymax - ymin)/y_res;

x = xmin:h_x:xmax;
y = ymin:h_y:ymax;

[X, Y] = meshgrid(x,y);

save "data/X.msh"  "X"  -ascii;
save "data/Y.msh" "Y"  -ascii;

# Run c++ program
command = sprintf("./launch.sh %d %d %d", size(trig)(1),  x_res+1, y_res+1)
system(command);

# Import solution
res = importdata('data/plot_res.dat');
res_sol = importdata('data/plot_res_sol.dat');

# Plot results
figure(2)
subplot(1, 3, 1);
surf(X, Y, res_sol);
title("Exact solution");
xlabel("x");
ylabel("y");
zlabel("res sol");

subplot(1, 3, 2);
mesh(X, Y, res);
title("Computed interpolation");
xlabel("x");
ylabel("y");
zlabel("res");

subplot(1, 3, 3);
surf(X, Y, res_sol - res);
title("Error");
xlabel("x");
ylabel("y");
zlabel("res sol - res");

# Save figures
print(1,"-S2000,900", "triangulation.png");
print(2,"-S2000,900", "surface2.png");
