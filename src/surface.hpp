#pragma once
#include <string>
#include <fstream>
#include <iostream>

template <class T>
class DATA{
private:
	T* data;
public:
	DATA(string filename);
	DATA(string filename, int rows, int columns):data(new T[rows][columns]);
	
};

template <class T>
T* load_points(std::string filename, int columns){
	std::ifstream points;
	points.open(filename);

	if( !points.is_open() ){
		std::cout << "could not open file";
		return 0.0;
	}

	std::string buffString; points >> buffString;
	int rows = std::stoi(buffString);

	new[] point_data

	for( int row_i = 0; row_i < rows; row_i++ ){
		for( int col_i = 0; col_i < columns; col_i++ ){
			points >> buffString;
			std::cout << buffString << std::endl;
		}
	}

	while ( points.good() ) {

	}

	return 5.0;
}
