#pragma once

class Triangle;

#include "Point.hpp"
#include <vector>

class Triangle {
private:
	const int id;
	int edges[3];
	std::vector<Point> vertices;
	std::vector<float> w;

	Triangle micro_triangle[3];

public:
	Triangle(std::vector< Point > init_points, int id);
	Triangle(Point p1, Point p2, Point p3, int id);

	// Test if point is in global triangle
	bool containsPoint( Point& p );
	// find subtriangle
	int getSubTriangle( Point& p, int number);

	int getId();
	void print();

	Point operator [] (int n);
};
