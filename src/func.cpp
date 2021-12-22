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


float gfuncdx(float x1, float x2)
{
    return (-2) * x2 * x2 - 10 * x1 * x2 + 10 * x2;
}

float gfundy(float x1, float x2)
{
    return 3 * x2 * x2 - 4 * x1 * x2 - 5 * x1 * x1 + 10 * x1;
}
