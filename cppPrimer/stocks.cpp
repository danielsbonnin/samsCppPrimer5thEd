#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "stocks.h"


void Stock::acquire(const char * co, int n, double pr)
{
	std:strncpy(company, co, 29);  // truncate co to fit company
	delete[] company;
	company = new char[strlen(co) + 1];
	strcpy(company, co);
	if (n < 0)
	{
		std::cerr << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		std::cerr << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0)
	{
		cerr << "Number of shares sold can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cerr << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
	using std::cout;
	using std::endl;
	os << "Company: " << s.company
		<< "  Shares: " << s.shares << endl
		<< "  Share Price: $" << s.share_val
		<< "  Total Worth: $" << s.total_val << endl;
	return os;
}

Stock::Stock()
{
	company = new char[1];
	company[0] = '\0';
	std::cout << "Default constructor called\n";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr)
{
	//std::cout << "Constructor using " << co << " called\n";
	company = new char[strlen(co) + 1];
	std::strcpy(company, co);
	if (n < 0)
	{
		std::cerr << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

// copy constructor
Stock::Stock(const Stock & s)
{
	company = new char[strlen(s.company) + 1];
	strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
}
// class destructor
Stock::~Stock()        // verbose class destructor
{
	delete[] company;
}

Stock & Stock::operator=(const Stock & s)
{
	if (&s == this)
		return *this;
	using std::cout;
	delete[] company;
	company = new char[strlen(s.company) + 1];

	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
	strcpy(company, s.company);
	
	company[strlen(s.company)] = '\0';

	return *this;
}
const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;          // argument object
	else
		return *this;      // invoking object
}

const char * Stock::getCompany() const
{
	const char * ptr;
	ptr = company;
	return ptr;
}
int Stock::getShares() const
{
	return shares;
}
double Stock::getShareVal() const
{
	return share_val;
}
double Stock::getTotalVal() const
{
	return total_val;
}