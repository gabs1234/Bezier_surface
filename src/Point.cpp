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

Point Point::getBarycentric( Triangle trig ){
	Point lambda;

	lambda[0] = det(P-Trig[1],P-Trig[2])/det(Trig[0]-Trig[1],Trig[0]-Trig[2]);
	lambda[1] = det(P-Trig[2],P-Trig[0])/det(Trig[1]-Trig[2],Trig[1]-Trig[0]);
	lambda[2] = det(P-Trig[0],P-Trig[1])/det(Trig[2]-Trig[0],Trig[2]-Trig[1]);

	return lambda;
}

/* Operator overloads */
float Point::operator[](int n){
	try{
		if(n==0){return xP;}
		if(n==1){return yP;}
		else{throw string("erreur indice");}
	}
	catch( string const& chaine ){
		cerr << chaine << endl;
	}
}

bool Point::operator<(const Point& P) const {
	return distance() < P.distance();
}

bool Point::operator<(const float& scalar) const {
	for( int i = 0; i < 2; i++ ){
		if( (*this)[i] > scalar ){
			return false;
		}
	}
	return true;
}

bool Point::operator<(const float& scalar, const Point& rightPoint) const {
	for( int i = 0; i < 2; i++ ){
		if( rightPoint[i] > scalar ){
			return false;
		}
	}
	return true;
}


Point Point::operator+(Point B){
	Point C;
	C.xP = xP+B.xP;
	C.yP = yP+B.yP;
	return C;
}

Point Point::operator-(Point B){
	Point C;
	C.xP = xP-B.xP;
	C.yP = yP-B.yP;
	return C;
}
