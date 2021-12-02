/* TODO:
 - Exception handling
*/

#include "data.hpp"

using namespace std;

template <class T>
DATA<T>::DATA(string filename, int columns):columns(columns){
    data_points.open(filename);
    if( !data_points.is_open() ){
		cout << "could not open file";
        throw 1;
	}

    stringstream buffer;
    buffer << data_points.rdbuf();
    data_points.close();
    
    buffer >> rows; // Read number of rows

	data = new T*[rows];

    // Fill in data matrix using string stream buffer
	for( int row_i = 0; row_i < rows; row_i++ ){
        data[row_i] = new T[columns];
		for( int col_i = 0; col_i < columns; col_i++ ){
            buffer >> data[row_i][col_i];
		}
	}    
}

template <class T>
DATA<T>::DATA(string filename, int rows, int columns):rows(rows), columns(columns), data(new T*[rows]){
    data_points.open(filename);
    if( !data_points.is_open() ){
		cout << "could not open file";
	}

    stringstream buffer;
    buffer << data_points.rdbuf();
    data_points.close();

    // Fill in data matrix using string stream buffer
	for( int row_i = 0; row_i < rows; row_i++ ){
        data[row_i] = new T[columns];
		for( int col_i = 0; col_i < columns; col_i++ ){
            buffer >> data[row_i][col_i];
		}
	}
}

template <class T>
void DATA<T>::print(){
    for( int i = 0; i < rows; i++ ){
        for( int j = 0; j < columns; j++ ){
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}
template class DATA<float>;
template class DATA<int>;
