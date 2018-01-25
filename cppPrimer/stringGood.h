#pragma once
#include <iostream>

class stringGood
{
private:
	char * str;                 // pointer to string
	int len;                    // length of string
	static int num_strings;     // number of objects
	static const int CINLIM = 80;  // cin input limit
public:
	stringGood(const char * s);  // constructor
	stringGood();                // default constructor
	stringGood(const stringGood & st);  // copy constructor
	int length() const { return len; }
// overloaded operator methods
	stringGood & operator=(const stringGood &);  // for deep copy
	stringGood & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
// overloaded operator friends
	friend bool operator<(const stringGood &st, const stringGood &st2);
	friend bool operator>(const stringGood &st, const stringGood &st2);
	friend bool operator==(const stringGood &st, const stringGood &st2);
	friend std::istream & operator>>(std::istream & is, stringGood & st);
// static function
	static int HowMany() { return num_strings; };
	~stringGood();               // destructor
// friend function
	friend std::ostream & operator<<(std::ostream & os,
					   const stringGood & st);
};

