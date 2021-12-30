#include "DataIO.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Triangulation.hpp"
#include "Compute.hpp"
#include "Func.hpp"
#include <cmath>

#include <iostream>

using namespace std;

float TestFunction(Point p){
	// SET FUNCTION HERE
	return f(p);
}

float dxTestFunction(Point p){
	// SET dx FUNCTION HERE
	return f(p);
}

float dyTestFunction(Point p){
	// SET dy FUNCTION HERE
	return f(p);
}


int main(int argc, char const *argv[]) {
	// Load initial control point data that we wish to interpolate
	auto control_points = readData<float>("../data/hctr.pts", 2);
	// Load triangulation data
	auto triangulation_data = readData<int>("../data/hctr.tri", 32, 3);

	// Convert triangulation data to an array of triangle objects
	vector<Triangle> triangulation = toTriangles(triangulation_data, control_points);

	// load meshgrid
	int lines = 20, columns = 20;
	auto X = readData<float>("../data/X.msh",lines,columns);
	auto Y = readData<float>("../data/Y.msh",lines,columns);

	// Get list of values of function
	vector<float> f_points =   evaluateFunction(TestFunction, control_points);
	vector<float> dxf_points = evaluateFunction(dxTestFunction, control_points);
	vector<float> dyf_points = evaluateFunction(dyTestFunction, control_points);
	
	vector<vector<float>> res( lines , vector<float> (columns));
	
	int micro_id = 0;
	int cur_id = 0;
	int next_id = 0;
	Coefficients coef; 
	vector<float> lambda(3);
	
	for( int i = 0; i < lines; i++ ){
		for( int j = 0; j < columns; j++ ){		
			Point P(X[i][j], Y[i][j]);
			// Find triangle in triangulation that contains P
			Triangle macro_triangle = findTriangle(P, triangulation);
			// Find micro triangle of macro_triangle that contains P
			Triangle micro_triangle = macro_triangle.findMicroTriangle(P);

			// check if we are still in the same triangle 
			next_id = macro_triangle.getId();
			if( next_id != cur_id ){
				calcCoefficient(macro_triangle, f_points, dxf_points, dyf_points, coef);
			}

			// Get barycentric coords of P in micro triangle
			lambda = P.getBarycentric(micro_triangle.getVertices());
			micro_id = micro_triangle.getId();

			// Compute interpolation
			res[i][j] = computeInterpolation(micro_id, lambda, coef);
			cur_id = next_id;
		}
	}

	vector<vector<float>> res_sol = getSol(TestFunction, X, Y);

	writeData(res, "../data/TEST.dat");
	makeRES(triangulation, control_points, f_points, dxf_points, dyf_points, res, res_sol, "../data/HCT.res");
}
