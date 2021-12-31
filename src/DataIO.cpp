#include "DataIO.hpp"
#include "Point.hpp"
#include "Compute.hpp"

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
void writeData(vector<vector <T>> data, std::string fileName){
	ofstream data_file(fileName);
	
	try {
		for( auto line : data ){
			for( auto val : line ){
				data_file << val << " ";
			}
			data_file << endl;
		}
	}
	catch( std::ofstream::failure e ){
		cerr << "Exception writing file" << endl;
	}

	data_file.close();
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

template void  writeData<float>(vector<vector<float>> data, std::string fileName);
template void  writeData<int>(vector<vector<int>>data, std::string fileName);


// Utilities instantiations
template void printData<float>(std::vector< std::vector <float> > data);
template void printData<int>(std::vector< std::vector <int> > data);

void makeRES(vector<Triangle> triangulation, 
			 vector<vector<float>> control_points, 
			 vector<float> f_points, 
			 vector<float> dxf_points, 
			 vector<float> dyf_points,
			 vector<vector<float>> res,
			 vector<vector<float>> res_sol,
			 string fileName)
{
	ofstream data_file(fileName);

	try{
	// Print triangle info
	for( auto triangle : triangulation ){
		data_file << triangle.getId() << "\t";
		for( int i = 0; i < 3; i++ ){
			data_file << triangle[i].getId() << "\t";
		}
		data_file << endl;
	}

	// Print Point info
	for( int i = 0; i < control_points.size(); i++ ){
		data_file << i << "\t";
		data_file << control_points[i][0] << "  ";
		data_file << control_points[i][1] << "\t";
		data_file << f_points[i] << "  ";
		data_file << dxf_points[i] << "  ";
		data_file << dyf_points[i] << endl;
	}

	// Process error
	int l = res.size(), c = res[0].size();
	vector<vector<float>> err( l, vector<float>(c) );
	for( int i = 0; i < l; i++ ){
		for( int j = 0; j < c; j++ ){
			err[i][j] = res_sol[i][j] - res[i][j];
		}
	}

	// Print min and max of error
	float min = getMin(err);
	float max = getMax(err);
	data_file << min << "\t" << max << endl;
	}
	catch( std::ofstream::failure e ){
		cerr << "Exception writing HCT.res file" << endl;
	}
	
}