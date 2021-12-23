#include "Triangulation.hpp"

using namespace std;

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

Triangle findTriangle(Point p, vector<Triangle> triangulation){
	for( auto triangle : triangulation ){
		if( triangle.containsPoint(p) ){
				return triangle;
		}
	}
	throw("error: triangle not found");
}

Triangle findTriangle(float x, float y, vector<Triangle> triangulation){
	Point p(x, y);
	for( auto triangle : triangulation ){
		if( triangle.containsPoint(p) ){
			return triangle;
		}
	}
	throw("error: triangle not found");
}

Triangle findTriangle(vector<float> vecP, vector<Triangle> triangulation){
	Point p(vecP);
	for( auto triangle : triangulation ){
		if( triangle.containsPoint(p) ){
			return triangle;
		}
	}
	throw("error: triangle not found");
}
