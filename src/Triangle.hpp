#pragma once

class Triangle;

#include "Point.hpp"
#include <vector>

class Triangle {
private:
	const int id;
	int edges[3];
	std::vector<Point> vertices;

public:
	Triangle();
	Triangle(std::vector< Point > init_points, int id);
	Triangle(Point p1, Point p2, Point p3, int id);

	// Returns the center of gravity of current triangle
	Point getCOG();
	// Returns the three microTriangles of the current triangles
	std::vector<Triangle> getMicroTriangles();

	// Test if point is in global triangle
	bool containsPoint(Point& p);
	// find subtriangle
	Triangle findMicroTriangle(Point& p);

	int getId();
	void print();

	Point operator [] (int n);
};
