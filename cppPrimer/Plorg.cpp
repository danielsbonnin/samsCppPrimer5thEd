#include "stdafx.h"
#include "Plorg.h"
#include <iostream>

Plorg::Plorg(const char * thename)
{
	strncpy(name, thename, 19);
	name[19] = '\0';
	ci = 50;
}

void Plorg::print() const
{
	std::cout << "Name: " << name << ", Contentment Index: " << ci << std::endl;
}

Plorg::~Plorg()
{
}
