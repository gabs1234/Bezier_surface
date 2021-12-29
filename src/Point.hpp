#pragma once

class Point;

#include "Triangle.hpp"
#include <vector>

class Point {
private:
	// Point coordinates
	float xP, yP;
	// Unique point id
	int id;
	// Calculate determinant of matrix [A B]
	float det(Point A, Point B) const;
	
public:
	
	Point();
	Point(float x, float y);
	Point(float x, float y, int id);
	Point(std::vector<float> point);
	Point(std::vector<float> point, int id);

	void print() const;

	// return barycentric coordinates according to trig
	std::vector<float> getBarycentric( Triangle trig );

	// Operator overloads
	float operator [] (int n);
	Point operator - (Point& B);
	Point operator + (Point& B);
	float operator * (Point& B);
	Point operator / (float C);
};

