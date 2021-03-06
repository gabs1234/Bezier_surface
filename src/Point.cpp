#include "Point.hpp"

#include <assert.h> // pour assert (necessaire avec certains compilateurs)
#include <iostream>

using namespace std;

/* Constructors */
Point::Point():xP(0), yP(0){}
Point::Point(float x, float y):xP(x), yP(y){}
Point::Point(float x, float y, int id):xP(x), yP(y), id(id){}
Point::Point(vector<float> point):xP(point[0]), yP(point[1]){}
Point::Point(vector<float> point, int id):xP(point[0]), yP(point[1]), id(id){}


/* Private member functions */
float Point::det(Point A, Point B) const {
	return A[0]*B[1]-A[1]*B[0];
}

/* Public member functions */
vector<float> Point::getBarycentric( vector<Point> points){
	vector<float> lambda(3);

	// // This solution is more efficient
	// lambda[0] = ((A2[1] - A3[1])*(xP - A3[0]) + (A3[0] - A2[0])*(yP - A3[1]))/d;
	// lambda[1] = ((A3[1] - A1[1])*(xP - A3[0]) + (A1[0] - A3[0])*(yP - A3[1]))/d;
	// lambda[2] = 1 - lambda[0] - lambda[1];

	int j, k;

	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
        k = (j + 1) % 3;
		Point Ai = points[i];
		Point Aj = points[j];
		Point Ak = points[k];

		lambda[i] = det( Ak - Aj, (*this) - Aj )/det( Ak - Aj, Ai - Aj );
	}

	return lambda;
}
int Point::getId() const {
	return id;
}
void Point::print(void) const {
	cout << "x=\t" << xP << ", \t y=\t" << yP << endl;
}


/* Operator overloads */
float Point::operator[](int n){
	if(n==0){return xP;}
	if(n==1){return yP;}
	else{
		cout << "hello" << endl;
		throw string("erreur indice");}
}
Point Point::operator+(Point& B){
	Point C;
	C.xP = xP+B.xP;
	C.yP = yP+B.yP;
	return C;
}
Point Point::operator-(Point& B){
	Point C;
	C.xP = xP-B.xP;
	C.yP = yP-B.yP;
	return C;
}
float Point::operator*(Point& B){
	return xP * B.xP + yP * B.yP;
}
Point Point::operator/(float C){
	Point D;
	D.xP = xP/C;
	D.yP = yP/C;
	return D;
}

