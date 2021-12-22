#include "DataIO.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Triangulation.hpp"
#include <iostream>

using namespace std;
/*
TODO:

for each grid point:
	convert into barycentric points according to macro-triangle
	if in triangle: find center of mass, and calculate coefficients of the 3 sub triangles

*/

int main(int argc, char const *argv[]) {
	// Load initial control point data that we wish to interpolate
	auto control_points = readData<float>("../data/hctr.pts", 2);
	// Load triangulation data
	auto triangulation_data = readData<int>("../data/hctr.tri", 32, 3);
	
	// Convert triangulation data to an array of triangle objects
	vector<Triangle> triangulation = toTriangles(triangulation_data, control_points);

	int triangle_id = findTriangle(1, .6, triangulation);
	
	// load meshgrid
	
	auto X = readData<float>("../data/X.msh",31,31); // 
	auto Y = readData<float>("../data/X.msh",31,31); // 
	
	// initiate variables 
	
	int id // as the triangle's id
	triangle id_triangle. 
	// coef
	
	float a[3], b[3], c[3], d[3], e[3];
	
	// functions 
	float p,q; // /!\ to define 
	float f,g , dfx, dyf;
	
	for(int i = 0; i < 31; i ++)
		{
		for(int j = 0; j < 31; j++)
			{
			Point P(X[i][j],Y[i][j]);
			id = findTriangle(P, triangulation)
			}
		}
}
