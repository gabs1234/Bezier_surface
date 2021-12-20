#include "Point.hpp"
#include "Triangle.hpp"

#include <assert.h>

/* Constructors */
Triangle::Triangle(std::vector<Point> init_points, int id) : id(id){
	assert( init_points.size() == 3 );
}

Triangle::Triangle(Point p1, Point p2, Point p3, int id) : id(id){
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;
}

/* Public member functions */
Triangle::isInTriangle(Point& p){
	Point baryCoords = p.getBarycentric(vertices);

	for( auto xi : baryCoords ){
		if( 0 < xi && xi < 1 ){
			
		}
	}
}