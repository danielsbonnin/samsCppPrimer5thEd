#include "stdafx.h"
#include "ch13progex.h"
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
void ex13_3()
{

}
void ex13_4()
{

}
