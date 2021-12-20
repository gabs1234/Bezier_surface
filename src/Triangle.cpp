#include "Triangle.hpp"

#include <cmath>    // pour sqrt
#include <assert.h> // pour assert (necessaire avec certains compilateurs)
#include <iostream>

#include <assert.h>

using namespace std;

/* Constructors */
Triangle::Triangle(vector<Point> init_points, int id) : id(id), vertices(3), w(3){
	assert( init_points.size() == 3 );
}

Triangle::Triangle(Point p1, Point p2, Point p3, int id) : id(id), vertices(3), w(3){
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;

}

/* Public member functions */
bool Triangle::containsPoint(Point& p){
	vector<float> baryCoords = p.getBarycentric( (*this) );

	for( auto xi : baryCoords ){
		if( (0 > xi) || (xi > 1) ){
			return false;
		}
	}
	return true;
}

/* Operator overloads */
Point Triangle::operator[](int n){

	if(n==0){return vertices[0];}
	else if(n==1){return vertices[1];}
	else if(n==2){return vertices[2];}
	else{throw string("erreur indice");}

}