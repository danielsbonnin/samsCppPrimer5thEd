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
using namespace std;
const int Num = 10;
int main(void)
{
	cout << "Please enter stack size: ";
	int stacksize;
	cin >> stacksize;
// create an empty stack with stacksize slots
	Stack<const char *> st(stacksize);

// in basket
	const char * in[Num] = {
		" 1: Hank Gilgamesh", " 2: Kiki Ishtar",
		" 3: Betty Rocker", " 4: Ian Flagranti",
		" 5: Wolfgang Kibble", " 6: Portia Koop",
		" 7: Joy Almondo", " 8: Xaverie Paprika",
		" 9: Juan Moore", "10: Misha Mache"
	};
// out basket
	const char * out[Num];
	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (rand() % 2 && nextin < Num)    // 50-50 chance
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		cout << out[i] << endl;

	cout << "Bye\n";
	cin.get();
	cin.get();
	return 0;
}
