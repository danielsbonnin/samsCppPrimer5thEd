#include "stdafx.h"
#include "ch6progex.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;
void ex6_1(void)
{
	char ch;
	while (cin.get(ch) && ch != '@')
	{
		if (isalpha(ch))
		{
			ch = char(islower(ch) ? toupper(ch) : tolower(ch));
		}
		if (!isdigit(ch))
			cout << char(ch);

	}
	return;
}
void ex6_2(void)
{
	double donations[10];
	double cur, sum, avg;
	cur = sum = avg = 0;
	int count = 0;
	int ltAverage = 0;
	cout << "Enter up to 10 numeric values (enter non-numeric value to stop): " << endl;
	while (count < 10 && cin >> cur)
	{
		donations[count] = cur;
		count++;
		cout << "Enter number or other to quit: " << endl;
	}
	for (int i = 0; i < count; ++i)
	{
		sum += donations[i];
	}
	if (sum != 0) avg = sum / count;
	for (int i = 0; i < count; ++i)
	{
		if (donations[i] > avg)
			ltAverage++;
	}
	cout << "Avg: " << avg << " Count > avg: " << ltAverage << endl;
	return;
}
void ex6_3(void)
{
	char ch;
	cout << "Please enter one of the following choices:" << endl;
	cout << "c) carnivore          p) pianist" << endl;
	cout << "t) tree               g) game" << endl;
	cin >>  ch;
	while (ch != 'c' && ch != 'p' && ch != 't' && ch != 'g')
	{
		cout << "Please enter a c, p, t, or g: ";
		cin >> ch;
	}
	switch (ch)
	{
		case 'c':
			cout << "A lion is a carnivore\n";
			break;
		case 'p':
			cout << "Emmanuel Axe is a pianist\n";
			break;
		case 't':
			cout << "A maple is a tree.\n";
			break;
		case 'g':
			cout << "Monopoly is a game.\n";
			break;
		default:
			cout << "An error occurred\n";
	}
	return;
}
void ex6_4(void)
{
	const int strsize = 80;
	enum preference {fullname, title, bopname};
	enum displayMode { name, ttl, bopn, pref };
	int memberCount = 3;
	struct bop {
		char fullname[strsize];  // real name
		char title[strsize];     // job title
		char bopname[strsize];   // secret BOP name
		int preference;          // 0 = fullname, 1 = title, 2 = bopname
	};
	bop members[] = {
		{"Daniel Bonnin", "Dad", "Darnell", bopname}, 
		{"Nadiah AM Bonnin", "Mom", "Nad", fullname},
		{"M E D", "Firstborn", "Emir", title}
	};
	char choice;
	displayMode cur = name;
	cout << "Benevolent Order of Programmers Report\n"
		"a. display by name       b. display by title\n"
		"c. display by bopname    d. display by preference\n"
		"q. quit\n";
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice != 'q')
	{
		while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'q')
		{
			cout << "Please enter a, b, c, d, or q: ";
			cin >> choice;
		}
		switch (choice)
		{
			case 'a':
				cur = name;
				break;
			case 'b':
				cur = ttl;
				break;
			case 'c':
				cur = bopn;
				break;
			case 'd':
				cur = pref;
				break;
			case 'q':
				continue;
				break;
			default:
				cout << "An error occurred" << endl;
				continue;
		}
		for (int i = 0; i < memberCount; ++i)
		{
			switch (cur)
			{
				case name:
					cout << members[i].fullname << endl;
					break;
				case ttl:
					cout << members[i].title << endl;
					break;
				case bopname:
					cout << members[i].bopname << endl;
					break;
				case pref:
					switch (members[i].preference)
					{
						case fullname:
							cout << members[i].fullname << endl;
							break;
						case title:
							cout << members[i].title << endl;
							break;
						case bopname:
							cout << members[i].bopname << endl;
							break;
						default:
							cout << "An error occurred printing this member's preference\n";
							break;
					}
					break;
			}
		}
		cout << "Next choice: ";
		cin >> choice;
	} 
	cout << "Bye!" << endl;
	return;
}
void ex6_5(void)
{
	const double hiBracket = 35000;
	const double midBracket = 15000;
	const double loBracket = 5000;
	double incomeInput, hi, mid, lo;
	incomeInput = hi = mid = lo = 0.0;
	cout << "Please enter an income: ";
	while (cin >> incomeInput && incomeInput >= 0.0)
	{
		hi = mid = lo = 0.0;
		if (incomeInput > loBracket)
		{
			if (incomeInput > midBracket)
			{
				lo = 10000;
				if (incomeInput > hiBracket) {
					mid = 20000;
					hi = incomeInput - hiBracket;
				}
				else
				{
					mid = incomeInput - midBracket;
				}
			}
			else
				lo = incomeInput - loBracket;
		}
		cout << "Taxes owed on " << incomeInput << ": $" << lo * 0.1 + mid * 0.15 + hi * 0.2 << endl;
		cout << "Enter another income or anykey/neg number to quit\n";
	}
	return;
}
void ex6_6(void)
{
	struct Patron
	{
		string name;
		double contribution;
	};
	int numPatrons = 0;
	cout << "Enter the number of patrons: ";
	while (!(cin >> numPatrons))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Enter a number: ";
	}
	
	Patron * patrons = new Patron[numPatrons];
	double contribInput = 0;
	for (int i = 0; i < numPatrons; ++i)
	{
		cin.get();
		cout << "Enter the patron's name: ";
		getline(cin, patrons[i].name);
		cout << "Enter the patron's contribution: ";
		while (!(cin >> contribInput))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Enter a number: ";
		}
		patrons[i].contribution = contribInput;
	}
	cout << "Grand Patrons" << endl;
	bool none = true;
	for (int i = 0; i < numPatrons; ++i)
	{
		if (patrons[i].contribution >= 10000)
		{
			none = false;
			cout << patrons[i].name << endl;
		}
	}
	if (none) cout << "None" << endl;
	cout << "\nPatrons" << endl;
	none = true;
	for (int i = 0; i < numPatrons; ++i)
	{
		if (patrons[i].contribution < 10000)
		{
			none = false;
			cout << patrons[i].name << endl;
		}
	}
	if (none) cout << "None" << endl;
	cout << "bye!" << endl;
	delete[] patrons;


	return;
}
void ex6_7(void)
{
	cout << "Enter words (q to quit)" << endl;
	int vWords = 0;
	int cWords = 0;
	int otherWords = 0;
	bool vowel, consonant, other;
	vowel = consonant = other = false;
	const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

	string word;
	while (cin >> word && word.compare("q"))
	{
		vowel = consonant = other = false;
		if (isalpha(word[0]))
		{
			for (int i = 0; i < 5; ++i)
				if (vowels[i] == word[0])
				{
					vowel = true;
					vWords++;
					break;
				}
			if (!vowel)
			{
				consonant = true;
				cWords++;
			}
		}
		else
		{
			other = true;
			otherWords++;
		}
	}
	cout << vWords << " words beginning with vowels" << endl;
	cout << cWords << " words beginning with consonants" << endl;
	cout << otherWords << " others" << endl;
	return;
}
void ex6_8(void)
{
	ifstream fin;
	fin.open("ex6_8.txt");
	while (fin.good())
		cout << char(fin.get());
	fin.close();
	return;
}
void ex6_9(void)
{
	struct Patron
	{
		string name;
		double contribution;
	};
	ifstream fin;
	fin.open("ex6_9.txt");
	int numPatrons = 0;
	if (!(fin >> numPatrons))
	{
		cout << "There was an error getting numPatrons\n";
		fin.close();
		return;
	}
	fin.get();
	char ch;
	Patron * patrons = new Patron[numPatrons];
	double contribInput = 0;
	for (int i = 0; i < numPatrons; ++i)
	{
		if (!(getline(fin, patrons[i].name))) {
			cout << "There was an error getting patron " << i << "'s name." << endl;
			fin.close();
			delete[] patrons;
			return;
		}
		
		if (!(fin >> contribInput))
		{
			cout << "There was an error getting patron " << i << "'s contribution." << endl;
			fin.close();
			delete[] patrons;
			return;
		}
		patrons[i].contribution = contribInput;
		while (fin.get() != '\n' && fin.good())
			continue;
	}
	cout << "Grand Patrons" << endl;
	bool none = true;
	for (int i = 0; i < numPatrons; ++i)
	{
		if (patrons[i].contribution >= 10000)
		{
			none = false;
			cout << patrons[i].name << endl;
		}
	}
	if (none) cout << "None" << endl;
	cout << "\nPatrons" << endl;
	none = true;
	for (int i = 0; i < numPatrons; ++i)
	{
		if (patrons[i].contribution < 10000)
		{
			none = false;
			cout << patrons[i].name << endl;
		}
	}
	if (none) cout << "None" << endl;
	cout << "bye!" << endl;
	delete[] patrons;
	fin.close();


	return;
}