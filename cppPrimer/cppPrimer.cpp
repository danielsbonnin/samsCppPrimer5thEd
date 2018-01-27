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
#include "stringGood.h"
#include "Queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);  // is there a new customer?

using namespace std;

int main(void)
{
// setting things up
	srand(time(0));      // random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);      // line queue holds up to qs people

	cout << "Enter the number of sumulation hours: ";
	int hours;           // hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles

	cout << "Enter the average number of customers per hour: ";
	double perhour;       // average # of arrival per hour
	cin >> perhour;
	double min_per_cust;  // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;            // new customer data
	long turnaways = 0;   // turned away by full queue
	long customers = 0;   // joined the queue
	long served = 0;      // served during the simulation
	long sum_line = 0;    // cumulative line length
	int wait_time = 0;    // time until autoteller is free
	long line_wait = 0;   // cumulative time in line

// running the simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))  // have newcomer
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);     // cycle = time of arrival
				line.enqueue(temp);  // add newcomer to line
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);       // attend next customer
			wait_time = temp.ptime(); // for wait_time minutes
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";

	cin.get();
	cin.get();
	return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minutes
bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}
