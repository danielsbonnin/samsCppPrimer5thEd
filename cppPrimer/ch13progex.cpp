#include "stdafx.h"
#include "ch13progex.h"
#include <iostream>
using namespace std;
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	strcpy(performers, s1);
	performers[49] = '\0';
	strcpy(label, s2);
	label[19] = '\0';
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::Cd()
{
	strcpy(performers, "None");
	strcpy(label, "None");
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd()
{
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
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic() : Cd()
{
	strcpy(primaryWork, "None");
}
Classic::Classic(const Classic & c) : Cd(c)
{
	strcpy(primaryWork, c.primaryWork);
}
Classic::Classic(const char * pw, const char * perf, const char * lab, int sel, double pt)
	: Cd(perf, lab, sel, pt)
{
	strcpy(primaryWork, pw);
	primaryWork[LEN - 1] = '\0';
}

Classic & Classic::operator=(const Classic & c)
{
	if (this == &c)
		return *this;
	Cd::operator=(c);
	strcpy(primaryWork, c.primaryWork);
	return *this;
}

Classic::~Classic()
{
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

}
void ex13_3()
{

}
void ex13_4()
{

}
