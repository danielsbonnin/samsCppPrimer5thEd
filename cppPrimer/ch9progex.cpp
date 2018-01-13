#include "stdafx.h"
/*
Ch. 9  Review questions:

1. What storage scheme would you use for the following situations?

	a. homer is a formal argument (parameter) to a function.
		automatic
	b. The secret variable is to be shared by two files.
		defined as an external variable in 1st file; declared using "extern" in second file
	c. The topsecret variable is to be shared by the functions in one file but hidden from other files.
		2 ways: using static keyword to define as static variable with internal linkage, or defined in unnamed namespace
	d. beencalled keeps track of how many times the function containing it has been called.
		declared in the function using keyword "static"
2. Describe the differences between a using declaration and a using directive.
	A using declaration brings a single name into the current scope, while a using directive brings all the
	names from a namespace into the current scope.

3. Rewrite the following so that it doesn't use using declarations or using directives:
	#include <iostream>
	using namespace std;
	int main()
	{
		double x;
		cout << "Enter value: ";
		while (! (cin >> x) )
		{
			cout << "Bad input. Please enter a number: ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		cout << "Value = " << x << endl;
		return 0;
	}

	#include <iostream>
	int main()
	{
		double x;
		std::cout << "Enter value: ";
		while (! (std::cin >> x) )
		{
			std::cout << "Bad input. Please enter a number: ";
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
		}
		std::cout << "Value = " << x << std::endl;
		return 0;

4. Rewrite the following so that it uses using declarations instead of the using directive:
	***The same code from #3***
	#include <iostream>
	using std::cin;
	using std::endl;
	using std::cout;
	int main()
	{
		double x;
		cout << "Enter value: ";
		while (! (cin >> x) )
		{
			cout << "Bad input. Please enter a number: ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		cout << "Value = " << x << endl;
		return 0;
	}

5. Say that the average(3,6) function returns an int average of the two int arguments
	when it is called in one file, and it returns a double average of the two int arguments
	when it is called in a second file in the same program. How could you set this up?
	// file1.cpp
	static int average(int, int);
	static int average(int x, int y)
	{
		return (x + y) / 2;
	}

	// file2.cpp
	static double average(int x, int y);
	double average(int x, int y)
	{
		return (double)(x + y) / 2.0;
	}

	*** OR you could define each file's average() function in an unnamed namespace ***

6. What will the following two-file program display?

	// file1.cpp
	#include <iostream>
	using namespace std;
	void other();
	void another();
	int x = 10;
	int y;

	int main()
	{
		cout << x << endl;
		{
			int x = 4;
			cout << x << endl;
			cout << y << endl;
		}
		other();
		another();
		return 0;
	}

	void other()
	{
		int y = 1;
		cout << "Other: " << x << ", " << y << endl;
	}

	// file 2.cpp
	#include <iostream>
	using namespace std;
	extern int x;
	namespace
	{
		int y = -4;
	}

	void another()
	{
		cout << "another(): " << x << ", " << y << endl;
	}

	***** answer: *****
	10
	4
	0
	Other: 10, 1
	another(): 10, -4

7. What will the following program display?

	#include <iostream>
	using namespace std;
	void other();
	namespace n1
	{
		int x = 1;
	}

	namespace n2
	{
		int x = 2;
	}

	int main()
	{
		using namespace n1;
		cout << x << endl;
		{
			int x = 4;
			cout << x << ", " << n1::x << ", " << n2::x << endl;
		}
		using n2::x;
		cout << x << endl;

		other();
		return 0;
	}

	void other()
	{
		using namespace n2;
		cout << x << endl;
		{
			int x = 4;
			cout << x << ", " << n1::x << ", " << n2::x << endl;
		}
		using n2::x;
		cout << x << endl;
	}
	**** answer ****
	1
	4, 1, 2
	2
	2
	4, 1, 2
	2
*/
#include "golf.h"
#include "golf2.h"
#include "sales.h"
#include <iostream>
#include <new>
void ex9_1()
{
	using namespace golf1;
	const int golfersLen = 10;
	golf golfers[golfersLen];
	int i = 0;
	for (i; i < golfersLen; ++i)
	{
		std::cout << "Golfer: " << i + 1 << std::endl;
		if (!setgolf(golfers[i]))
		{
			i--;
			break;
		}
	}
	if (i < 0) return;
	std::cout << "You entered the following golfers:\n";
	for (int j = 0; j <= i; ++j)
		showgolf(golfers[j]);
	for (int j = 0; j <= i; ++j)
		handicap(golfers[j], j);
	std::cout << "After resetting handicaps: \n";
	for (int j = 0; j <= i; ++j)
		showgolf(golfers[j]);
	return;
}

void ex9_2()
{
	using namespace golf2;
	const int golfersLen = 10;
	golf golfers[golfersLen];
	int i = 0;
	for (i; i < golfersLen; ++i)
	{
		std::cout << "Golfer: " << i + 1 << std::endl;
		if (!setgolf(golfers[i]))
		{
			i--;
			break;
		}
	}
	if (i < 0) return;
	std::cout << "You entered the following golfers:\n";
	for (int j = 0; j <= i; ++j)
		showgolf(golfers[j]);
	for (int j = 0; j <= i; ++j)
		handicap(golfers[j], j);
	std::cout << "After resetting handicaps: \n";
	for (int j = 0; j <= i; ++j)
		showgolf(golfers[j]);
	return;
}

void ex9_3()
{
	struct chaff
	{
		char dross[20];
		int slag;
	};
	const int BUF = 2;
	chaff * buffer = new chaff[BUF];
	chaff * first = new (buffer) chaff;
	chaff * second = new (buffer + 1) chaff;
	strcpy(first->dross, "sample for first");
	strcpy(second->dross, "sample for second");
	first->slag = 1;
	second->slag = 2;
	for (int i = 0; i < BUF; ++i)
		std::cout << "chaff #" << i + 1 << ": " << buffer[i].dross << ", " << buffer[i].slag << std::endl;
	delete[] buffer;
}

void ex9_4()
{
	using namespace SALES;
	struct Sales s;
	setSales(s);
	showSales(s);
}