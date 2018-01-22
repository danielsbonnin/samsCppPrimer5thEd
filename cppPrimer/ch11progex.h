#pragma once
/*
CH 11 Review Questions

1. Use a member function to overload the multiplication operator for the Stonewt class;
have the operator multiply the data members by a type double value. Note that this will
require carryover for the stone-pound representation. That is, twice 10 stone 8 pounds
is 21 stone 2 pounds.

	Stonewt Stonewt::operator*(double f) const
	{
		return Stonewt(pounds * f);
	}

2. What are the differences between a friend function and a member function?
	
	Unlike a member function, a friend function is not invoked via the . operator, 
	and does not require the first argument to be of "this" type. The friend function 
	must explicity access members via the membership operator applied to an object
	passed as an argument.

3. Does a nonmember function have to be a friend to access a class's members?
	
	A non member function may only access a class's public members where a friend
	function may access all the class members.

4. Use a friend function to overload the multiplication operator for the Stonewt class; have
	the operator multiply the double value by the Stone value.

	Stonewt operator*(double x, const Stonewt & y)
	{
		return Stonewt(x * y.pounds);
	}

5. Which operators cannot be overloaded?

	sizeof, ., .*, ::, ?:, typeid, const_cast, dynamic_cast, reinterpret_cast, static_cast

6. What restriction applies to overloading the following operators? =, (), [], and ->

	Only member functions can be used to overload these: no friend functions.

7. Define a conversion function for the Vector class that converts a Vector object to a type
	double value that represents the vector's magnitude.

	Vector::operator double() const
	{
		return mag;
	}
*/
void ex11_1();
void ex11_2();
void ex11_2();
void ex11_3();
void ex11_4();
void ex11_5();
void ex11_6();
void ex11_7();