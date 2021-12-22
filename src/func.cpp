#include "Point.hpp"
#include <cmath>    
#include <assert.h> 
#include <iostream>

float ffunc(Point P){
	{
	return exp(P[0]+P[1]);	
	}
}

float ffunxdx(Point P){
	return exp(P[0]+P[1]);	
}

float ffuncdy(Point P){
	return exp(P[0]+P[1]);	
}

float gfunc(Point P){
	return P[1]*P[1]*P[1]-2*P[1]*P[1]*P[0]-5*P[1]*P[0]*P[0]+10*P[1]*P[0]+1;
}
