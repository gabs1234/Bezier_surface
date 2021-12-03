#include "data.hpp"
#include <iostream>

using namespace std;
/*
TODO:

	for each grid point:
		convert into barycentric points according to macro-triangle
		if in triangle: find center of mass, and calculate coefficients of the 3 sub triangles

HELLLO MOTHERFUCKER
*/

int main(int argc, char const *argv[]) {
	// Load initial control points that we wish to interpolate
	DATA<float> control_points("data/hctr.pts", 2);
	// Load triangulation
	DATA<int> triangulation("data/hctr.tri", 32, 3);

	control_points.print();
	triangulation.print();

	return 0;
}
