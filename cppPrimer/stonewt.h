#pragma once
#include <iostream>
class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };      // pounds per stone
	int stone;                      // whole stones
	double pds_left;                // fractional pounds
	double pounds;                  // wntire weight in pounds
	char form;                      // 's': stone, 'i': integer pounds, 'f': float pounds
public:
	Stonewt(double lbs);            // constructor for double pounds 
	Stonewt(int stn, double lbs);   // constructor for stone, lbs
	Stonewt();                      // default constructor
	
	~Stonewt();
	bool setForm(char f);
	friend std::ostream & operator<<(std::ostream &, const Stonewt &);
	void show_lbs() const;          // show weight in pounds format
	void show_stn() const;          // show weight in stone format
	Stonewt operator*(double) const;// multiply by a double factor
	Stonewt operator*(const Stonewt &) const;
	friend Stonewt operator*(double x, const Stonewt & y);
	Stonewt operator+(const Stonewt &) const;
	Stonewt operator-(const Stonewt &) const;
	bool operator<(const Stonewt & x) const { return pounds < x.pounds; }
	bool operator>(const Stonewt & x) const { return pounds > x.pounds; }
	bool operator==(const Stonewt & x) const { return pounds == x.pounds; }
	bool operator<=(const Stonewt & x) const { return pounds <= x.pounds; }
	bool operator>=(const Stonewt & x) const { return pounds >= x.pounds; }
	bool operator!=(const Stonewt & x) const { return pounds != x.pounds; }
// conversion functions
	operator int() const;
	operator double() const;
};

