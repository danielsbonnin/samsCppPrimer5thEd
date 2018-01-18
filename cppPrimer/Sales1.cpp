#include "stdafx.h"
#include "Sales1.h"
#include "sales.h"
#include <iostream>

namespace SALES {
	Sales1::Sales1()
	{
		for (int i = 0; i < QUARTERS; ++i)
			sales[i] = 0.0;
		setVars();
	}

	Sales1::Sales1(const double ar[], int n)
	{
		for (int i = 0; i < QUARTERS; ++i)
		{
			if (i < n)
			{
				sales[i] = ar[i];
			}
			else
				sales[i] = 0.0;
		}
		setVars();
	}
	void Sales1::setVars()
	{
		double thesum = 0;
		min = sales[0];
		max = sales[0];

		for (int i = 0; i < QUARTERS; ++i)
		{
			thesum += sales[i];
			max = sales[i] > max ? sales[i] : max;
			min = sales[i] < min ? sales[i] : min;
		}
		average = thesum / double(QUARTERS);
	}

	void Sales1::setSales()
	{
		using namespace std;
		int i = 0;
		double entries[QUARTERS];
		char ans = ' ';
		while (i < 4)
		{
			cout << "Enter the sales for Q " << i + 1 << ": ";
			if (!(cin >> entries[i]))
			{
				cin.get();
				cin.clear();
				cout << "quit? (Y/N): ";
				cin.get();

				cin >> ans;
				if (ans == 'Y' || ans == 'y')
					break;
				else
					cout << "Ok, if you don't want to quit, then enter N U M B E R S for sales figures.\n";
				cin.get();
				continue;
			}
			cin.get();
			i++;
		}
		cout << "You entered " << i << " sales figures. " << endl;
		Sales1 s(entries, i);
		*this = s;
	}
	Sales1::~Sales1()
	{
	}

	// display all information in structure s
	void Sales1::showSales() const
	{
		using namespace std;
		cout << "Quarterly Sales: |";
		for (int i = 0; i < QUARTERS; ++i)
			cout << "Q" << i + 1 << ": " << sales[i] << " | ";
		cout << "|" << endl;
		cout << "Minimum: " << min << " Maximum: " << max << " Average: " << average << endl;
	}
}