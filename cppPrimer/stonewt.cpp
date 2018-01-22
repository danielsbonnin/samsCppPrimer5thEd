#include "stdafx.h"
#include "stonewt.h"
#include <iostream>
using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;    // integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	form = 's';
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	form = 's';
}

Stonewt::Stonewt()               // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
	form = 's';
}

Stonewt::~Stonewt()              // destructor
{
}

// set form
bool Stonewt::setForm(char f)
{
	if (f == 's')
	{
		form = f;
		return true;
	}
	else if(f == 'i')
	{
		form = f;
		return true;
	}
	else if(f == 'f')
	{
		form = f;
		return true;
	}
	else
		return false;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
	if (s.form == 's')
		os << s.stone << " stones, and " << s.pds_left << " pounds.";
	else if (s.form == 'i')
		os << int(s.pounds) << " pounds.";
	else
		os << s.pounds << " pounds.";
	return os;
}
// show weight in pounds
void Stonewt::show_lbs() const
{
	cout << pounds << " pounds\n";
}

void Stonewt::show_stn() const
{
	cout << stone << " stone, " << pds_left << " pounds\n";
}


// conversion functions
Stonewt::operator int() const
{
	return int(pounds + 0.5);
}

Stonewt::operator double() const
{
	return pounds;
}

Stonewt Stonewt::operator*(double f) const
{
	Stonewt ret(pounds * f);
	ret.setForm(form);
	return ret;
}

Stonewt operator*(double x, const Stonewt & y)
{
	Stonewt ret(y.pounds * x);
	ret.setForm(y.form);
	return ret;
}

Stonewt Stonewt::operator*(const Stonewt & s) const
{
	Stonewt ret(pounds * s.pounds);
	ret.setForm(form);
	return ret;
}

Stonewt Stonewt::operator+(const Stonewt & s) const
{
	Stonewt ret(pounds + s.pounds);
	ret.setForm(form);
	return ret;
}

Stonewt Stonewt::operator-(const Stonewt & s) const
{
	Stonewt ret(pounds - s.pounds);
	ret.setForm(form);
	return ret;
}