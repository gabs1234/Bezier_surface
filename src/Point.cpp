#include "Point.hpp"

#include <cmath>    // pour sqrt
#include <assert.h> // pour assert (necessaire avec certains compilateurs)
#include <iostream>

using namespace std;

/* Constructors */
Point::Point():xP(0), yP(0){assert(ok());}

Point::Point(float x, float y){
	xP=x; yP=y;
	assert(ok());
}

/* Private member functions */
float Point::det(Point A, Point B){
	// returns det(A,B)
	return A[0]*B[1]-A[1]*B[0];
}

/* Public member functions */
void Point::print(void) const {
	cout << "x=\t" << xP << ", \t y=\t" << yP << endl;
}

void Point::translate(float x, float y) {
	xP+=x; yP+=y;
	assert( ok() );
}

bool Point::ok(){
	return xP>=0. && yP>=0.;
}


vector<float> Point::getBarycentric( Triangle Trig ){
	vector<float> lambda(3);

	Point t_P0 = Trig[0], t_P1 = Trig[1], t_P2 = Trig[2];

	lambda[0] = det((*this)-t_P1, (*this)-t_P2)/det(t_P0-t_P1, t_P0-t_P2);
	lambda[1] = det((*this)-t_P2, (*this)-t_P0)/det(t_P1-t_P2, t_P1-t_P0);
	lambda[2] = det((*this)-t_P0, (*this)-t_P1)/det(t_P2-t_P0, t_P2-t_P1);

	return lambda;
}

/* Operator overloads */
float Point::operator[](int n){
	if(n==0){return xP;}
	if(n==1){return yP;}
	else{throw string("erreur indice");}
}

bool Point::operator<(const Point& P) const {
	return 0;
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
