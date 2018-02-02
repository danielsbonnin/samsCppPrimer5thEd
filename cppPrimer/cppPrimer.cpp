// cppPrimer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ch3progex.h"
#include "ch4progex.h"
#include "ch5progex.h"
#include "ch6progex.h"
#include "ch7progex.h"
#include "ch8progex.h"
#include "ch9progex.h"
#include "ch11progex.h"
#include "ch12progex.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <new>
#include "stocks.h"
#include "mytime0.h"
#include "vect.h"
#include "stonewt.h"
#include "tabtenn0.h"
#include "Brass.h"
using namespace std;
const int CLIENTS = 4;
const int LEN = 40;
int main(void)
{
	AcctABC * p_clients[CLIENTS];

	int i;
	for (i = 0; i < CLIENTS; i++)
	{
		char temp[LEN];
		long tempnum;
		double tempbal;
		char kind;
		cout << "Enter client's name: ";
		cin.getline(temp, LEN);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening balance: $";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or "
			<< "2 for BrassPlus Account: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cout << "Enter the interest rate "
				<< "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
				tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];  // free memory
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}
