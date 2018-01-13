#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

/*
	Chapter 8 review questions
	
1. What kinds of functions are good candidates for inline status?
	Short/nonrecursive/one line.
2. Suppose the song() function has this prototype:

	void song(char * name, int times);
	
	a. How would you modify the prototype so that the default value for times is 1?
		void song(char * name, int times = 1);
	b. What changes would you make in the function definition?
		None, because 1 is in the domain of acceptable answers already?
	c. Can you provide a default value of "O, My Papa" for name?
		Yes, only if you also provide the default value for times.: -> void song(char * name = "O, My Papa", int times = 1);

3. Write overloaded versions of iquote(), a function rhat displays its argument enclosed in double quotation marks.
   Write three versions: one for an int argument, one for a double argument, and one for a string argumen.

   void iquote(int num);
   void iquote(double num);
   void iquote(char * quote);

   void iquote(int num) 
   {
		cout << "\"" << num << "\"" << endl;
	}

	void iquote(double num)
	{
		cout << "\"" << num << "\"" << endl;
	}
	void iquote(const char * quote)
	{
		cout << "\"" << quote << "\"" << endl;
	}

4. The following is a structure template:

	struct box
	{
		char maker[40];
		float height;
		float widgth;
		float length;
		float volume;
	};
	a. Write a function that has a reference to a box structure as its formal argument and
	   displays the value of each member.

	   void showBox(const box & input)
	   {
			cout << "maker: " << input.maker << endl;
			cout << "height: " << input.height << endl;
			cout << "width: " << input.width << endl;
			cout << "length: " << input.length << endl;
			cout << "volume: " << input.volume << endl;
		}

	b. Write a function that has a reference to a box structure as its formal argument and 
	    sets the volume member to the product of the other three dimensions.
		
		void setVolume(box & input)
		{
			input.volume = input.height * input.width * input.length;
		}

5. The following are some desired effects. Indicate whether each can be accomplished with
	default arguments, function overloading, both, or neither. Provide appropriate proto-
	types.

	a. mass(density, volume) returns the mass of an object having a density of
	density and a volume of volume, whereas mass(density) returns the mass hav-
	ing a density of density and a volume of 1.0 cubic meters. All quantities are type
	double.
	
		default arguments or function overloading:

		mass(double density, double volume = 1.0);  // default arguments

	b. repeat(10, "I'm OK") displays the indicated string 10 times, and repeat("But
	you're kind of stupid") displays the indicated string 5 times.

		overloading:
		repeat(int n, char * phrase);
		repeat(char * phrase);

	c. average(3,6) returns the int average of two int arguments, and average(3.0,
	6.0) returns the double average of two double values.
		function overloading:
		int average(int x, int y);
		double average(double x, double y);
		
	d. mangle("I'm glad to meet you") returns the character I or a pointer to the
	string "I'm mad to gleet you", depending on whether you assign the return
	value to a char variable or to a char* variable.

	neither: the return value is not part of the function signature.

6. Write a function template that returns the larger of its two arguments.
	template <typename T>
	T max(T x, T y)
	{
		if (x > y) return x;
		else return y;
	}s

7. Given the template of Review Question 6 and the box structure of Review Question 4,
	provide a template specialization that takes two box arguments and returns the one with
	the larger volume.

	template <> box max<box>(box x, box y)
	{
		if (x.volume > y.volume) return x;
		else return y;
	}
*/
using namespace std;
void multi_printer(char * str, int times = 0) {
	static int calledTimes = 0;
	calledTimes++;

	times = times > 0 ? calledTimes : 1;
	for (int i = 0; i < times; ++i)
		cout << str << endl;
}

void ex8_1(void)
{
	cout << "multi_printer(\"test phrase\"): \n";
	multi_printer("test phrase");
	cout << "multi_printer(\"test phrase\", 1): \n";
	multi_printer("test phrase", 1);
	cout << "multi_printer(\"test phrase\"): \n";
	multi_printer("test phrase");
	cout << "multi_printer(\"test phrase\", 1): \n";
	multi_printer("test phrase", 1);
}

const int MAX_STR = 64;
struct CandyBar {
	char * brand;
	double weight;
	int calories;
};

void updateBar(CandyBar & bar, char * brand = "Millenium Munch", double weight = 2.85, int calories = 350)
{
	bar.brand = brand;
	bar.weight = weight;
	bar.calories = calories;
}

void showBar(const struct CandyBar & bar)
{
	cout << "Brand: " << bar.brand << " weight: " << bar.weight << " calories: " << bar.calories << endl;
}
void ex8_2(void)
{
	struct CandyBar testBar = { "test brand", 6.66, 600 };
	cout << "Test Bar: ";
	showBar(testBar);
	updateBar(testBar, "test brand #2", 5.55, 500);
	cout << "After updating: " << endl;
	showBar(testBar);
	cout << "updating to all default vals: {\"Millenium Munch\", 2.85, 350}" << endl;
	updateBar(testBar);
	showBar(testBar);
}

