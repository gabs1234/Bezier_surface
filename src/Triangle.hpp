#pragma once

#include "Point.hpp"
#include <vector>

class Triangle {
private:
	// Unique Identifier for triangle
	int id;
	// List of vertices of triangle
	std::vector<Point> vertices;
	// List of vertex id's
	int vertex_id[3];
	// TODO: use this ?
	const float eps = 1e-6;

	// Finds the center of gravity of current triangle
	void getCOG();
	// Finds the three microTriangles of the current triangles
	void getMicroTriangles();

public:
	Triangle();
	Triangle(std::vector<Point> init_points);
	Triangle(std::vector<Point> init_points, int id);
	Triangle(std::vector<Point> init_points, int id, std::vector<int> vertex_ids);
	Triangle(Point p1, Point p2, Point p3);
	Triangle(Point p1, Point p2, Point p3, int id);
	Triangle(Point p1, Point p2, Point p3, int id, std::vector<int> vertex_ids);

	Point COG;
	std::vector<Triangle> micro_triangles;
	
	// Test if point is in global triangle
	bool containsPoint(Point& p);
	// find if of subtriangle
	Triangle findMicroTriangle(Point& p);

	int getId();
	int getVertexId(int index);
	std::vector<Point> getVertices();
	void print();

	Point operator [] (int n);
};
