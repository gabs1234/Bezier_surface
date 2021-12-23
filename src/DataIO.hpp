#pragma once
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
