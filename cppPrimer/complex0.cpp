#include "stdafx.h"
#include "complex0.h"
#include <iostream>

complex0::complex0()
{
	real = 0.0;
	imag = 0.0;
}

complex0::complex0(double r, double i)
{
	real = r;
	imag = i;
}
complex0 complex0::operator*(const complex0 & c) const
{
	return complex0(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

complex0 complex0::operator*(double m) const
{
	return complex0(m * real, m * imag);
}

complex0 operator*(double m, const complex0 & c)
{
	return complex0(m * c.real, m * c.imag);
}
complex0 complex0::operator+(const complex0 & c) const
{
	return complex0(real + c.real, imag + c.imag);
}
complex0 complex0::operator-(const complex0 & c) const
{
	return complex0(real - c.real, imag - c.imag);
}

complex0 complex0::operator~() const
{
	return complex0(real, imag * -1);
}
std::ostream & operator<<(std::ostream & os, const complex0 & c)
{
	os << "(" << c.real << ", " << c.imag << "i)";
	return os;
}
std::istream & operator>>(std::istream & is, complex0 & c)
{
	double r, i;
	std::cout << "real: ";
	while (!(is >> r))
		return is;
	std::cout << "imaginary: ";
	if (!(is >> i))
		return is;
	c.real = r;
	c.imag = i;
	return is;
}