void upperConv(std::string & phrase)
{
	for (int i = 0; i < phrase.length(); ++i)
	{
		phrase[i] = toupper(phrase[i]);
	}
}
void ex8_3(void)
{
	std::string input = "";
	cout << "Enter a string (q to quit): ";
	getline(cin, input);
	while (input.compare("q"))
	{
		upperConv(input);
		cout << input << endl;
		cout << "Enter a string (q to quit): ";
		getline(cin, input);
	} 
}
struct stringy {
	char * str;        // points to a string
	int ct;            // length of string (not counting '\0')
};
// prototypes for set(), show(), and show() go here
void set(struct stringy & beany, const char * testing);
void show(const struct stringy & beany);
void show(const struct stringy & beany, int times);
void show(const char * phrase);
void show(const char * phrase, int times);
void ex8_4(void)
{

	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);    // first argument is a reference,
				// allocates space to hold copy of testing,
				// sets str member of beany to point to the
				// new block, copies testing to new block,
				// and sets ct member of beany
	show(beany);      // prints member string once
	show(beany, 2);   // prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);    // prints testing string once
	show(testing, 3); // prints testing string thrice
	show("Done!");
}
void set(struct stringy & beany, const char * testing)
{
	char * newStr = new char[strlen(testing)];
	beany.str = newStr;
	strcpy(beany.str, testing);
	beany.ct = strlen(testing);
}
void show(const struct stringy & beany)
{
	cout << beany.str << endl;
}
void show(const struct stringy & beany, int times)
{
	for (int i = 0; i < times; ++i)
		cout << beany.str << endl;
}
void show(const char * phrase)
{
	cout << phrase << endl;
}
void show(const char * phrase, int times)
{
	for (int i = 0; i < times; ++i)
		cout << phrase << endl;
}

template <typename T>
T max5(const T * arr)
{
	T theMax = arr[0];
	for (int i = 1; i < 5; ++i)
		theMax = (arr[i] > theMax) ? arr[i] : theMax;
	return theMax;
}
void ex8_5(void)
{
	int intTest[5] = { 1, 6, 2, 4, 3 };
	double doubleTest[5] = { 10.0, 6.0, 2.0, 2.6, 3.0 };
	cout << "the max of the ints: " << max5(intTest) << endl;
	cout << "The max of the doubles: " << max5(doubleTest) << endl;
}
template <typename T>
T maxn(T arr[], int n);

template <> 
const char * maxn(const char * arr[], int size);

void ex8_6(void)
{
	int intTest[] = { 1, 6, 2, 4, 3, 7};
	double doubleTest[] = { 10.0, 6.0, 2.0, 2.6 };
	const char * words[4] = { "cat", "doggy", "marmot", "elephant" };
	cout << "the max of the ints: " << (int)maxn(intTest, 6) << endl;
	cout << "The max of the doubles: " << (double)maxn(doubleTest, 4) << endl;
	cout << "Array of cstrings: {cat, doggy, marmot, elephant}" << endl;
	cout << "The longest cstring is: " << (char *)maxn(words, 4) << endl;
}

template <typename T>
T maxn(T arr[], int n)
{
	T theMax = arr[0];
	for (int i = 1; i < n; ++i)
		theMax = (arr[i] > theMax) ? arr[i] : theMax;
	return theMax;
}

template <> const char * maxn(const char * arr[], int size)
{
	int best_len = 0;
	int best_idx = 0;
	
	for (int i = 0; i < size; ++i)
	{
		int cur = strlen(arr[i]);
		if (cur > best_len)
		{
			best_len = cur;
			best_idx = i;
		}
	}
	return arr[best_idx];
}


template <typename T> // template A
T ShowArray(T arr[], int n);

template <typename T> // template B
T ShowArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

/*
Modify Listing 8.14 so that the template functions return the sum of the array contents
instead of displaying the contents. The program now should report the total number of
things and the sum of all the debts
*/
void ex8_7(void)
{
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] =
	{
		{ "Ima Wolfe", 2400.0 },
		{ "Ura Fox", 1300.0 },
		{ "Iby Stout", 1800.0 }
	};
	double * pd[3];
	// set pointers to the amount members of the structures in the arr mr_E
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;
	cout << "Mr. E's has " << ShowArray(things, 6) << " things." << endl;
	cout << "Mr.E's debts total : $" << ShowArray(pd, 3) << endl;
}

template <typename T>
T ShowArray(T arr[], int n)
{
	cout << "template A\n";
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

template <typename T>
T ShowArray(T * arr[], int n)
{
	T sum = 0;
	cout << "template B\n";
	for (int i = 0; i < n; i++)
		sum += *arr[i];
	return sum;
}