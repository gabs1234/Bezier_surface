#include "Point.hpp"
#include "Triangle.hpp"
#include <vector>
#include <assert.h>
#include <array>
void coefs(Triangle triangle, float *a, float *b, float *c, float *d, float *e, float *p, float *q, float *g, float *u, float *f, float *dxf, float *dyf)
{
/*
triangle : triangle where we determine the coefficients a, b, c, d, e
with p, q that interpolate the function f;
*/


	int j, k;
	int ci, cj, ck ; // edge j
	vector<float[3]> coefs; 
	for(int i = 0; i < 3; i++) // a_i ------------------------------------------------------
		{
		ci = triangle.edges(i)-1; // faire fonction membre de la classe triangle pour accéder aux edges 
		a[i] = f[triangle.edges[ci]];
		}
		
	for(int j = 0; j < 3; j++) // p --------------------------------------------------------
		{
		ck = (j + 1) % 3;
		cj = triangle.edges(j) - 1;
		p[j] = dxf[cj] * (triangle.points[k][0] - triangle.point[j][0] + dyf[cj] * (triangle.point[k][1] - triangle.point[j][1]);
		}
	
	for(int i = 0; i < 3; i++) // q --------------------------------------------------------
		{
		j = (i+1)%3;
		k = (i+2)%3;
		ck = triangle.edges(k)-1;
		q[k] = dx[ck] * (triangle.points[j][0] - triangle.points[k][0])
		     + dyf[ck] * (triangle.points[j][1] - triangle.points[k][1]);
		}
	
	for(int i = 0; i < 3; i++) // b --------------------------------------------------------
		{
		b[i] = (a[i] + p[i]) /3;
		}
	
	for(int i = 0; i < 3; i++) // c --------------------------------------------------------
		{
		c[i] = (a[i] + q[i]) /3;
		}
	
	for(int i = 0; i < 3; i++) //d ---------------------------------------------------------
		{
		d[i] = (a[i] + b[i] + c[i]) /3
		}
		
	for(int i = 0; i < 3; i++) // u ---------------------------------------------------------
		{
		j = (i+1)%3;
		k = (i+2)%3;
		
		u[i] = 2*
		((triangle.points[k][0] - triangle.w[0]) * (triangle.points[k][0] - triangle.points[j][0])+
		(triangle.points[k][1] - triangle.w[1]) * (triangle.points[k][1] - triangle.points[j][1]))/
		((triangle.points[k][0] - triangle.points[j][0]) * (triangle.points[k][0] - triangle.points[j][0])+
		(triangle.points[k][1] - triangle.points[j][1]) * (triangle.points[k][1] - triangle.points[j][1]));

		}
		
	for(int i = 0; i < 3; i++) // g ---------------------------------------------------------
		{
		j = (i+1)%3;
		k = (i+2)%3;
		g[i] = (2 * (d[k] + d[j]) + (4-3*u[i]*c[k] + u[i] - 2) * a[k]
		+ (3*u[i] - 2) * b[j] - u[i] * a[j]) / 4;
		}	
	
	for(int i = 0; i < 3; i++) // e ---------------------------------------------------------
		{
		j = (i+1)%3;
		k = (i+2)%3;
		e[k] = (d[k] + g[i] + g[j])/3;
		}
		
}
		
		
double computeInterpolation(int id, vector<float> lambda, float *a, float *b, float *c, float *d, float *e, float *p, float *q, float *g, float *u)
{
    double w = (e[0] + e[1] + e[2]) / 3;

    int i = id;
    int j = (i + 1) % 3;
    int k = (i + 2) % 3;

    double S = a[k] * lambda[2] * lambda[2] * lambda[2] + a[j] * lambda[1] * lambda[1] * lambda[1] +
               b[j] * 3 * lambda[1] * lambda[1] * lambda[2] + c[k] * 3 * lambda[1] * lambda[2] * lambda[2] +
               d[j] * 3 * lambda[0] * lambda[1] * lambda[1] + d[k] * 3 * lambda[0] * lambda[2] * lambda[2] +
               e[j] * 3 * lambda[0] * lambda[0] * lambda[1] + e[k] * 3 * lambda[0] * lambda[0] * lambda[2] +
               g[i] * 6 * lambda[0] * lambda[1] * lambda[2] + w * lambda[0] * lambda[0] * lambda[0];
    return S;
}
