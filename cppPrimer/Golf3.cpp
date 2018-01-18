#include "stdafx.h"
#include "Golf3.h"
#include <iostream>
#include <cstring>

Golf3::Golf3(const char * name, int hc)
{
	strncpy(fullname, name, Len - 1);
	fullname[Len - 1] = '\0';
	handicap = hc;
}

int Golf3::setGolf()
{
	using namespace std;
	char name[Len];
	char nameInput[256];
	int handicap = 0;
	cout << "Enter the golfer's name: ";
	cin.getline(nameInput, Len);
	int  nameLen = strlen(nameInput);
	if (nameLen == 0)
	{
		cout << "You entered a blank name.\n";
		return 0;
	}
	else if (nameLen > Len)
	{
		cout << "Name must be less than " << Len << " characters\n";
		return 0;
	}
	else
		strcpy(name, nameInput);
	std::cout << "The name you entered was " << nameLen << " characters long\n";

	std::cout << "Enter the golfer's handicap: ";
	while (!(cin >> handicap))
	{
		std::cin.clear();
		cin.get();
		std::cout << "Enter a number: ";
	}
	cin.get();
	Golf3 g = Golf3(name, handicap);
	*this = g;
	return 1;
}

void Golf3::setHandicap(int hc)
{
	handicap = hc;
}

void Golf3::showGolf() const
{
	std::cout << "Golfer's full name: " << fullname << " Handicap: " << handicap << std::endl;
}
Golf3::~Golf3()
{
}
