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
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <new>
#include "stocks.h"
#include "stack.h"
#include "mytime0.h"
#include "vect.h"
#include "stonewt.h"
#include "stringGood.h"
using namespace std;

const int BUF = 512;

class JustTesting
{
private:
	stringGood words;
	int number;
public:
	JustTesting(const stringGood & s = "Just Testing", int n = 0)
	{
		words = s; number = n; cout << words << " constructed\n";
	}
	~JustTesting() { cout << words << " destroyed\n"; }
	void Show() const { cout << words << ", " << number << endl; }
};
int main(void)
{
	char * buffer = new char[BUF];        // get a block of memory

	JustTesting *pc1, *pc2;

	pc1 = new (buffer) JustTesting;      // place object in buffer
	pc2 = new JustTesting("Heap1", 20);  // place object on heap

	cout << "Memory block addresses:\n" << "buffer: "
		<< (void *)buffer << "    heap: " << pc2 << endl;
	cout << "Memory contents:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting *pc3, *pc4;
	pc3 = new (buffer + sizeof(JustTesting))
		JustTesting("Better Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "Memory contents:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	delete pc2;
	delete pc4;
// explicitly destroy placement new objects
	pc3->~JustTesting();   // destroy object pointed to by pc3
	pc1->~JustTesting();   // destroy object ointed to by pc1

	delete[] buffer;
	cout << "Done\n";
	
	cin.get();
	cin.get();
	cin.get();
	return 0;
}
