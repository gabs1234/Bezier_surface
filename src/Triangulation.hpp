#pragma once

#include "Triangle.hpp"
#include "Point.hpp"
#include <vector>
#include <iostream>

std::vector<Triangle> toTriangles(std::vector<std::vector<int>> triangulation_data, std::vector<std::vector<float>> control_points);
// Finds triangle in triangulation that contains p
Triangle findTriangle(Point p, std::vector<Triangle> triangulation);
Triangle findTriangle(float x, float y, std::vector<Triangle> triangulation);
Triangle findTriangle(std::vector<float> vecP, std::vector<Triangle> triangulation);
