#include "Triangle.hpp"

#include <cmath>    // pour sqrt
#include <assert.h> // pour assert (necessaire avec certains compilateurs)
#include <iostream>

#include <assert.h>

using namespace std;

/* Constructors */
Triangle::Triangle(vector<Point> init_points, int id) : id(id), vertices(init_points){
	assert( init_points.size() == 3 );
}

Triangle::Triangle(Point p1, Point p2, Point p3, int id) : id(id), vertices(3){
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;	
}

/* Public member functions */
Point Triangle::getCOG(){
	Point COG;
	for( auto point : vertices ){
		COG = COG + point;
	}
	return COG/3;
}
vector<Triangle> Triangle::getMicroTriangles(){
	Point COG = getCOG();
	vector<Triangle> mic_triangles;

	int j, k;

	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
        k = (i + 2) % 3;
		Triangle MicroTriangle(COG, vertices[j], vertices[k], i);
		mic_triangles.push_back(MicroTriangle);
    }

	return mic_triangles;
}

bool Triangle::containsPoint(Point& p){
	vector<float> baryCoords = p.getBarycentric( (*this) );

	for( auto xi : baryCoords ){
		if( (0 > xi) || (xi > 1) ){
			return false;
		}
	}
	return true;
}

Triangle Triangle::findMicroTriangle(Point& p){
	vector<Triangle> mic_triangles = getMicroTriangles();

	for( auto triangle : mic_triangles ){
		if( triangle.containsPoint(p) ){
			return triangle;
		}
	}
	// TMP
	return mic_triangles[0];
}

int Triangle::getId(){
	return id;
}

void Triangle::print(){
	cout << "[ " << endl;
	for( auto point : vertices ){
		point.print();
	}
	cout << "]" << endl;
}

/* Operator overloads */
Point Triangle::operator[](int n){

	if(n==0){return vertices[0];}
	else if(n==1){return vertices[1];}
	else if(n==2){return vertices[2];}
	else{throw string("erreur indice");}

}