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
using namespace std;

int main(void)
{
	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << shirt << endl;
	cout << balloon << endl;
	cout << map << endl;
	lacksDMA balloon2(balloon);
	hasDMA map2;
	map2 = map;
	cout << balloon2 << endl;
	cout << map2 << endl;
	cin.get();
	cin.get();
	return 0;
}
