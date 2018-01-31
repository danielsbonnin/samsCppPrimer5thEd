#include "stdafx.h"
#include "ch12progex.h"
#include "stringGood.h"
#include "stocks.h"
#include "Stack2.h"
#include "Queue.h"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Cow {
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;  // display all cow data
};

Cow::Cow()
{
	for (int i = 0; i < 20; ++i)
		name[i] = '\0';
	hobby = new char[5];
	strcpy(hobby, "none");
	hobby[4] = '\0';
	weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
	strcpy(name, nm);
	int nlen = strlen(nm);
	nlen = nlen < 20 ? nlen : 19;
	for (nlen; nlen < 20; ++nlen)
		name[nlen] = '\0';
	int hlen = strlen(ho);
	hobby = new char[hlen + 1];
	strcpy(hobby, ho);
	hobby[hlen] = '\0';
	weight = wt;
}
Cow::Cow(const Cow & c)
{
	for (int i = 0; i < 20; ++i)
		name[i] = c.name[i];
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy(hobby, c.hobby);
	hobby[len] = '\0';
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	delete[] hobby;
	for (int i = 0; i < 20; ++i)
		name[i] = c.name[i];
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy(hobby, c.hobby);
	hobby[len] = '\0';
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	cout << "Name: " << name << " Hobby: " << hobby << " Weight: " << weight << endl;
}
void ex12_1()
{
	Cow daniel("Daniel", "Tennis", 170);
	daniel.ShowCow();
	Cow dan(daniel);
	dan.ShowCow();
	Cow scott = dan;
	scott.ShowCow();
}
void ex12_2()
{
	// practice exercise test program from exercise 12.2 in the book
	stringGood s1(" and I am a C++ student.");
	stringGood s2 = "Please enter your name: ";
	stringGood s3;
	cout << s2;                    // overloaded << operator
	cin >> s3;                     // overloaded >> operator
	s2 = "My name is " + s3;       // overloaded =, + operators
	cout << s2 << ".\n";
	
	s2 = s2 + s1;
	s2.stringup();                 // converts string to uppercase
	cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
		<< " 'A' characters in it.\n";
	s1 = "red";      // stringGood(const char *),
	                 // then stringGood & operator=(const stringGood&)
	stringGood rgb[3] = { stringGood(s1), stringGood("green"), stringGood("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	stringGood ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();            // converts string to lowercase
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])   // overloaded == operator
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye\n";
}
void ex12_3()
{
	/*
		Rewrite the  Stock class, as described in Listings 10.7 and 10.8 in Chapter 10, so that it
		uses dynamically allocated memory directly instead of using  string class objects to hold
		the stock names.Also, replace the  show() member function with an overloaded
		operator<<() definition.Test the new definition program in Listing 10.9.
	*/
	// listing 10.9: pg 501
	const int STKS = 4;
// create an array of initialized objects
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	cout.precision(2);								 // #.## format
	cout.setf(ios_base::fixed, ios_base::floatfield);// #.## format
	cout.setf(ios_base::showpoint);                  // #.## format

	cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		cout << stocks[st];

	Stock top = stocks[0];
	for (st = 1; st < STKS; st++)
		top = top.topval(stocks[st]);
	cout << "\nMost valuable holding:\n";
	cout << top;
}
void ex12_4()
{
	Stack2 a(10);
	for (int i = 0; i < 10; ++i)
		a.push(i);
	cout << a;
	Stack2 b(a);
	cout << b;
	Stack2 c;
	int temp;
	while (!a.isempty())
	{
		a.pop(temp);
		c.push(temp);
	}
	cout << c;
	cout << a;
	while (!a.isfull())
		a.push(1);
	cout << a;
}
const int MIN_PER_HR = 60;
bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}
void ex12_5()
{
/*
	The Bank of Heather has performed a study showing that ATM customers won’t wait
	more than one minute in line. Using the simulation from Listing 12.10, find a value for
	number of customers per hour that leads to an average wait time of one minute. (Use at
	least a 100-hour trial period.)
*/
	srand(time(0));    // random initializing of rand()

	int qs = 5;
	Queue line(qs);    // line queue holds up to qs people
	
	int hours = 10000;   // hours of simulation
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours;  // # of cycles

	
	double perhour;         // average # of arrivals per hour
	perhour = 18.1;
	cout << "***Customers per hour = " << perhour << "***\n";
	double min_per_cust;    // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;              // new customer data
	long turnaways = 0;     // turned away by full queue
	long customers = 0;     // joined the queue
	long served = 0;        // served during the simulation
	long sum_line = 0;      // cumulative line length
	int wait_time = 0;      // time until autoteller is free
	long line_wait = 0;     // cumulative time in line

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
			line.dequeue(temp);     // attend next customer
			wait_time = temp.ptime(); // for wait_time minutes
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}
// reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
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

}
void ex12_6()
{
/*
	The Bank of Heather would like to know what would happen if it added a second ATM.
	Modify the simulation in this chapter so that it has two queues. Assume that a customer
	will join the first queue if it has fewer people in it than the second queue and that the
	customer will join the second queue otherwise. Again, find a value for number of cus-
	tomers per hour that leads to an average wait time of one minute. (Note: This is a non-
	linear problem in that doubling the number of ATMs doesn't double the number of
	customers who can be handled per hour with a one-minute wait maximum.)
*/
	
	srand(time(0));    // random initializing of rand()

	int qs = 5;
	Queue line1(qs);    // line queue holds up to qs people
	Queue line2(qs);   
	int hours = 10000;   // hours of simulation
						 // simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours;  // # of cycles


	double perhour;         // average # of arrivals per hour
	perhour = 50.5;
	cout << "***Customers per hour = " << perhour << "***\n";
	double min_per_cust;    // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp, templ1, templ2;              // new customer data
	long turnaways = 0;     // turned away by full queue
	long customers = 0;     // joined the queue
	long served = 0;        // served during the simulation
	long sum_line1 = 0;      // cumulative line length
	long sum_line2 = 0;
	int line1_wait_time = 0;      // time until autoteller is free
	int line2_wait_time = 0;
	long line_wait = 0;     // cumulative time in line

	// for each minute, check if new customer
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))  // have newcomer
		{
			// See which queue is shorter
			if (line1.isfull() && line2.isfull())
				turnaways++;
			else if (line1.queuecount() < line2.queuecount())
			{
				customers++;
				temp.set(cycle);
				line1.enqueue(temp);
			}
			else
			{
				customers++;
				temp.set(cycle);
				line2.enqueue(temp);
			}
		}
		if (line1_wait_time <= 0 && !line1.isempty())
		{
			line1.dequeue(templ1);     // attend next customer
			line1_wait_time = templ1.ptime(); // for wait_time minutes
			line_wait += cycle - templ1.when();
			served++;
		}
		if (line2_wait_time <= 0 && !line2.isempty())
		{
			line2.dequeue(templ2);    // attend next customer
			line2_wait_time = templ2.ptime();
			line_wait += cycle - templ2.when();
			served++;
		}
		if (line1_wait_time > 0)
			line1_wait_time--;
		if (line2_wait_time > 0)
			line2_wait_time--;
		sum_line1 += line1.queuecount();
		sum_line2 += line2.queuecount();
	}
	// reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size for line 1: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line1 / cyclelimit << endl;
		cout << "average queue size for line 2: ";
		cout << (double)sum_line2 / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
}