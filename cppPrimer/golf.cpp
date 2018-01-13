#include "stdafx.h"
#include "golf.h"
#include <iostream>
namespace golf1
{
	void setgolf(golf & g, const char * name, int hc)
	{
		strcpy(g.fullname, name);
		g.handicap = hc;
		return;
	}

	int setgolf(golf & g)
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
		strcpy(g.fullname, name);
		g.handicap = handicap;
		return 1;
	}

	void handicap(golf & g, int hc)
	{
		g.handicap = hc;
		return;
	}

	void showgolf(const golf & g)
	{
		std::cout << "Name: " << g.fullname << ". Handicap: " << g.handicap << std::endl;
		return;
	}
}