#include "stdafx.h"
#include "golf2.h"
#include <iostream>
#include <string>

namespace golf2
{
	void setgolf(golf & g, std::string name, int hc)
	{
		g.fullname = name;
		g.handicap = hc;
		return;
	}

	int setgolf(golf & g)
	{
		using namespace std;
		string name = "";
		int handicap = 0;
		cout << "Enter the golfer's name: ";
		getline(cin, name);
		if (name.length() == 0)
		{
			cout << "You entered a blank name.\n";
			return 0;
		}

		cout << "Enter the golfer's handicap: ";
		while (!(cin >> handicap))
		{
			std::cin.clear();
			cin.get();
			std::cout << "Enter a number: ";
		}
		cin.get();
		g.fullname = name;
		g.handicap = handicap;
		return 1;
	}

	void handicap(golf & g, int hc)
	{
		g.handicap = hc;
		return;
	}

	void showgolf(const golf2::golf & g)
	{
		std::cout << "Name: " << g.fullname << ". Handicap: " << g.handicap << std::endl;
		return;
	}
}