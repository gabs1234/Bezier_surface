cd 'C:\Users\sully\Documents\Uni\CAO'
P = load("hctr.pts");
P(1,:)= [];
DT = delaunayTriangulation(P);
triplot(DT)
triangulation = DT.ConnectivityList;
dlmwrite('trig.txt', triangulation);
x = 0:0.1:3;
y = 0:0.1:3;
msh = meshgrid(x,y);
dlmwrite('mesh.msh', msh);