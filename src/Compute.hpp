#pragma once

#include "Point.hpp"
#include "Triangle.hpp"
#include <vector>
#include <algorithm>

#include <cmath>

struct Coefficients {
	float a[3];
	float p[3];
	float q[3];
	float b[3];
	float c[3];
	float d[3];
	float e[3];
	float u[3];
	float g[3];
};

typedef float (*func)(Point);

void calcCoefficient(Triangle& triangle, std::vector<float> f, std::vector<float> dxf, std::vector<float> dyf, Coefficients& coef);
float computeInterpolation(int id, std::vector<float> lambda, Coefficients coef);
std::vector<float> evaluateFunction(func f, std::vector<std::vector<float>> control_points);
std::vector<std::vector<float>> getSol(func f, std::vector<std::vector<float>> X, std::vector<std::vector<float>> Y);
float getMin(std::vector<std::vector<float>> sol);
float getMax(std::vector<std::vector<float>> sol);