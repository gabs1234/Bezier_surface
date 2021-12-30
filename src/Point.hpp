#pragma once

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

	// return barycentric coordinates according to trig
	std::vector<float> getBarycentric( std::vector<Point> points);

	int getId() const;
	void print() const;

	// Operator overloads
	float operator [] (int n);
	Point operator - (Point& B);
	Point operator + (Point& B);
	float operator * (Point& B);
	Point operator / (float C);
};

