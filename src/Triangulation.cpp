#include "Triangulation.hpp"

using namespace std;

vector<Triangle> toTriangles(vector<vector<int>> triangulation_data, vector<vector<float>> control_points){
	vector<Triangle> triangulation;
	int trig_id = 0;
	int point_id = 0;

	for( auto vertex_id : triangulation_data ){
		vector<Point> tmp_trig(3);

		for( int i = 0; i < 3; i++ ){
			point_id = vertex_id[i] - 1;
			Point tmp_point( control_points[point_id], point_id );
			tmp_trig[i] = tmp_point;
		}

		Triangle trig = Triangle(tmp_trig, trig_id, vertex_id);
		triangulation.push_back(trig);
		trig_id++;
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
