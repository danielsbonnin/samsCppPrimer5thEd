#include "stdafx.h"
#include "stringGood.h"
#include <cstring>
using std::cout;
using std::cin;

// initializing static class member
int stringGood::num_strings = 0;

// class methods

// construct stringGood from C string
stringGood::stringGood(const char * s)
{
	len = std::strlen(s);                     // set size
	str = new char[len + 1];                  // allot storage
	std::strcpy(str, s);                      // initialize pointer
	num_strings++;                            // set object count
}

stringGood::stringGood()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';         // default string
	num_strings++;
}

// copy constructor
stringGood::stringGood(const stringGood & st)
{
	num_strings++;                  // handle static member update
	len = st.len;                   // same length
	str = new char[len + 1];        // allot space
	std::strcpy(str, st.str);       // copy string to new location
}

stringGood::~stringGood()             // necessary destructor
{
	--num_strings;                    // required
	delete[] str;                     // required
}

// overloaded operator methods

bool operator<(const stringGood &st1, const stringGood &st2)
{
	if (std::strcmp(st1.str, st2.str) < 0)
		return true;
	else
		return false;
}

bool operator>(const stringGood &st1, const stringGood &st2)
{
	return st2.str < st1.str;
}

bool operator==(const stringGood & st1, const stringGood & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

// read-write char access for non-const stringGood
char & stringGood::operator[](int i)
{
	return str[i];
}

// read-only char access for const stringGood
const char & stringGood::operator[](int i) const
{
	return str[i];
}

// assign a stringGood to a stringGood
stringGood & stringGood::operator=(const stringGood & st)
{
	if (this == &st)                // object assigned to itself
		return *this;
	delete[] str;                   // free old string
	len = st.len;
	str = new char[len + 1];        // get space for new string
	std::strcpy(str, st.str);       // copy the string
	return *this;                   // return reference to invoking object
}

// assign a C string to a stringGood
stringGood & stringGood::operator=(const char * s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const stringGood & st)
{
	os << st.str;
	return os;
}

// quick and dirty stringGood input
std::istream & operator>>(std::istream & is, stringGood & st)
{
	char temp[stringGood::CINLIM];
	is.get(temp, stringGood::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
