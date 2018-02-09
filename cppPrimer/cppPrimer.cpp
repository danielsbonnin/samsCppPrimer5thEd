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
using namespace std;

int main(void)
{
	APair<string, int> ratings[4] =
	{
		APair<string, int>("The Purple Duke", 5),
		APair<string, int>("Jake's Frisco Al Fresco", 4),
		APair<string, int>("Mont Souffle", 5),
		APair<string, int>("Gertie's Eats", 3)
	};

	int joints = sizeof(ratings) / sizeof(APair<string, int>);
	cout << "Rating:\t Eatery\n";
	for (int i = 0; i < joints; i++)
		cout << ratings[i].second() << ":\t "
		<< ratings[i].first() << endl;
	cout << "Oops! Revised rating:\n";
	ratings[3].first() = "Gertie's Fab Eats";
	ratings[3].second() = 6;
	cout << ratings[3].second() << ":\t "
		<< ratings[3].first() << endl;
	cin.get();
	cin.get();
	return 0;
}
