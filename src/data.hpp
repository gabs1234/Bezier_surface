#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

template <class T>
class DATA{
private:
    std::ifstream data_points;
    int rows;
    const int columns;
	T** data;

public:
    // Constructors
	DATA(std::string filename, const int columns);
	DATA(std::string filename, const int rows, const int columns);

    // Utilities
    void print();
};