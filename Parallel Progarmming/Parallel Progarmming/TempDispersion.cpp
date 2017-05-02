
/*
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

//Print the numbers in the array with a fixed precision of 4 and width 10.   
const int SIZE_OF_ARRAY = 10;
const double CHANGE = 0.1;
const double NEIGHBORS = 4.0;
double averageTemperature = 0.0;
double largestChange = 0.0;
double oldValue = .0;

void initial(double room[SIZE_OF_ARRAY][SIZE_OF_ARRAY]) {
	for (int row = 0; row < SIZE_OF_ARRAY; row++)
	{
		for (int colomn = 0; colomn < SIZE_OF_ARRAY; colomn++)
		{
			if (row == 0 || row == 9)
			{
				if (colomn == 0 || colomn == 9)
				{
					room[row][colomn] = 0;
				}
				else
				{
					room[row][colomn] = 100;
				}
			}
			else
			{
				room[row][colomn] = 0;
			}
		}
	}
}

void print(double room[SIZE_OF_ARRAY][SIZE_OF_ARRAY]) {
	for (int row = 0; row < SIZE_OF_ARRAY; row++)
	{
		for (int colomn = 0; colomn < SIZE_OF_ARRAY; colomn++)
		{
			if (colomn == 9) {
				cout << room[row][colomn];
			}
			else {
				cout << room[row][colomn] << ",";
			}
		}
		cout << endl;
	}
}

void firstIteration(double room[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	for (int row = 1; row < SIZE_OF_ARRAY - 1; row++)
	{
		for (int column = 1; column < SIZE_OF_ARRAY - 1; column++)
		{

			averageTemperature = (room[row][column - 1] + room[row + 1][column] + room[row][column + 1] + room[row - 1][column]) / NEIGHBORS;
			room[row][column] = averageTemperature;

		}
	}

}

void average(double room[SIZE_OF_ARRAY][SIZE_OF_ARRAY])
{
	do
	{
		largestChange = 0;
		for (int row = 1; row < SIZE_OF_ARRAY - 1; row++)
		{
			for (int column = 1; column < SIZE_OF_ARRAY - 1; column++)
			{
				double oldValue = room[row][column];
				averageTemperature = (room[row][column - 1] + room[row + 1][column] + room[row][column + 1] + room[row - 1][column]) / NEIGHBORS;
				room[row][column] = averageTemperature;

				double change = abs(oldValue - room[row][column]);
				if (change > largestChange)
				{
					largestChange = change;
				}
			}
		}


	} while (largestChange > CHANGE);

}

int main() {
	double room[SIZE_OF_ARRAY][SIZE_OF_ARRAY];
	cout << "Temp simulator" << endl;
	cout << endl;
	cout << "Printing initial temp..." << endl;
	initial(room);
	print(room);
	cout << endl;
	firstIteration(room);
	cout << "Printing room after one iteration..." << endl;
	print(room);

	cout << endl << endl;

	average(room);
	print(room);

	system("PAUSE");
	return 0;
}

*/