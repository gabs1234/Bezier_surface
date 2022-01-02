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
	return g(p);
}

float dxTestFunction(Point p){
	// SET dx FUNCTION HERE
	return dxg(p);
}

float dyTestFunction(Point p){
	// SET dy FUNCTION HERE
	return dyg(p);
}


int main(int argc, char const *argv[]) {
	if( argc != 4 ){
		cerr << "usage: main nb_triangles nx_mesh ny_mesh" << endl;
		return 1;
	}
	int nb_triangles = stoi(argv[1]);
	int columns = stoi(argv[2]);
	int lines = stoi(argv[3]);
	
	// Input filenames
	string ctrl_points = "data/hctr.pts";
	string triangle_points = "data/hctr.tri";
	string X_mesh = "data/X.msh";
	string Y_mesh = "data/Y.msh";

	// Output filenames
	string htc_res = "data/HCT.res";
	string plot_res = "data/plot_res.dat";
	string plot_res_sol = "data/plot_res_sol.dat";


	// Load initial control point data that we wish to interpolate
	auto control_points = readData<float>(ctrl_points, 2);
	// Load triangulation data
	auto triangulation_data = readData<int>(triangle_points, nb_triangles, 3);

	// Convert triangulation data to an array of triangle objects
	vector<Triangle> triangulation = toTriangles(triangulation_data, control_points);

	// load meshgrid
	auto X = readData<float>(X_mesh,lines,columns);
	auto Y = readData<float>(Y_mesh,lines,columns);

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
	
	for( int j = 0; j < columns; j++ ){
		for( int i = 0; i < lines; i++ ){
	
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

	// Write interpolation result to file
	writeData(res, plot_res);
	// Write exact solution to file
	writeData(res_sol, plot_res_sol);
	makeRES(triangulation, control_points, f_points, dxf_points, dyf_points, res, res_sol, htc_res);
}
