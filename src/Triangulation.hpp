#pragma once

#include "Triangle.hpp"
#include "Point.hpp"
#include <vector>
#include <iostream>

std::vector<Triangle> toTriangles(std::vector<std::vector<int>> triangulation_data, std::vector<std::vector<float>> control_points);
// Finds triangle in triangulation that contains p
int findTriangle(Point p, std::vector<Triangle> triangulation);
int findTriangle(float x, float y, std::vector<Triangle> triangulation);
int findTriangle(std::vector<float> vecP, std::vector<Triangle> triangulation);