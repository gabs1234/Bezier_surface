#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "Point.hpp"
#include <vector>

class Triangle {
private:
	const int id;
	std::vector<point> vertices(3);
	std::vector<float> COG;

public:
	Triangle(std::vector< std::vector<float> > init_points, int id);
	Triangle(std::vector<float> p1, std::vector<float> p2, std::vector<float> p3, int id);

	// Test if point is in global triangle
	bool isInTriangle( std::vector<float>& p );
	// find subtriangle
	int getSubTriangle( std::vector<float>& p, int number );
}

#endif