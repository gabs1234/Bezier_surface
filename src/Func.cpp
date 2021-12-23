#include "Func.hpp"

float f(Point P){
	return exp(P[0]+P[1]);	
}

float dxf(Point P){
	return exp(P[0]+P[1]);	
}

float dyf(Point P){
	return exp(P[0]+P[1]);	
}

float g(Point P){
	return P[1]*P[1]*P[1]-2*P[1]*P[1]*P[0]-5*P[1]*P[0]*P[0]+10*P[1]*P[0]+1;
}

float dxg(Point P){
	return (-2)*P[1]*P[1] - 10*P[0]*P[1] + 10*P[1];
}

float dyg(Point P){
	return 3*P[1]*P[1] - 4*P[0]*P[1] - 5*P[0]*P[0] + 10*P[0];
}