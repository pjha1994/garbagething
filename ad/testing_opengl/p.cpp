#include <iostream>
using namespace std;

const int x = 12; //Array size

void getTotal(int value[x])
{
	int total = 0;
	for (int i = 0; i < x; i++)
	{
		total += value[i];
	}
	cout << "Total = " << total << endl;
}

void getAverage(int value[x])
{
	int total = 0;
	for (int i = 0; i < x; i++)
	{
		total += value[i];
	}
	int average;
	average = total / x;
	cout << "Average = " << average << endl;
}

void getLargest(int value[x])
{
	int largest = value[0];
	for (int i = 1; i < x; i++)
	{
		if (value[i] > largest)
		{
			largest = value[i];
		}
	}
	cout << "Largest = " << largest << endl;
}

void getSmallest(int value[x])
{
	int lowest = value[0];
	for (int i = 1; i < x; i++)
	{
		if (value[i] < lowest)
		{
			lowest = value[i];
		}
	}
	cout << "Lowest = " << lowest << endl;
}


int main()
{
	int value[x];
	for (int i = 0,y=1; i < x,y<=x; i++,y++)
	{
		//for (int y = 1; y <= x; y++)
		//{
			cout << "Enter the rainfall (in inches) for month #";
			cout << y << " :";
			cin >> value[i];
		//}
		//break;
	}

	getSmallest(value);
	getLargest(value);
	getTotal(value);
	getAverage(value);

	return 0;
}