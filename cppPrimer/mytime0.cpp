#include "stdafx.h"
#include "mytime0.h"
#include <iostream>
#include <fstream>
Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time & x, const Time & y)
{
	Time sum;
	sum.minutes = x.minutes + y.minutes;
	sum.hours = x.hours + y.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator-(const Time & x, const Time & y)
{
	Time diff;
	int tot1, tot2;
	tot1 = x.minutes + 60 * x.hours;
	tot2 = y.minutes + 60 * y.hours;
	diff.minutes = (tot1 - tot2) % 60;
	diff.hours = (tot1 - tot2) / 60;
	return diff;
}

Time Time::operator*(double mult) const
{
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator*(double m, const Time & t)  // friend not used in definition
{
	Time result;
	long totalminutes = t.hours * m * 60 + t.minutes * m;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}

Time::~Time()
{
}
