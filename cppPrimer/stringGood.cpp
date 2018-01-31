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
	num_strings++;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

stringGood::stringGood()
{
	num_strings++;
	str = new char[1];
	str[0] = '\0';
	len = 0;
}

// copy constructor
stringGood::stringGood(const stringGood & st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
}

stringGood::~stringGood()             // necessary destructor
{
	delete[] str;
	num_strings--;
}

// string mutate methods

void stringGood::stringlow()
{
	for (int i = 0; i < len; ++i)
		str[i] = tolower(str[i]);
}

int stringGood::has(char ch) const
{
	int count = 0;
	for (int i = 0; i < len; ++i)
		if (ch == str[i])
			count++;
	return count;
}

void stringGood::stringup()
{
	for (int i = 0; i < len; ++i)
		str[i] = toupper(str[i]);
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
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}

// assign a C string to a stringGood
stringGood & stringGood::operator=(const char * s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
stringGood stringGood::operator+(const stringGood & st) const
{
	stringGood temp;
	temp.len = len + st.len;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, str);
	strcpy(temp.str + len, st.str);
	temp.str[temp.len] = '\0';
	return temp;
}

stringGood operator+(const char * st, const stringGood & sg)
{
	int newlen = strlen(st) + sg.len;
	char * newstr = new char[newlen + 1];
	strcpy(newstr, st);
	strcpy(newstr + strlen(st), sg.str);

	stringGood temp(newstr);
	delete[] newstr;
	return temp;
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
