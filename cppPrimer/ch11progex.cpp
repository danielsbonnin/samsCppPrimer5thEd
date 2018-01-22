#include "stdafx.h"
#include "ch11progex.h"
#include "stonewt.h"
#include "vect.h"
#include "mytime0.h"
#include "complex0.h"  // to avoid confusion with complex.h
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
void ex11_1()
{
	using VECTOR::Vector;
	ofstream fout;
	fout.open("ex11_1.txt");
	srand(time(0));      // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		fout << "Target Distance: " << target << " " << " Step Size: " << dstep << endl;
		cout << "Target Distance: " << target << " " << " Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			cout << steps << ": " << result << endl;
			fout << steps << ": " << result << endl;
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		result.rect_mode();
		fout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		fout << result << endl;
		result.polar_mode();
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";

	return;

}
void ex11_2()
{
	// Altered vect.cpp and vect.h according to instructions, tested with ex11_1().
	cout << "Testing new implementation of Vector class with ex11_1():" << endl;
	ex11_1();
}

void ex11_3()
{
	using VECTOR::Vector;
	srand(time(0));      // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	unsigned long int highest = 0;
	unsigned long int lowest = INT_MAX;
	int sumSteps = 0;
	double avg;
	int numtrials;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		cout << "Enter number of trials: ";
		if (!(cin >> numtrials))
			break;
		cout << "Target Distance: " << target << " " << " Step Size: " << dstep << " # Trials: " << numtrials << endl;
		for (int i = 0; i < numtrials; ++i)
		{
			steps = 0;
			result.set(0.0, 0.0, 'p');
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.set(dstep, direction, 'p');
				result = result + step;
				steps++;
			}
			highest = steps > highest ? steps : highest;
			lowest = steps < lowest ? steps : lowest;
			sumSteps += steps;
		}
		avg = sumSteps / double(numtrials);
		cout << "Target: " << target << " # Trials: " << numtrials << ":\n";
		cout << "Steps: " << "Highest: " << highest << " Lowest: " << lowest << " Average: " << avg << endl;

		steps = 0;
		sumSteps = 0;
		result.set(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";

	return;
}
void ex11_4()
{
	// Altered mytime0.h and mytime0.cpp, converting member operator 
	// overrides to friend funcs
	Time t(1, 30);
	cout << "Creating new Time: " << t << endl;
	Time u(0, 5);
	t = t + u;
	cout << "Adding 5 minutes: " << t << endl;
	t = t - u;
	cout << "Subtracting 5 minutes: " << t << endl;
	t = t * 2;
	cout << "Multiplying times 2: " << t << endl;
	t = 2 * t;
	cout << "Multiplying times 2 in the other order: " << t << endl;
}
void ex11_5()
{
	Stonewt s(32, 1.5);
	cout << "s: " << s << endl;
	s.setForm('i');
	cout << "Changing to integer pounds form: " << s << endl;
	s.setForm('f');
	cout << "Changing to float pounds form: " << s << endl;
	Stonewt t(100.7);
	t.setForm('f');
	cout << "Creating new 100.7 pound Stonewt: " << t << endl;
	s = s + t;
	cout << "Adding t to s: " << s << endl;
	Stonewt u(2);
	u.setForm('f');
	cout << "Creating a new Stonewt: " << u << endl;
	cout << "Multiplying " << s << " X " << u << " = ";
	s = s * u;
	cout << s << "Or: ";
	s.setForm('i');
	cout << s << ", Or: ";
	s.setForm('s');
	cout << s << endl;
	cout << "Bye" << endl;
}
void ex11_6()
{
	Stonewt arr[6] = { 10, 20, 30 };
	for (int i = 0; i < 6; ++i)
		cout << arr[i] << endl;
	int i = 3;
	double lbsInput = 0;
	while (i < 6)
	{
		cout << "Enter a weight in lbs: ";
		while (!(cin >> lbsInput) || lbsInput < 0.0)
			cout << "Enter a weight in lbs: ";
		arr[i] = Stonewt(lbsInput);
		i += 1;
	}
	Stonewt smallest = double(1 << 16);
	Stonewt largest = 0.0;
	Stonewt comp(11, 0);
	int lgrThanComp = 0;
	for (int i = 0; i < 6; ++i)
	{
		smallest = arr[i] < smallest ? arr[i] : smallest;
		largest = arr[i] > largest ? arr[i] : largest;
		if (arr[i] >= comp)
		{
			lgrThanComp += 1;
			cout << arr[i] << " is larger than " << comp << endl;
		}
	}
	cout << "*** Printing list of weights ***" << endl;
	for (int i = 0; i < 6; ++i)
		cout << arr[i] << endl;
	cout << "*** Finished printing ***" << endl;

	cout << "Smallest: " << smallest << endl;
	cout << "Largest: " << largest << endl;
	cout << "There are " << lgrThanComp << " Stonewts >= " << comp << ".\n";
	cout << "Bye!" << endl;
}
void ex11_7()
{
	complex0 c;
	complex0 a(3.0, 4.0);    // initialize to (3, 4i)
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << "\n";
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	return;
}