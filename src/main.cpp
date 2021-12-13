#include "DataIO.hpp"
#include <iostream>

using namespace std;
/*
TODO:

	for each grid point:
		convert into barycentric points according to macro-triangle
		if in triangle: find center of mass, and calculate coefficients of the 3 sub triangles

*/

int main(int argc, char const *argv[]) {
	// Load initial control points that we wish to interpolate
	auto control_points = readData<float>("../data/hctr.pts", 2);
	// Load triangulation
	auto triangulation = readData<int>("../data/hctr.tri", 32, 3);

	printData<float>(control_points);
	printData<int>(triangulation);


	return 0;
}
