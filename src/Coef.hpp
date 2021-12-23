#pragma once

#include "Point.hpp"
#include "Triangle.hpp"
#include <vector>

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

void calcCoefficient(Triangle& triangle, Coefficients& coef, func f, func dxf, func dyf);
float computeInterpolation(int id, std::vector<float> lambda, Coefficients coef);