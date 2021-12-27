#include "Point.hpp"

#include <cmath>    // pour sqrt
#include <assert.h> // pour assert (necessaire avec certains compilateurs)
#include <iostream>

using namespace std;

/* Constructors */
Point::Point():xP(0), yP(0){}

Point::Point(float x, float y){
	xP=x; yP=y;
}

Point::Point(vector<float> point){
	xP=point[0]; yP=point[1];
}

/* Private member functions */
float Point::det(Point A, Point B){
	return A[0]*B[1]-A[1]*B[0];
}

/* Public member functions */
void Point::print(void) const {
	cout << "x=\t" << xP << ", \t y=\t" << yP << endl;
}

void Point::translate(float x, float y) {
	xP+=x; yP+=y;
}


vector<float> Point::getBarycentric( Triangle Trig ){
	vector<float> lambda(3);


	// lambda[0] = ((A2[1] - A3[1])*(xP - A3[0]) + (A3[0] - A2[0])*(yP - A3[1]))/d;
	// lambda[1] = ((A3[1] - A1[1])*(xP - A3[0]) + (A1[0] - A3[0])*(yP - A3[1]))/d;
	// lambda[2] = 1 - lambda[0] - lambda[1];

	int j, k;

	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
        k = (j + 1) % 3;
		Point Ai = Trig[i];
		Point Aj = Trig[j];
		Point Ak = Trig[k];

		lambda[i] = det( Ak - Aj, (*this) - Aj )/det( Ak - Aj, Ai - Aj );
	}

	return lambda;
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

