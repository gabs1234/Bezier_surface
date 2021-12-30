#include "Triangle.hpp"

#include <assert.h> // pour assert (necessaire avec certains compilateurs)
#include <iostream>

using namespace std;

/* Constructors */
Triangle::Triangle(vector<Point> init_points):vertices(init_points){
	assert( init_points.size() == 3 );

	getCOG();	
}
Triangle::Triangle(vector<Point> init_points, int id) : vertices(init_points), id(id){
	assert( init_points.size() == 3 );
	getCOG();
}
Triangle::Triangle(vector<Point> init_points, int id, vector<int> vertex_ids) : vertices(init_points), id(id){
	assert( init_points.size() == 3 );
	for( int i = 0; i < 3; i++ ){
		vertex_id[i] = vertex_ids[i]-1;
	}
	getCOG();
}
Triangle::Triangle(Point p1, Point p2, Point p3) : vertices(3){
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;
	getCOG();
}
Triangle::Triangle(Point p1, Point p2, Point p3, int id) : vertices(3), id(id){
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;
	getCOG();
}
Triangle::Triangle(Point p1, Point p2, Point p3, int id, vector<int> vertex_ids) : vertices(3), id(id){
	vertices[0] = p1;
	vertices[1] = p2;
	vertices[2] = p3;
	for( int i = 0; i < 3; i++ ){
		vertex_id[i] = vertex_ids[i];
	}
	getCOG();
}

/* Private member functions */
void Triangle::getCOG(){
	for( auto point : vertices ){
		COG = COG + point;
	}
	COG = COG/3;
}
void Triangle::getMicroTriangles(){
	int j, k;

	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
        k = (i + 2) % 3;
		Triangle micro_triangle(COG, vertices[j], vertices[k], i);
		micro_triangles.push_back(micro_triangle);
    }
}

/* Public member functions */
bool Triangle::containsPoint(Point& p){
	vector<float> baryCoords = p.getBarycentric( vertices );

	for( auto xi : baryCoords ){
		if( (-eps > xi) || (xi > 1) ){
			return false;
		}
	}

	return true;
}
Triangle Triangle::findMicroTriangle(Point& p){
	// Finds the three microTriangles of the current triangles
	getMicroTriangles();
	for( auto triangle : micro_triangles ){
		if( triangle.containsPoint(p) ){
			return triangle;
		}
	}
	// temp
	throw("Error: micro triangle not found!");
}
int Triangle::getId(){
	return id;
}
vector<Point> Triangle::getVertices(){
	return vertices;
}
int Triangle::getVertexId(int index){
	return vertex_id[index];
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
	assert( (0 <= n) && (n < 3) );
	return vertices[n];
}