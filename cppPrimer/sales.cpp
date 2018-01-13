#include "stdafx.h"
#include "sales.h"
#include <iostream>
namespace SALES
{
	// copies the lesser of 4 or n items from the array ar
	// to the sales member of s and computes and stores the
	// average, maximum, and minimum values of the entered items;
	// remaining elements of sales, if any, set to 0
	void setSales(Sales & s, const double ar[], int n)
	{
		int count = n < 4 ? n : 4;
		double sum = 0.0;
		s.min = double(1 << 32);
		s.max = 0;
		s.average = 0;
		for (int i = 0; i < 4; ++i)
			s.sales[i] = 0;
		for (int i = 0; i < count; ++i)
		{
			s.sales[i] = ar[i];
			s.min = ar[i] < s.min ? ar[i] : s.min;
			s.max = ar[i] > s.max ? ar[i] : s.max;
			sum += ar[i];
		}
		if (sum != 0)
			s.average = sum / count;
		return;
	}
	// gathers sales for 4 quarters interactively, stores them
	// in the sales member of s and computes and stores the
	// average, maximum, and minumum values
	void setSales(Sales & s)
	{
		using namespace std;
		double curInputs[4];
		for (int i = 0; i < 4; ++i)
		{
			cout << "Enter the sales for Q" << i + 1 << ": ";

			while (!(cin >> curInputs[i]))
			{
				cin.clear();
				cin.get();
				cout << "Enter a number: ";

			}
			// Ignore to the end of file
			cin.get();
		}
		setSales(s, curInputs, 4);
	}
	// display all information in structure s
	void showSales(const Sales & s)
	{
		using namespace std;
		for (int i = 0; i < 4; ++i)
		{
			cout << "Q" << i + 1 << ": " << s.sales[i] << " | ";
		}
		cout << "min: " << s.min << " max: " << s.max << " avg: " << s.average << endl;
	}
}