#pragma once
/*
ch 12 review questions
1. Suppose a String class has the following private members:
	class String
	{
	private:
		char * str;      // points to string allocated by new
		int len;         // holds length of string
	//...
	};

	a. What's wrong with this default constructor?
		String::String() {}

		Members are not initialized. Potentially leads to erroneous memory accesses.
		Should at least initialize str to NULL.

	b. What's wrong with this constructor?
		String::String(const char * s)
		{
			str = s;
			len = strlen(s);
		}

		Member str points to memory allocated elsewhere. Should allocate memory and use strcpy().

	c. What's wrong with this constructor?
		String::String(const char * s)
		{
			strcpy(str, s);
			len = strlen(s);
		}

		Member str has not allocated any memory for strcpy. 
		
		### From book answers pg 1155 ###
		Should use new char[len + 1]  to allocate the proper amount of memory.

2. Name three problems that may arise if you define a class in which a pointer member is
	initialized by using new. Indicate how that can be remedied. 

	0.5) (from the book) "When an object of that type expires, the data pointed to by the object's member
		pointer remains in memory, using space and remaining inaccessible because the pointer
		has been lost. That can be fixed by having the class destructor delete memory allocated
		by new in the constructor functions."

	1.) If the object's memory is freed using delete, the memory allocated by the constructor will not 
		automatically be freed using delete unless explicitly defined in the destructor.
	2.) Assigning via the assignment operator or copy constructor will make a shallow copy. This leads to the same memory being
		deleted multiple times, which is an error. 
	3.) If the object is allocated via placement new, its destructor must be explicitly called, since it was 
		not allocated on the heap. 

3. What class methods does the compiler generate automatically if you don't provide them
	explicitly? Describe how these implicitly generated functions behave.

	default constructor: allocates space for the non-static members; does not initialize values. 
	copy constructor:    copies non static variables to new object. This includes pointers. (memberwise assignment)
	assignment operator  (memberwise assignment).
	default destructor: does nothing
	address operator: returns the value of the "this" pointer

4. Identify and correct the errors in the following class declaration:

class nifty
{
// data
	char * personality;
	int talents;
	nifty & operator=(const nifty &) {};
	nifty & nifty(const nifty &) const {};
// methods
public:
	nifty();
	nifty(const char * s);
	~nifty();
	friend ostream & operator<<(ostream & os, const nifty & n);
};   

nifty::nifty()
{
	personality = NULL;
	talents = 0;
}

nifty::nifty(const char * s)
{
	personality = new char [strlen(s)];
	strcpy(personality, s);
	talents = 0;
}

nifty::~nifty()
{
	delete [] personality;
}
ostream & operator<<(ostream & os, const nifty & n)
{
	os << n.personality << '\n';
	os << n.talent << '\n';
	return os;
}

5. Consider the following class declaration:

class Golfer
{
private:
	char * fullname;      // points to string containing golfer's name
	int games;            // holds number of golf games played
	int * scores;         // points to first element of array of golf scores
public:
	Golfer();
	Golfer(const char * name, int g = 0);
	// creates empty dynamic array of g elements if g > 0
	Golfer(const Golfer & g);
	~Golfer();
};

	a. What class methods would be invoked by each of the following statements?
		Golfer nancy;                           // #1 default constructor
		Golfer lulu("Little Lulu");             // #2 Golfer(const char * name, int g = 0) constructor
		Golfer roy("Roy Hobbs", 12);            // #3 Golfer(const char * name, int g = 0) constructor
		Golfer * par = new Golfer;              // #4 default constructor
		Golfer next = lulu;                     // #5 copy constructor
		Golfer hazzard = "Weed Thwacker";       // #6 Golfer(const char * name, int g = 0) constructor
		*par = nancy;                           // #7 default assignment operator;
		nancy = "Nancy Putter";                 // #8  Golfer(const char * name, int h = 0) constructor, then default assignment operator method

	b. Clearly, the class requires several more methods to make it useful. What additional
		method does it require to protect against data corruption?
		
		It needs an explicit assignment operator. It also needs a scoreCount variable.

*/

void ex12_1();
void ex12_2();
void ex12_3();
void ex12_4();
void ex12_5();
void ex12_6();