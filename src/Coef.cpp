#include "Coef.hpp"
#include <iostream>

using namespace std;

void calcCoefficient(Triangle& triangle, Coefficients& coef, func f, func dxf, func dyf){
	int j, k;

	Point COG = triangle.getCOG();

	// a
	for( int i = 0; i < 3; i++ ){
		Point Ai = triangle[i];
		coef.a[i] = f(Ai);
	}
	
	// p
	for( int j = 0; j < 3; j++ ){
		k = (j + 1) % 3;
		Point Aj = triangle[j];
		Point Ak = triangle[k];
		coef.p[j] = dxf(Aj)*(Ak[0] - Aj[0]) + dyf(Aj)*(Ak[1] - Aj[1]);
	}
	
	// q 
	for( int j = 0; j < 3; j++ ){
		k = (j + 1) % 3;
		Point Ak = triangle[k];
		Point Aj = triangle[j];
		coef.q[k] = dxf(Ak)*(Aj[0] - Ak[0]) + dyf(Aj)*(Aj[1] - Ak[1]);
	}
	
	// b 
	for( int i = 0; i < 3; i++ ){
		coef.b[i] = (coef.a[i] + coef.p[i]) /3;
	}
	
	// c 
	for( int i = 0; i < 3; i++ ){
		coef.c[i] = (coef.a[i] +  coef.q[i]) /3;
	}
	
	// d
	for( int i = 0; i < 3; i++ ){
		coef.d[i] = (coef.a[i] + coef.b[i] + coef.c[i]) /3;
	}
	
	// u
	for( int i = 0; i < 3; i++ ){
		j = (i+1)%3;
		k = (i+2)%3;

		Point Aj = triangle[j];
		Point Ak = triangle[k];

		Point Ajk = Ak - Aj;
		Point AkW = COG - Ak;

		coef.u[i] = 2*( AkW*Ajk )/(Ajk*Ajk);
	}
	
	// g
	for( int i = 0; i < 3; i++ ){
		j = (i+1)%3;
		k = (i+2)%3;

		coef.g[i] = ( 2*(coef.d[k] + coef.d[j]) + (4-3*coef.u[i])*coef.c[k] + (coef.u[i] - 2)*coef.a[k]
		+ (3*coef.u[i] - 2)*coef.b[j] - coef.u[i]*coef.a[j] ) / 4;
	}	
	
	// e
	for( int i = 0; i < 3; i++ ){
		j = (i+1)%3;
		k = (i+2)%3;
		coef.e[k] = (coef.d[k] + coef.g[i] + coef.g[j])/3;
	}
		
}
		
		
float computeInterpolation(int id, vector<float> lambda, Coefficients coef){
    float w = (coef.e[0] + coef.e[1] + coef.e[2]) / 3;

    int i = id;
    int j = (i + 1) % 3;
    int k = (i + 2) % 3;

    float S =  coef.a[k] * lambda[2] * lambda[2] * lambda[2] + coef.a[j] * lambda[1] * lambda[1] * lambda[1] +
               coef.b[j] * 3 * lambda[1] * lambda[1] * lambda[2] + coef.c[k] * 3 * lambda[1] * lambda[2] * lambda[2] +
               coef.d[j] * 3 * lambda[0] * lambda[1] * lambda[1] + coef.d[k] * 3 * lambda[0] * lambda[2] * lambda[2] +
               coef.e[j] * 3 * lambda[0] * lambda[0] * lambda[1] + coef.e[k] * 3 * lambda[0] * lambda[0] * lambda[2] +
               coef.g[i] * 6 * lambda[0] * lambda[1] * lambda[2] + w * lambda[0] * lambda[0] * lambda[0];
    return S;
}
