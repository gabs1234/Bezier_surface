#ifndef _POINT_
#define _POINT_

#include "Triangle.hpp"

class Point {
private:
	float xP, yP;
	float det(Point A, Point B);
	
public:
	Point();
	Point(float x, float y);
	void print() const;
	void translate(float x, float y);
	bool ok();
	float distance() const;

	// return barycentric coordinates according to trig
	Point getBarycentric( Triangle trig );

	// Operator overloads
	float operator [] (int n);
    bool operator < (const Point&) const;
	Point operator - (Point&);
	Point operator + (Point&);

};

#endif
