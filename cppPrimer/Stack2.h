#pragma once
#include <iostream>
using namespace std;
typedef int Item1;
class Stack2
{
private:
	enum { MAX = 10 };        // constant specific to class
	Item1 * pitems;            // holds stack items
	int size;                 // number of elements in stack
	int top;                  // index for top stack item
public:
	Stack2(int n = 10);        // creates stack with n elements
	Stack2(const Stack2 & st);
	~Stack2();
	friend ostream & operator<<(ostream & os, Stack2 & st);
	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise
	bool push(const Item1 & item);  // add item to stack
	// pop() returns false if stack already is empty, true otherwise
	bool pop(Item1 & item);  // pop top into item
	Stack2 & operator=(const Stack2 & st);
};

