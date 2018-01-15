// cppPrimer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ch3progex.h"
#include "ch4progex.h"
#include "ch5progex.h"
#include "ch6progex.h"
#include "ch7progex.h"
#include "ch8progex.h"
#include "ch9progex.h"
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <new>
#include "stocks.h"
using namespace std;

int main(void)
{
	
	cout.setf(ios_base::fixed, ios_base::floatfield);        // #.## format
	cout.precision(2);                 // #.## format
	cout.setf(ios_base::showpoint);    // #.## format

	cout << "Using constructors to create new objects\n";
	Stock stock1("NanoSmart", 12, 20.0);                     // syntax 1
	stock1.show();
	Stock stock2 = Stock("Boffo Objects", 2, 2.0);           // syntax 2
	stock2.show();

	cout << "Assigning stock1 to stock2:\n";
	stock2 = stock1;
	cout << "Listing stock1 and stock2:\n";
	stock1.show();
	stock2.show();

	cout << "Using a constructor to reset an object\n";
	stock1 = Stock("Nifty Foods", 10, 50.0);    // temp object
	cout << "Revised stock1:\n";
	stock1.show();
	cout << "Done\n";

	cin.get();
	cin.get();
	return 0;
}

