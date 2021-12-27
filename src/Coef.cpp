#include "Coef.hpp"
#include <iostream>

using namespace std;

void calcCoefficient(Triangle& triangle, vector<float> f, vector<float> dxf, vector<float> dyf, Coefficients& coef){
	int j, k;

	Point COG = triangle.getCOG();

	// a
	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
		k = (i + 2) % 3;
		Point Aj = triangle[j];
		coef.a[j] = f[Aj.id];
	}
	
	// p
	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
		k = (i + 2) % 3;
		Point Aj = triangle[j];
		Point Ak = triangle[k];
		Point Ajk = Ak - Aj;
		Point dAj(dxf[Aj.id], dyf[Aj.id]);

		coef.p[j] = dAj*Ajk;
	}
	
	// q 
	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
		k = (i + 2) % 3;
		Point Aj = triangle[j];
		Point Ak = triangle[k];
		Point Akj = Aj - Ak;
		Point dAk(dxf[Ak.id], dyf[Ak.id]);

		coef.q[k] = dAk*Akj;
	}
	
	// b 
	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
		k = (i + 2) % 3;
		coef.b[j] = (coef.a[j] + coef.p[j]) /3.0;
	}
	
	// c 
	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
		k = (i + 2) % 3;
		coef.c[k] = (coef.a[k] +  coef.q[k]) /3.0;
	}
	
	// d
	for( int i = 0; i < 3; i++ ){
		j = (i + 1) % 3;
		k = (i + 2) % 3;
		coef.d[k] = (coef.a[k] + coef.b[k] + coef.c[k]) /3.0;
	}
	
	// u
	for( int i = 0; i < 3; i++ ){
		j = (i+1)%3;
		k = (i+2)%3;

		Point Aj = triangle[j];
		Point Ak = triangle[k];

		Point Ajk = Ak - Aj;
		Point Awk = Ak - COG;

		coef.u[i] = 2*( Awk*Ajk )/( Ajk*Ajk );
	}
	
	// g
	for( int i = 0; i < 3; i++ ){
		j = (i+1)%3;
		k = (i+2)%3;

		coef.g[i] = ( 2*(coef.d[k] + coef.d[j]) + (4-3*coef.u[i])*coef.c[k] + (coef.u[i] - 2)*coef.a[k]
		+ (3*coef.u[i] - 2)*coef.b[j] - coef.u[i]*coef.a[j] )/4;
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

    float S = coef.a[k]*lambda[2]*lambda[2]*lambda[2] + coef.a[j]*lambda[1]*lambda[1]*lambda[1] +
               coef.b[j]*3*lambda[1]*lambda[1]*lambda[2] + coef.c[k]*3*lambda[1]*lambda[2]*lambda[2] +
               coef.d[j]*3*lambda[0]*lambda[1]*lambda[1] + coef.d[k]*3*lambda[0]*lambda[2]*lambda[2] +
               coef.e[j]*3*lambda[0]*lambda[0]*lambda[1] + coef.e[k]*3*lambda[0]*lambda[0]*lambda[2] +
               coef.g[i]*6*lambda[0]*lambda[1]*lambda[2] + w*lambda[0]*lambda[0]*lambda[0];
    return S;
}

vector<float> evaluateFunction(func f, vector<vector<float>> control_points){
	vector<float> list;

	for( auto point : control_points ){
		list.push_back( f(point) );
	}

	cout << list.size() << endl;

	return list;
}
