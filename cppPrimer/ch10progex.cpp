#include "stdafx.h"
#include "Account.h"
#include "sales.h"
#include "Sales1.h"
#include "Plorg.h"
#include "ch10progex.h"
#include "Golf3.h"
#include "stack.h"
#include "List.h"
#include <iostream>
#include <string>
#include <cstring>
/*
Review questions
1. What is a class?
	A collection of variables and methods in a special scope, that represent a data object.
	It provides data storage information, and methods that use that data.
2. How does a class accomplish abstraction, encapsulation, and data hiding?
	Abstraction: By providing a more or less generic interface, that can accomodate a range of user options
	encapsulation: By separating the details of implementation from the user-facing interface
	data hiding: By limiting user access to private variables, enforcing the use of the interface.
3. What is the relationship between an object and a class?
	A class is a definition, specifying variables and methods of a type of object.
	An object is an instance of its class, having the specified variables and methods defined by the class definition.
4. In what way, aside from being functions, are class function members different from class
	data members?
	In a program, there is only one copy of the class function members, used by all instances of the class. 
	Each instance of the class has its own unique copy of each data member, though. 
5. Define a class to represent a bank account. Data members should include the depositor's
	name, the account number (use a string), and the balance. Member functions should
	allow the following:
		* Creating an object and initializing it.
		* Displaying the depositor's name, account number, and balance
		* Depositing an amount of money given by an argument
		* Withdrawing an amount of money given by an argument
		
	Just show the class declaration, not the method implemementation. (Programming
	Exercise 1 provides you with an opportunity to write the implemenentation.)

	class Account
	{
		enum {Len = 60};
		char * name[60];
		char * accno[60];
		double balance;
	public:
		Account();
		Account(const char * thename, const char * account, double balance);
		void show(void) const;
		bool deposit(double amt);
		double withdraw(double amt);
	}
6. When are class constructors called? When are class destructors called?
	Constructors are called when the object is declared. If not explicitly called, the default constructor is used.
	Destructors are called when the object passes out of scope or is explicity deleted when created with keyword new.
7. Provide code for a constructor for the bank account class from Review Question 5.
	Account::Account(const char * theName, const char * theAccNo, double bal)
	{
		strncpy(name, theName, Len - 1);
		name[Len - 1] = '\0';
		strncpy(accno, theAccNo, Len - 1);
		accno[Len - 1] = '\0';
		balance = bal;
	}
8. What is a default constructor? What is the advantage of having one?
	A constructor with 0 formal parameters, or all default parameters. Can initialize an object with reasonable values.

9. Modify the Stock class (the version in stock2.h) so that is has member functions that
	return the values of the individual data members. Note: A member that returns the com-
	pany name should not provide a weapon for altering the array. That is, it can't simply 
	return a char *. It could return a const pointer, or it could return a pointer to a copy of
	the array, manufactured by using new.
		// stocks.h
		#pragma once
		class Stock   // class declaration
		{
		private:
			char company[30];
			int shares;
			double share_val;
			double total_val;
			void set_tot() { total_val = shares * share_val; }
		public:
			Stock();
			Stock(const char * co, int n = 0, double pr = 0.0);
			~Stock();
			const Stock & topval(const Stock & s) const;
			void acquire(const char * co, int n, double pr);
			void buy(int num, double price);
			void sell(int num, double price);
			void update(double price);
			void show();
			const char * getCompany() const;
			int getShares() const;
			double getShareVal() const;
			double getTotalVal() const;
		};    // note semicolon at the end


		// stocks.cpp
		#include "stdafx.h"
		#include <iostream>
		#include <cstring>
		#include "stocks.h"


		void Stock::acquire(const char * co, int n, double pr)
		{
			std:strncpy(company, co, 29);  // truncate co to fit company
			company[29] = '\0';
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

		void Stock::show()
		{
			using std::cout;
			using std::endl;
			cout << "Company: " << company
				<< "  Shares: " << shares << endl
				<< "  Share Price: $" << share_val
				<< "  Total Worth: $" << total_val << endl;
		}

		Stock::Stock()
		{
			std::cout << "Default constructor called\n";
			std::strcpy(company, "no name");
			shares = 0;
			share_val = 0.0;
			total_val = 0.0;
		}

		Stock::Stock(const char * co, int n, double pr)
		{
			//std::cout << "Constructor using " << co << " called\n";
			std::strncpy(company, co, 29);
			company[29] = '\0';
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
		// class destructor
		Stock::~Stock()        // verbose class destructor
		{
			//std::cout << "Bye, " << company << "!\n";
		}

		const Stock & Stock::topval(const Stock & s) const
		{
			if (s.total_val > total_val)
				return s;          // argument object
			else
				return *this;      // invoking object
		}

		const char * Stock::getCompany()
		{
			const char * ptr;
			ptr = company;
			return ptr;
		}
		int Stock::getShares() 
		{
			return shares;
		}
		double Stock::getShareVal()
		{
			return share_val;
		}
		double Stock::getTotalVal()
		{
			return total_val;
		}

10. What are this and *this?

	"this" is a pointer to the current object's address in memory, which is only available to class methods. 
	"*this" is the dereferenced pointer, referring to the object's data, and 
	enabling the "." operator.
*/
void ex10_1()
{
	Account a = Account();
	a.show();
	Account b = Account("This is a manually entered account name", "11111111", 999.99);
	b.show();
	a.deposit(10.6);
	a.show();
	a.withdraw(10.5);
	a.show();
	b.withdraw(999.0);
	b.show();

}

