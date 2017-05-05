#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include<vector>
#include <stdlib.h>
#include "TempSimulator.h"

#define filepath "C:\\Users\\ethan\\Desktop\\inputfile.txt"

using namespace std;

struct point
{
	float Temp;
	bool IS_static;
};


vector<vector<point>> initial(vector<vector<float>> temperatures, int X_dim, int Y_dim) {

	vector<vector<point>> initial_grid;

	initial_grid = vector<vector<point>>(X_dim, vector<point>(Y_dim));


	for (int r = 0; r < Y_dim; r++) {
		for (int c = 0; c < X_dim; c++) {
			point temp;
			if (r == 0 && c == 0) {
				temp.IS_static = true;
			}
			else {
				temp.IS_static = false;
			}
			temp.Temp = temperatures[r][c];		
			initial_grid[r][c] = temp;
		}
	}
	return initial_grid;
}


void temp_simulator(vector<vector<point>> grid, int X_dim, int Y_dim, int iteration, float multiplier) {

	for (int i = 0; i > iteration; i++) {
		for (int r = 0; r < Y_dim; r++) {
			for (int c = 0; c < X_dim; c++) {
				if (!grid[c][r].IS_static) {
					if ((c == 0 && r == 0) || (c == X_dim - 1 && r == Y_dim - 1) || (c == 0 && r == Y_dim - 1) || (c == Y_dim - 1 && r == 0)) {
						//corner formula
					}
					else if ((c == 0 && r < Y_dim) || (c == X_dim - 1 && r < Y_dim) || (c < X_dim - 1 && r == 0) || (c < X_dim - 1 && r == Y_dim - 1) {
						//edge formula
					}
					else {
						//middle formula
					}
				}

			}
		}
	}

}


vector<vector<float>> file_reader(int&X_dim, int&Y_dim, int&iterations, float&multiplier) {
	string line;
	int counter = 0;

	ifstream inputfile;
	inputfile.open(filepath);

	if (inputfile.is_open())
	{		
		
		string x_string, y_string, iter_string, multi_string;

		getline(inputfile, line);
		x_string = line;
		cout << x_string << endl;
		X_dim = stoi(x_string);

		getline(inputfile, line);
		y_string = line;
		cout << y_string << endl;
		Y_dim = stoi(y_string);

		getline(inputfile, line);
		iter_string = line;
		cout << iter_string << endl;
		iterations = stoi(iter_string);

		getline(inputfile, line);
		multi_string = line;
		cout << multi_string << endl;
		multiplier = stof(multi_string);

		vector<vector<float>> input_data = vector<vector<float>>(X_dim, vector<float>(Y_dim));

		for (int r = 0; r < X_dim; r++) {
			for (int c = 0; c < Y_dim; c++) {
				getline(inputfile, line);
				cout << line << endl;
				input_data[c][r] = stof(line);
				cout << "Added as float" << endl;
			}
		}

		inputfile.close();
		cout << "added all data to vector!" << endl;
		return input_data;
		
		
	}
	else cout << "Unable to open file";	
}

int main() {

	float NewTemp;

	int X_dim = 0;
	int	Y_dim = 0;
	int	iterations = 0;
	float multiplier = 0;
	float temp;
	//Use dynamic array

	vector<vector<float>> input_data = file_reader(X_dim, Y_dim, iterations, multiplier);

	cout << endl;

	vector<vector<point>> initial_grid = initial(input_data, X_dim, Y_dim);

	for (int i = 0; i < X_dim; i++) {
		for (int j = 0; j < Y_dim; j++) {
			cout << to_string(initial_grid[j][i].Temp) << endl;
		}
	}



	system("PAUSE");

}
