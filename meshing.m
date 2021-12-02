points = load("hctr.pts")

trig = delaunay(points)

triplot(trig, points(:,1), points(:, 2))

save("hgtr.tri",  "trig" )