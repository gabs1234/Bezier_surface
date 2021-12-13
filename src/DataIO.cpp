/* TODO:
 - Exception handling
*/

#include "DataIO.hpp"

using namespace std;

template <class T>
vector< vector <T> > readData(const string filename, int cols){
    ifstream data_file;
    data_file.exceptions( std::ifstream::failbit | std::ifstream::badbit );
    
    vector< vector <T> > data;
    try {
        data_file.open(filename);

        int rows = 0;
        data_file >> rows;
        
        vector<T> row(cols);

        for( int irow = 0; irow < rows; irow++ ){
            for( int icol = 0; icol < cols; icol++ ){
                data_file >> row[icol];
            }
            data.push_back(row);
        }
    }
    catch( std::ifstream::failure e ){
        cerr << "Exception opening/reading file" << endl;
    }

    data_file.close();
    return data;
}

template <class T>
vector< vector <T> > readData(const string filename, int rows, int cols){
    ifstream data_file;
    data_file.exceptions( std::ifstream::failbit | std::ifstream::badbit );
    
    vector< vector <T> > data(rows);
    try {
        data_file.open(filename);
        
        vector<T> row(cols);

        for( int irow = 0; irow < rows; irow++ ){
            for( int icol = 0; icol < cols; icol++ ){
                data_file >> row[icol];
            }
            data[irow] = row;
        }
    }
    catch( std::ifstream::failure e ){
        cerr << "Exception opening/reading file" << endl;
    }

    data_file.close();
    return data;
}

template <class T>
void printData(std::vector< std::vector <T> > data){
    for( auto row : data ){
        for( auto val : row ){
            cout << val << "\t";
        }
        cout << endl;
    }
}

// IO functions instantiations
template vector< vector <float> > readData<float>(const string filename, int cols);
template vector< vector <int> > readData<int>(const string filename, int cols);

template vector< vector <float> > readData<float>(const string filename, int cols, int rows);
template vector< vector <int> > readData<int>(const string filename, int cols, int rows);


// Utilities instantiations
template void printData<float>(std::vector< std::vector <float> > data);
template void printData<int>(std::vector< std::vector <int> > data);

