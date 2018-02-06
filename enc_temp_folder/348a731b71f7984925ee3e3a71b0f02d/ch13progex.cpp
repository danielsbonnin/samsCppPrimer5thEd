#include "stdafx.h"
#include "ch13progex.h"
#include "dma.h"
#include <iostream>
using namespace std;
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strncpy(performers, s1, strlen(s1));
	performers[strlen(s1)] = '\0';
	strncpy(label, s2, strlen(s2) + 1);
	label[strlen(s2)] = '\0';
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & d)
{
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	performers[strlen(d.performers)] = '\0';
	strcpy(label, d.label);
	label[strlen(d.label)] = '\0';
	selections = d.selections;
	playtime = d.playtime;
}
Cd::Cd()
{
	performers = new char[LEN];
	label = new char[LEN];
	strncpy(performers, "None", LEN - 1);
	performers[LEN - 1] = '\0';
	strncpy(label, "None", LEN - 1);
	label[LEN - 1] = '\0';
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}
void Cd::Report() const
{
	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "# selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	performers[strlen(d.performers)] = '\0';
	strcpy(label, d.label);
	label[strlen(d.label)] = '\0';
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic() : Cd()
{
	primaryWork = new char[LEN];
	strncpy(primaryWork, "None", LEN - 1);
	primaryWork[LEN - 1] = '\0';
}
Classic::Classic(const Classic & c) : Cd(c)
{
	primaryWork = new char[strlen(c.primaryWork) + 1];
	strcpy(primaryWork, c.primaryWork);
	primaryWork[strlen(c.primaryWork)] = '\0';
}
Classic::Classic(const char * pw, const char * perf, const char * lab, int sel, double pt)
	: Cd(perf, lab, sel, pt)
{
	primaryWork = new char[strlen(pw) + 1];
	strcpy(primaryWork, pw);
	primaryWork[strlen(pw)] = '\0';
}

Classic & Classic::operator=(const Classic & c)
{
	if (this == &c)
		return *this;
	Cd::operator=(c);
	delete[] primaryWork;
	primaryWork = new char[strlen(c.primaryWork) + 1];
	strcpy(primaryWork, c.primaryWork);
	primaryWork[strlen(c.primaryWork)] = '\0';
	return *this;
}

Classic::~Classic()
{
	delete[] primaryWork;
}

void Classic::Report() const
{
	Cd::Report();
	cout << "Primary Work: " << primaryWork << endl;
}

void Bravo(const Cd & disk);
void ex13_1()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	
	cout << "Using object directly:\n";
	c1.Report();     // use Cd method
	c2.Report();     // use Classic method
	
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();   // use Cd method for cd object
	pcd = &c2;
	pcd->Report();   // use Classic method for classic object

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	
}

void Bravo(const Cd & disk)
{
	disk.Report();
}

void ex13_2()
{
	/*
	Do Programming Exercise 1, but use dynamic memory allocation instead of fixed-size
	arrays for the various strings tracked by the two classes
	*/
	ex13_1();
}

const int numDmas = 4;
const int LAB_LEN = 40;
void ex13_3()
{
	baseDMA * dmas[numDmas];

	int i;
	for (i = 0; i < numDmas; i++)
	{
		char temp[LAB_LEN + 1];
		int tempnum;
		char color_or_style[LAB_LEN + 1];
		char kind;
		cout << "Enter label: ";
		cin.getline(temp, LAB_LEN);
		cout << "Enter a rating: ";
		cin >> tempnum;
		cout << "Enter 1 for lacksDMA or "
			<< "2 for hasDMA: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";
		while (cin.get() != '\n')
			continue;
		if (kind == '1')
		{
			cout << "You have chosen to enter a lacksDMA object\n";
			cout << "Enter a color: ";
			cin.getline(color_or_style, LAB_LEN);
			dmas[i] = new lacksDMA(color_or_style, temp, tempnum);
		}
		else
		{
			cout << "You have chosen to enter a hasDMA object\n";
			cout << "Enter a style: ";
			cin.getline(color_or_style, LAB_LEN);
			dmas[i] = new hasDMA(color_or_style, temp, tempnum);
		}
	}
	cout << endl;
	for (i = 0; i < numDmas; i++)
	{
		dmas[i]->View();
	}
	for (i = 0; i < numDmas; i++)
	{
		delete dmas[i];   // free memory
	}
	cout << "Done.\n";
}

Port::Port(const char * br, const char * st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 19);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if (&p == this)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	bottles = p.bottles;
	return *this;
}

Port & Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}

void Port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort() : Port()
{
	nickname = new char[5];
	strcpy(nickname, "none");
	year = -1;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b), year(y)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete[] nickname;
	year = vp.year;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
	os << (Port &)vp << endl;
	os << "Nickname: " << vp.nickname << endl;
	return os;
}

void ex13_4()
{
	// a. Port definitions above
	// b. The destructor is redefined to handle new dma
	// the new data member: year requires updated constructors,
	//		assignment operator, and << operator
	// c. operator=() is not virtual because its function signature
	// will never conflict with that of it's ancestors. There is no
	// point. operator<<() is not virtual because it is not a class member.
	// d. see above
	Port * ports[4] = {
		new Port(), new VintagePort("brand", 2, "nickname", 1982), new Port(), new VintagePort()
	};
	for (int i = 0; i < 4; ++i)
		ports[i]->Show();
	cout << "copying 2nd Port to 4th Port" << endl;
	(VintagePort &)*ports[3] = (VintagePort &)*ports[1];
	for (int i = 0; i < 4; ++i)
		ports[i]->Show();
	for (int i = 0; i < 4; ++i)
		delete ports[i];
}