void Person::Show() const
{
	std::cout << fname << " " << lname << std::endl;
}
void Person::FormalShow() const
{
	std::cout << lname << ", " << fname << std::endl;
}
Person::Person(const std::string & ln, const char * fn)
{
	lname = ln;
	strncpy(fname, fn, LIMIT - 1);
	fname[LIMIT - 1] = '\0';
}

void ex10_2()
{	
	using namespace std;
	Person one;                          // use default constructor
	Person two("Smythecraft");           // use #2 with one default argument
	Person three("Dimwiddy", "Sam");     // use #2, no defaults
	one.Show();
	cout << endl;
	one.FormalShow();
	two.Show();
	cout << endl;
	two.FormalShow();
	cout << endl;
	three.Show();
	cout << endl;
	three.FormalShow();
	cout << endl;
}
/*
3. Do Programming Exercise 1 from Chapter 9, but replace the code shown there with an
appropriate  golf class declaration. Replace  setgolf(golf &, const char *, int)
with a constructor with the appropriate argument for providing initial values. Retain the
interactive version of  setgolf() , but implement it by using the constructor. (For exam-
ple, for the code for  setgolf() , obtain the data, pass the data to the constructor to cre-
ate a temporary object, and assign the temporary object to the invoking object, which is
*this .)
*/
void ex10_3()
{
	using namespace std;
	const int golfersLen = 10;
	Golf3 golfers[golfersLen];
	int i = 0;
	for (i; i < golfersLen; ++i)
	{
		std::cout << "Golfer: " << i + 1 << std::endl;
		if (!golfers[i].setGolf())
		{
			i--;
			break;
		}
	}
	if (i < 0) return;
	std::cout << "You entered the following golfers:\n";
	for (int j = 0; j <= i; ++j)
		golfers[j].showGolf();
	for (int j = 0; j <= i; ++j)
		golfers[j].setHandicap(j);
	std::cout << "After resetting handicaps: \n";
	for (int j = 0; j <= i; ++j)
		golfers[j].showGolf();
	return;
}
/*
Do Programming Exercise 4 from Chapter 9, but convert the  Sales structure and its
associated functions to a class and its methods. Replace the  setSales(Sales &, double
[], int) function with a constructor. Implement the interactive  setSales(Sales &)
method by using the constructor. Keep the class within the namespace  SALES
*/
void ex10_4()
{
	using namespace SALES;
	Sales1 s;
	s.showSales();
	s.setSales();
	s.showSales();
}


void ex10_5()
{
	using namespace std;
	double balance = 0.0;
	struct customer arr[3] = { { "Al", 1 }, { "Bob", 3 }, { "Chuck", 5 } };
	Stack s;
	for (auto i : arr)
	{
		s.push(i);
		balance += i.payment;
		cout << "Adding " << i.fullname << " to stack. Balance is now: " << balance << endl;
	}
	struct customer c;
	while (s.pop(c))
	{
		balance -= c.payment;;
		cout << "Popping " << c.fullname << " from stack. Balance is:  " << balance << endl;

	}

}
class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0) { x = a; y = b; }
	void showmove() const {std::cout << "x: " << x << " y: " << y << std::endl;}
	Move add(const Move & m) const { return Move(m.x + this->x, m.y + this->y); }
	// this function adds x of m to x of invoking object to get new x,
	// adds y of m to y of invoking object to get new y, creates a new
	// move object initialized to new x, y values and returns it
	void reset(double a = 0, double b = 0) { x = a; y = b; }
};

void ex10_6()
{
	Move m1 = Move();  // (0, 0)
	m1.showmove();
	Move m2 = Move(2, 2);
	m2.showmove();
	Move m3 = Move(3, 3);
	m3.showmove();
	Move m4 = m2.add(m3);
	m4.showmove();
}
void ex10_7()
{
	using namespace std;
	cout << "Creating new default Plorg\n";
	Plorg p = Plorg();
	p.print();
	cout << "Setting CI to 5\n";
	p.setCI(5);
	p.print();
	cout << "Using constructor to create Plorg named Bob\n";
	p = Plorg("Bob");
	p.print();
}

template <typename T>
void showItem(T t)
{
	std::cout << "Item: " << t << " ";
}

template <typename T>
void addOne(T t)
{
	t++;
}
void ex10_8()
{
	using std::cout;
	using std::endl;
	using namespace LIST;
	cout << "Creating a List: ";
	List l = List();
	cout << "Adding 1 to List:\n";
	l.add(1);
	l.visit(&showItem);
	cout << "\nAdding 9 more\n";
	for (int i = 2; i <= 10; ++i)
		l.add(i);
	l.visit(&showItem);
	cout << "\nIncrementing all items: \n";
	l.visit(&addOne);
	cout << endl;
	l.visit(&showItem);
	cout << endl;
	cout << "isFull(): " << l.isFull() << endl;
}