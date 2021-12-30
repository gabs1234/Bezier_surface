#pragma once

#include "Triangle.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


// Read
template <class T>
std::vector< std::vector <T> > readData(const std::string filename, int cols);
template <class T>
std::vector< std::vector <T> > readData(std::string filename, int cols, int rows);

// Write
template <class T>
void writeData(std::vector< std::vector <T> > data, std::string fileName);

// Utilities
template <class T>
void printData(std::vector< std::vector <T> > data);

void makeRES(std::vector<Triangle> triangulation, 
			 std::vector<std::vector<float>> control_points, 
			 std::vector<float> f_points, 
			 std::vector<float> dxf_points, 
			 std::vector<float> dyf_points,
			 std::vector<std::vector<float>> res,
			 std::vector<std::vector<float>> res_sol,
			 std::string fileName);