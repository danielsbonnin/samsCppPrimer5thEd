#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Review Questions ch. 7 Sams C++ Primer Pluss 5th ed. 
1. defining the function, declaring the prototype, calling the function.
2. a. void igor(); float tofu(int); double mpg(double, double); long summation(long arr[], int size); 
    e.) double doctor(const char name[]); f.) void ofcourse(boss); g.) char * plot(map *);
3. 
void loader(int empty[], int arr_size, int val)
{
	for (--arr_size;  arr_size > -1; --arr_size)
		empty[arr_size] = val;
}
4.) 
void setter(int * st, int *end, int val)]
{
	for (int *i = st; i != end; ++i)
	{
		*i = val;
	}
}

5.)
double max(const double arr[], int size)
{
	double themax = arr[0]
	for (int i = 1; i < size; ++i)
		themax = arr[i] > themax ? arr[i] : themax;
	return themax;
}
6.)
Because C++ is a "pass-by_value" language, so it wouldn't make a difference. 
7.)
string constant, char *, char []
8.)
int replace(char * str, char c1, char c2)
{
	int count = 0;
	while (str*)
	{
		if (str* == c1)
		{
			++count;
			str* = c2;
		}
		str++;
	}
	return count;
}
9.) *"pizza" means 'p'. "taco"[2] means 'c'
10.) You would pass glitz by value the same way as a fundamental type. You would pass its address 
using the addressof operator & as in &glitz. Passing by value uses additional memory but is less prone to 
difficult bugs. Passing by reference is more efficient but a little more complex and risky. 
11.) int judge (int (*p)(const char *));
*/
double harmonic_mean(double x, double y)
{
	return 2.0 * x * y / (x + y);
}
void ex7_1(void)
{
	double x, y;
	cout << "Enter two numbers (enter a 0 to stop): " << endl;
	while (cin >> x >> y)
	{
		if (x == double(0) || y == double(0))
		{
			cout << "Bye.\n";
			return;
		}
		cout << "The harmonic mean of " << x << " and " << y << " is " << harmonic_mean(x, y) << ".\n";
	}
}

void ex7_2(void)
{
	cout << "Enter up to 10 golf scores to average (enter 0 to end): \n";
	int scores[10];
	int curScore = 0;
	double sum = 0.0;
	int count = 0;
	for (int i = 0; i < 10; ++i)
	{
		cin >> curScore;
		if (!cin)
		{
			while (cin.get() != '\n')
				continue;
		}
		if (curScore < 1)
			break;

		sum += double(curScore);
		scores[count] = curScore;
		count++;
		cout << "curScore: " << curScore << " count: " << count << " sum: " << sum << endl;
		
	}
	sum /= count;
	cout << "You entered the following scores\n";
	for (int i = 0; i < count; ++i)
	{
		cout << "Score #" << i + 1 << ": " << scores[i] << endl;
	}
	cout << "The average score is: " << sum << endl;
}
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void boxDisplay(box b) {
	cout << b.maker << "'s box:\n";
	cout << "\theight: " << b.height << "\twidth: " << b.width << "\tlength: " << b.length << "\tvolume: " << b.volume << endl;
}
void boxRef(box * b) {
	b->volume = b->height * b->width * b->length;
	cout << b->maker << "'s box:\n";
	cout << "\theight: " << b->height << "\twidth: " << b->width << "\tlength: " << b->length << "\tvolume: " << b->volume << endl;
}
void ex7_3(void)
{
	box first = { "Darnell Washington", 5, 5, 5, 100 };
	boxDisplay(first);
	boxRef(&first);
}
long double probability(unsigned numbers, unsigned picks, unsigned powerball)
{
	long double result = 1.0;   // here come some local variables
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result * powerball;
}
void ex7_4(void)
{
	double total, choices, powerball;
	cout << "Enter the number of choices on the game card in the regular section, \n"
		"the number of picks allowed, and the number of powerball options:\n";
	while ((cin >> total >> choices >> powerball) && choices <= total && powerball > 0)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices, powerball);       // compute the odds
		cout << " of winning.\n";
		cout << "Next two numbers (q to quit): ";
	}
	cout << "bye\n";
}

int recFact(int x)
{
	if (x < 1) return 0;
	if (x == 1) return 1;
	return x * recFact(x - 1);
}
void ex7_5(void)
{
	double input;
	cout << "Enter a number to factorial (0 to quit):\n";
	while (cin >> input && input > 0)
		cout << "The factorial of " << input << " is " << recFact(input) << endl;
}

