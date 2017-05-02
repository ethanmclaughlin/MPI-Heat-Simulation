#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#define X 8
#define T 5

using namespace std;
/*
struct point
{
	double Temp;
	int X_loc;
	int Y_loc;
	bool IS_static;
};

  
const int SIZE_OF_ARRAY = 10;
*/
/*
void initial(point room[SIZE_OF_ARRAY][SIZE_OF_ARRAY]) {
	for (int row = 0; row < SIZE_OF_ARRAY; row++)
	{
		for (int colomn = 0; colomn < SIZE_OF_ARRAY; colomn++)
		{
			if (row == 0 || row == 9)
			{
				if (colomn == 0 || colomn == 9)
				{
					room[row][colomn];
				}
				else
				{
					room[row][colomn];
				}
			}
			else
			{
				room[row][colomn];
			}
		}
	}
}*/

/*
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
}*/
/*
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
*/

int main() {
	
	float P1Temp;
	float P2Temp;
	float P3Temp;
	float P4Temp;
	float P5Temp;
	float NewTemp;
	
	//Use dynamic array


	
	string line;

	ifstream inputfile("input.txt");
	if (inputfile.is_open())
	{
		while (getline(inputfile, line))
		{
			cout << line << '\n';
		}
		inputfile.close();
	}

	else cout << "Unable to open file";
	

	//point room[SIZE_OF_ARRAY][SIZE_OF_ARRAY];
	cout << "Temp simulator" << endl;
	cout << endl;
	cout << "Printing initial temp..." << endl;
	//initial(room);
	//print(room);


	int room[10][10];
	//float formula = P1Temp + ((P2Temp - P1Temp) * .01);

	//populate initial grid
	for (int row = 0; row < room[10][10]; row++)
	{
		for (int column = 0; column < room[10][10]; column++)
		{
			if (row == 0 || row == 9)
			{
				if (column == 0 || column == 9)
				{
					room[row][column] = 0;
				}
				else
				{
					room[row][column] = 0;
				}
			}
			else
			{
				room[row][column] = 0;
			}
		}
	}

	//print initial grid
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			cout << room[row][column] << " ";
		}
		cout << endl;
	}
	
	int temp;

	cout << "Enter temperture: ";
	cin >> temp;

	//First iteration
	for (int row = 0; row < room[10][10]; row++)
	{
		for (int column = 0; column < room[10][10]; column++)
		{
			//top or bottom row
			if (row == 0 || row == 9)
			{
				//first or last column
				if (column == 0 || column == 9)
				{
					//Corner formula
					//P1Temp +((P2Temp - P1Temp) * .01) + ((P3Temp - P1Temp) * .01)
					//NewTemp = room[row][column] + ((room[row][column + 1] - room[row][column]) * .01) + ((room[row + 1][column] - room[row][column]) * .01);
					
					//Top Right Corner
					NewTemp = room[row][column] + ((room[row][column - 1] - room[row][column]) * .01) + ((room[row + 1][column] - room[row][column]) * .01);
					//Bottom Left Corner
					NewTemp = room[row][column] + ((room[row][column + 1] - room[row][column]) * .01) + ((room[row - 1][column] - room[row][column]) * .01);
					//Bottom Right Corner
					NewTemp = room[row][column] + ((room[row][column - 1] - room[row][column]) * .01) + ((room[row - 1][column] - room[row][column]) * .01);
				}
				else
				{
					//Edge formula
					//P1Temp +((P2Temp - P1Temp) * .01) + ((P3Temp - P1Temp) * .01) + ((P4Temp - P1Temp) * .01)

					//Top Edge
					NewTemp = room[row][column] + ((room[row][column - 1] - room[row][column]) * .01) + ((room[row][column + 1] - room[row][column]) * .01)
						+ ((room[row + 1][column] - room[row][column]) * .01);
					//Left Edge
					NewTemp = room[row][column] + ((room[row - 1][column] - room[row][column]) * .01) + ((room[row][column + 1] - room[row][column]) * .01)
						+ ((room[row + 1][column] - room[row][column]) * .01);
					//Right Edge
					NewTemp = room[row][column] + ((room[row - 1][column] - room[row][column]) * .01) + ((room[row][column - 1] - room[row][column]) * .01)
						+ ((room[row + 1][column] - room[row][column]) * .01);
					//Bottom Edge
					NewTemp = room[row][column] + ((room[row][column - 1] - room[row][column]) * .01) + ((room[row - 1][column] - room[row][column]) * .01)
						+ ((room[row][column + 1] - room[row][column]) * .01);
				}
			}
			else
			{
				//Middle formula
				//P1Temp +((P2Temp - P1Temp) * .01) + ((P3Temp - P1Temp) * .01) + ((P4Temp - P1Temp) * .01) + ((P5Temp - P1Temp) * .01)
				NewTemp = room[row][column] + ((room[row][column - 1] - room[row][column]) * .01) + ((room[row][column + 1] - room[row][column]) * .01)
					+ ((room[row + 1][column] - room[row][column]) * .01) + ((room[row - 1][column] - room[row][column]) * .01);
			}
		}
	}

	//Print final grid
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			cout << room[row][column] << " ";
		}
		cout << endl;
	}


	system("PAUSE");
	return 0;
}


/*
float fun(int a)
{
	float formula = 4 * a - (a*a) / 2.0;

	return formula;
}

int main()
{
	float u[X + 1][T + 1];
	float h = 1.0;
	float k = 0.0125;
	float c;
	float al;
	float us;
	float ue;


	cout << "\n Enter the square of 'c' :";
	cin >> c;

	al = c*k / pow(h, 2);

	cout << " Enter the value of u[0, t] :";
	cin >> us;
	cout << "  Enter the value of u[" << X << ",t]:";
	cin >> ue;

	for (int i = 0; i <= T; i++)
	{
		u[0][i] = u[X][i] = us;
	}

	for (int j = 1; j <= X - 1; j++)
	{
		u[j][0] = fun(j);
	}

	for (int i = 0; i <= T - 1; i++)
	{
		for (int j = 1; j <= X - 1; j++)
		{
			u[j][i + 1] = al*u[j - 1][i] + (1 - 2 * al)*u[j][i] + al*u[j + 1][i];
		}
	}

	cout << " The value of alpha is " << al << "\n";
	cout << " The value of u[j,i] are:\n\n ";
	/*
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < X; j++)
			cout << "7.4 \t" << u[j][i];
		cout << "\n";
	}
	*//*
	for (int row = 0; row < T; row++)
	{
		for (int column = 0; column < X; column++)
		{
			//cout <<  setprecision(3) << u[row][column];
			printf("%6.4f\t", u[column][row]);
		}

		cout << endl;
	}

	system("PAUSE");
	return 0;
}*/


/*
P1NewTemp = P1Temp + ((P2Temp - P1Temp) * .01)



*/