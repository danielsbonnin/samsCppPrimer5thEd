#pragma once
#include <iostream>
class complex0
{
	double real;
	double imag;
public:

	complex0();
	complex0(double, double);
	//~complex0();
	complex0 operator*(const complex0 &) const;
	complex0 operator*(double m) const;
	friend complex0 operator*(double m, const complex0 & c);
	complex0 operator+(const complex0 &) const;
	complex0 operator-(const complex0 &) const;
	complex0 operator~() const;
	friend std::ostream & operator<<(std::ostream & os, const complex0 & c);
	friend std::istream & operator>>(std::istream & os, complex0 & c);
};

