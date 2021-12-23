#pragma once

class Point;

#include "Triangle.hpp"
#include <vector>

class Point {
private:
	float xP, yP;
	float det(Point A, Point B);
	
public:
	Point();
	Point(float x, float y);
	Point(std::vector<float> point);

	void print() const;
	void translate(float x, float y);
	bool ok();

	// return barycentric coordinates according to trig
	std::vector<float> getBarycentric( Triangle trig );

	// Operator overloads
	float operator [] (int n);
    bool operator < (const Point& P) const;
	Point operator - (Point& B);
	Point operator + (Point& B);
	float operator * (Point& B);
	Point operator / (float C);
};

