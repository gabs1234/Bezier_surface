#include "DataIO.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Triangulation.hpp"
#include "Coef.hpp"
#include "Func.hpp"
#include <cmath>

#include <iostream>

using namespace std;


int main(int argc, char const *argv[]) {
	// Load initial control point data that we wish to interpolate
	auto control_points = readData<float>("../data/hctr.pts", 2);
	// Load triangulation data
	auto triangulation_data = readData<int>("../data/hctr.tri", 32, 3);
	
	// Convert triangulation data to an array of triangle objects
	vector<Triangle> triangulation = toTriangles(triangulation_data, control_points);

	int lines = 20, columns = 20;
	// load meshgrid
	auto X = readData<float>("../data/X.msh",lines,columns);
	auto Y = readData<float>("../data/Y.msh",lines,columns);

	// Get list of values of function
	vector<float> f_points = evaluateFunction(f, control_points);
	vector<float> dxf_points = evaluateFunction(dxf, control_points);
	vector<float> dyf_points = evaluateFunction(dyf, control_points);

	
	vector<vector<float>> res( lines , std::vector<float> (columns));
	
	int id;
	
	int cur_id = 0;
	int next_id;

	Coefficients coef; 
	vector<float> lambda(3);
	
	for( int i = 0; i < lines; i++ ){
		for( int j = 0; j < columns; j++ ){
			Point P(X[i][j], Y[i][j]);

			Triangle macro_triangle = findTriangle(P, triangulation);
			Triangle micro_triangle = macro_triangle.findMicroTriangle(P);
			next_id = macro_triangle.getId();

			// check if we are still in the same triangle 
			if( next_id != cur_id ){
				calcCoefficient(macro_triangle, f_points, dxf_points, dyf_points, coef);
			}

			lambda = P.getBarycentric(micro_triangle);
			id = micro_triangle.getId();

			res[i][j] = computeInterpolation(id, lambda, coef);
			cur_id = next_id;
		}
	}

	writeData(res, "../data/TEST.dat");
}
