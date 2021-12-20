#include "DataIO.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
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

	vector<Triangle> triangulation( triangulation_data.size() );

	for( auto triangle_id : triangulation_data ){
		for( int point_id : triangle_id ){
			
		}
	}

	return 0;
}
