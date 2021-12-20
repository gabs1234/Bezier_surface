#include "Triangulation.hpp"

using namespace std;

int prev_trig_id = 0;

vector<Triangle> toTriangles(vector<vector<int>> triangulation_data, vector<vector<float>> control_points){
	vector<Triangle> triangulation;
	int id = 0;

	for( auto triangle_id : triangulation_data ){
		vector<Point> tmp_trig;

		for( int point_id : triangle_id ){
			Point tmp_point( control_points[point_id-1] );
			tmp_trig.push_back(tmp_point);
		}

		Triangle tmp(tmp_trig, id);
		triangulation.push_back( tmp );
		id++;
	}

	return triangulation;
}

int findTriangle(Point p, vector<Triangle> triangulation){
	for( auto triangle : triangulation ){
		if( triangle.containsPoint(p) ){
			return triangle.getId();
		}
	}
	// error not found
	cerr << "error not found" << endl;
	return -1;
}

int findTriangle(float x, float y, vector<Triangle> triangulation){
	Point p(x, y);
	cout << "number of triangles: " << triangulation.size() << endl;
	for( auto triangle : triangulation ){
		if( triangle.containsPoint(p) ){
			return triangle.getId();
		}
	}
	// error not found
	cerr << "error not found" << endl;
	return -1;
}

int findTriangle(vector<float> vecP, vector<Triangle> triangulation){
	Point p(vecP);
	for( auto triangle : triangulation ){
		if( triangle.containsPoint(p) ){
			return triangle.getId();
		}
	}
	// error not found
	cerr << "error not found" << endl;
	return -1;
}