int Fill_array(double vals[], int size)
{
	int i = 0;
	double curNum = 0.0;
	cout << "Enter numbers (other to quit):\n";
	while (i < size && cin >> vals[i])
		i++;
	return i;
}
void Show_array(const double vals[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << vals[i] << " ";
	cout << endl;
}
void Reverse_array(double vals[], int size)
{
	double temp = 0.0;
	for (int i = 0; i < size / 2; ++i)
	{
		temp = vals[i];
		vals[i] = vals[size - i - 1];
		vals[size - i - 1] = temp;
	}
}
void ex7_6(void)
{
	const int ARR_LIMIT = 10;
	double arr[ARR_LIMIT];
	int size = 0;
	size = Fill_array(arr, ARR_LIMIT);
	Show_array(arr, size);
	Reverse_array(arr, size);
	Show_array(arr, size);
	Reverse_array(arr, size);
	cout << "Back to normal\n";
	Show_array(arr, size);
	Reverse_array(arr, size - 1);
	Reverse_array(arr, size - 2);
	Reverse_array(arr, size - 1);
	Show_array(arr, size);


}

double * fill_array(double * st, double * end)
{
	double temp;
	int count = 0;
	for (st; st != end; st++)
	{
		cout << "Enter value #" << (count + 1) << ": ";
		cin >> temp;
		if (!cin)    // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)    // signal to terminate
			break;
		else count++;
		*st = temp;
	}
	return st;
}

void show_array(double * st, double * end)
{
	int i = 0;
	for (st; st != end; st++)
	{
		cout << "Property #" << (++i) << ": $";
		cout << *st << endl;
	}
}

void revalue(double r, double * st, double * end)
{
	for (st; st != end; ++st)
		*st *= r;
}
void ex7_7(void)
{
	const int Max = 5;
	double properties[Max];

	double * end = fill_array(&properties[0], &properties[Max - 1]);
	show_array(&properties[0], end);
	cout << "Enter revaluation factor: ";
	double factor;
	cin >> factor;
	revalue(factor, properties, end);
	show_array(properties, end);
	cout << "Done\n";
	return;
}
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter a student's name (or press Enter to quit):\n";
		cin.getline(pa[i].fullname, SLEN);
		if (!cin)
		{
			count = i;
			break;
		}
		++count;
		cout << "Enter " << pa[i].fullname << "'s hobby:\n";
		cin.getline(pa[i].hobby, SLEN);
		cout << " Enter " << pa[i].fullname << "'s ooplevel:\n";
		cin >> pa[i].ooplevel;
		cout << "You entered: " << pa[i].hobby << " and " << pa[i].ooplevel << endl;
		while (cin.get() != '\n')
			continue;
	}
	return count;
}

// display1() takes a student structure as an argument
// and displays its contents
void display1(student st)
{
	cout << st.fullname << ": " << endl;
	cout << st.fullname << "'s hobby is: " << st.hobby << endl;
	cout << st.fullname << "'s ooplevel is: " << st.ooplevel << endl;
}

// display2() takes the address of student structure as an
// argument and displays the structure's contents
void display2(const student * ps)
{
	cout << ps->fullname << ": " << endl;
	cout << ps->fullname << "'s hobby is " << ps->hobby << endl;
	cout << ps->fullname << "'s ooplevel is " << ps->ooplevel << endl;
}

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n)
{
	cout << "Showing all students by value:\n";
	for (int i = 0; i < n; ++i)
	{
		display1(pa[i]);
	}
	cout << "Showing all students by reference:\n";
	student * s;
	for (int i = 0; i < n; ++i)
	{
		display2(&pa[i]);
	}
}
void ex7_8(void)
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	cout << "class size: " << class_size << endl;
	while (cin.get() != '\n')
		continue;

	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	cout << "You entered: " << entered << " different students\n";
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";
	return;
}

double add(double x, double y)
{
	return x + y;
}

double mult(double x, double y)
{
	return x * y;
}

double calculate(double x, double y, double(*func)(double, double))
{
	return func(x, y);
}
void ex7_9(void)
{
	double x, y;
	cout << "Enter a pair of numbers:\n";
	while (cin >> x >> y)
	{
		cout << "The sum of " << x << " and " << y << " is: " << calculate(x, y, add) << endl;
		cout << "The product of " << x << " and " << y << " is: " << calculate(x, y, mult) << endl;
		cout << "Enter two more numbers or other to exit" << endl;
	}
	cout << "Bye\n";

}