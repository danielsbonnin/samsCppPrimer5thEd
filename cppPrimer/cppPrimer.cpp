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
#include "ch11progex.h"
#include "ch12progex.h"
#include "ch13progex.h"
#include "studentc.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <new>
#include "stocks.h"
#include "mytime0.h"
#include "vect.h"
#include "stonewt.h"
#include "tabtenn0.h"
#include "Brass.h"
#include "dma.h"
#include "worker0.h"
#include "stacktp.h"
#include "arraytp.h"
#include "apair.h"
#include "tempmemb.h"
using namespace std;

template <template <typename T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	// assumes the thing class has push() and pop() members
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int & a, double & x) { return s1.pop(a) && s2.pop(x); }
};


int main(void)
{
	Crab<Stack> nebula;
// Stack must match template <typename T> class thing
	int ni;
	double nb;
	cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}

	while (nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}
