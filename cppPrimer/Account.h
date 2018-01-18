#pragma once
class Account
{
	enum { Len = 60 };
	char name[60];
	char accno[60];
	double balance;
public:
	Account();
	Account(const char * thename, const char * account, double balance);
	void show(void) const;
	bool deposit(double amt);
	double withdraw(double amt);
	~Account();
};

