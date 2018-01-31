#include "stdafx.h"
#include "Stack2.h"
#include <iostream>
using namespace std;
Stack2::Stack2(int n)
{
	n = (n > 10) ? 10 : n;
	n = (n < 1) ? 1 : n;
	pitems = new Item1[n];
	size = n;
	top = -1;
}
Stack2::Stack2(const Stack2 & st)
{
	pitems = new Item1[st.size];
	size = st.size;
	top = st.top;
	for (int i = 0; i <= top; ++i)
		pitems[i] = st.pitems[i];
}

Stack2::~Stack2()
{
	delete[] pitems;
}
bool Stack2::isempty() const
{
	return top == -1;
}
bool Stack2::isfull() const
{
	return top == size - 1;
}
// push() returns false if stack already is full, true otherwise
bool Stack2::push(const Item1 & item)
{
	if (isfull())
		return false;
	pitems[++top] = item;
	return true;
}
bool Stack2::pop(Item1 & item)
{
	if (isempty())
		return false;
	item = pitems[top--];
	return true;
}
Stack2 & Stack2::operator=(const Stack2 & st)
{
	delete[] pitems;
	pitems = new Item1[st.size];
	size = st.size;
	top = st.top;
	for (int i = 0; i <= top; ++i)
		pitems[i] = st.pitems[i];
	return *this;
}

ostream & operator<<(ostream & os, Stack2 & st)
{
	os << "Stack contents: ";
	for (int i = 0; i <= st.top; ++i)
	{
		os << st.pitems[i] << " ";
	}
	os << endl;
	return os;
}


