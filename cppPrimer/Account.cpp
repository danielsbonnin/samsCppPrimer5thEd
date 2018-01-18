#include "stdafx.h"
#include "Account.h"
#include <cstring>
#include <iostream>

Account::Account()
{
	strncpy(name, "Not Entered", Len);
	strncpy(accno, "00000000", Len);
	balance = 0.0;
}

Account::Account(const char * thename, const char * account, double bal)
{
	strncpy(name, thename, Len - 1);
	name[Len - 1] = '\0';
	strncpy(accno, account, Len - 1);
	name[Len - 1] = '\0';
	balance = bal;
}


Account::~Account()
{
}
void Account::show() const
{
	using namespace std;
	cout << "Name: " << name << " Account: " << accno << " Balance: $" << balance << endl;
}
bool Account::deposit(double amt)
{
	if (amt < 0)
		return false;
	balance += amt;
	return true;
}
double Account::withdraw(double amt)
{
	if (amt > balance)
		return false;
	balance -= amt;
	return true;
}