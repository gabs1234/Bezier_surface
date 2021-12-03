#include "point.h"
#include <iostream>
using namespace std;

float det(Point A, Point B)
{
	// return det(A,B)
	return A[0]*B[1]-A[1]*B[0];
}

vector<float> barycentric_coord(Point P, vector<Point>& Trig){
	// return point P's barycentrics coordinates on triangle (Trig[0] Trig[1] Trig[2])
	
	vector<float> lambda(3);
	
	lambda[0] = det(P-Trig[1],P-Trig[2])/det(Trig[0]-Trig[1],Trig[0]-Trig[2]);
	lambda[1] = det(P-Trig[2],P-Trig[0])/det(Trig[1]-Trig[2],Trig[1]-Trig[0]);
	lambda[2] = det(P-Trig[0],P-Trig[1])/det(Trig[2]-Trig[0],Trig[2]-Trig[1]);
	
	return lambda;
	
}

int test_triangle(Point P, vector<Point>& Trig){
	//test if point P is on the triangle Trig 
	// 1 : in the triangle 
	// 0 : not in the triangle
	vector<float> lambda = barycentric_coord(P,Trig);
	int t = 0
	for(int i = 0; i<3;i++){
		if(lambda[i]>0 && lambda[i] < 1){t = 1;}
		else{t = 0;}
	}
	return t;
}
