#include "DataIO.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Triangulation.hpp"
#include "Coef.hpp"

#include <cmath>

#include <iostream>

using namespace std;


float f(Point P){
	return exp(P[0]+P[1]);	
}

float dxf(Point P){
	return exp(P[0]+P[1]);	
}

float dyf(Point P){
	return exp(P[0]+P[1]);	
}

int main(int argc, char const *argv[]) {
	// Load initial control point data that we wish to interpolate
	auto control_points = readData<float>("../data/hctr.pts", 2);
	// Load triangulation data
	auto triangulation_data = readData<int>("../data/hctr.tri", 32, 3);

	// Convert triangulation data to an array of triangle objects
	vector<Triangle> triangulation = toTriangles(triangulation_data, control_points);

	int lines = 31, columns = 31;
	// load meshgrid
	auto X = readData<float>("../data/X.msh",lines,columns);
	auto Y = readData<float>("../data/X.msh",lines,columns);
	
	vector<vector<float>> res( lines , std::vector<float> (columns));
	
	int id;

	Coefficients coef; 
	vector<float> lambda(3);
	
	for( int i = 0; i < 31; i++ ){
		for( int j = 0; j < 31; j++ ){
			Point P(X[i][j], Y[i][j]);

			Triangle macro_triangle = findTriangle(P, triangulation);
			Triangle micro_triangle = macro_triangle.findMicroTriangle(P);

			calcCoefficient(macro_triangle, coef, f, dxf, dyf);

			lambda = P.getBarycentric(micro_triangle);
			id = micro_triangle.getId();

			res[i][j] = computeInterpolation(id, lambda, coef);
		}
	}

	writeData(res, "RES.dat");
}
