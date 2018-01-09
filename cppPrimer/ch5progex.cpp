#include "stdafx.h"
#include <iostream>
#include <string>
#include "ch5progex.h"
using namespace std;

void ex5_1(void) 
{
	int start, stop, sum = 0;
	cout << "Enter the first integer: ";
	cin >> start;
	cout << "Enter the second integer: ";
	cin >> stop;
	for (start; start <= stop; ++start)
	{
		sum += start;
	}
	cout << "Sum: " << sum << endl;
	return;
}
void ex5_2(void)
{
	int cur = 1, sum = 0;
	while (cur)
	{
		cout << "Enter a number (0 to stop): ";
		cin >> cur;
		cout << "Sum: " << (sum += cur) << endl;
	}
	cout << "Done" << endl;
	return;
}
void ex5_3(void)
{
	const float dInc = 10.0;    // Simple interest rate
	const float cInt = 0.05;    // Compound interest rate
	double dBal = 100.0, cBal = 100.0;  // same starting balance
	int years = 0;
	while (cBal <= dBal)
	{
		dBal += dInc;
		cBal += (cBal * cInt);
		++years;
	}
	cout << "It takes " << years << " years for Cleo's balance to exceed Daphne's\n";
	return;
}
void ex5_4(void)
{
	const char * months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int sales[12];
	int sum = 0;
	for (int i = 0; i < 12; ++i)
	{
		cout << "Enter the number of books sold in " << months[i] << ": ";
		cin >> sales[i];
	}
	for (int i = 0; i < 12; ++i)
		sum += sales[i];
	cout << "Total sales: " << sum << endl;
	return;
}
void ex5_5(void)
{
	const char * months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int sales[3][12];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			cout << "Enter the number of books sold in year " << i + 1 << " month: " << months[j] << ": ";
			cin >> sales[i][j];
		}
	}
	int cursum = 0;
	int sum = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 12; ++j)
			cursum += sales[i][j];
		cout << "Total sales for year " << i << ": " << cursum << endl;
		sum += cursum;
		cursum = 0;
	}
	cout << "Total sales: " << sum << endl;
	
	return;
}
void ex5_6(void)
{
	struct Car
	{
		string make;
		int year;
	};
	int numCars = 0;
	cout << "How many cars do you wish to catalog? ";
	cin >> numCars;
	cin.get();
	Car * cars = new Car[numCars];
	for (int i = 0; i < numCars; ++i)
	{
		cout << "Car #" << i + 1 << ": " << endl;
		cout << "Please enter the make: ";
		getline(cin, cars[i].make);
		cout << "Please enter the year made: ";
		cin >> cars[i].year;
		cin.get();
	}
	cout << "Here is your collection:" << endl;
	for (int i = 0; i < numCars; ++i)
	{
		cout << cars[i].year << " " << cars[i].make << endl;
	}

	delete[] cars;
	return;
}
void ex5_7(void)
{
	char word[85];
	int count = -1;
	cout << "Enter words (type \"done\" to stop)\n";
	do
	{
		++count;
		
		cin >> word;

	} while (strcmp(word, "done"));
	cout << "You entered a total of " << count << " words." << endl;
	return;
}
void ex5_8(void)
{
	string word;
	int count = -1;
	cout << "Enter words (type \"done\" to stop)\n";
	do
	{
		++count;
		cin >> word;
	} while (word != "done");
	cout << "You entered a total of " << count << " words.\n";

	return;
}
void ex5_9(void)
{
	int rows = 0;
	cout << "Enter number of rows: ";
	cin >> rows;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			if (j >= (rows - i) - 1)
				cout << '*';
			else cout << '.';
		}
		cout << endl;
	}
	return;
}