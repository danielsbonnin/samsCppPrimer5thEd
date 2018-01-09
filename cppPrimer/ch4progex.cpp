#include "stdafx.h"
#include <iostream>
#include <string>
#include "ch4progex.h"
using namespace std;

void ex4_1(void)
{
	char fNameTemp[80];
	char lNameTemp[80];
	int age = 0;
	char gradeInput = ' ';
	cout << "What is your first name? ";
	cin.getline(fNameTemp, 80);
	cout << "What is your last name? ";
	cin.getline(lNameTemp, 80);
	cout << "What letter grade do you deserve? ";
	cin >> gradeInput;
	cout << "What is your age? ";
	cin >> age;
	cout << "Name: " << lNameTemp << ", " << fNameTemp << endl;
	cout << "Grade: " << char(gradeInput + 1) << endl;
	cout << "Age: " << age << endl;
	return;
}

void ex4_2(void)
{
	string name, dessert;
	cout << "Enter your name:\n";
	getline(cin, name);
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return;
}

void ex4_3(void)
{
	char fName[80];
	char lName[80];
	char combined[160];
	const char sep[] = ", ";
	cout << "Enter your first name: ";
	cin.getline(fName, 80);
	cout << "Enter your last name: ";
	cin.getline(lName, 80);
	cout << "Here's the information in a single string: ";
	cout << strcat(lName, sep) << fName << endl;
	return;
}

void ex4_4(void)
{
	string fName, lName;
	cout << "Enter your first name: ";
	getline(cin, fName);
	cout << "Enter your last name: ";
	getline(cin, lName);
	cout << "Here's the information in a single string: ";
	lName += ", " + fName;
	cout << lName << endl;
	return;
}

void ex4_5(void)
{
	CandyBar snack = { "Mocha Munch", 2.3, 350 };
	cout << "Brand: " << snack.brand << endl;
	cout << "Weight: " << snack.weight << endl;
	cout << "Calories: " << snack.calories << endl;
	return;
}

void ex4_6(void)
{
	CandyBar bars[3] = { {"type one", 1.1, 1}, { "type two", 2.2, 2 }, { "type three", 3.3, 3 } };
	cout << "Bar 1: " << endl;
	cout << "Brand: " << bars[0].brand << endl;
	cout << "Weight: " << bars[0].weight << endl;
	cout << "Calories: " << bars[0].calories << endl;

	cout << "Bar 2: " << endl;
	cout << "Brand: " << bars[1].brand << endl;
	cout << "Weight: " << bars[1].weight << endl;
	cout << "Calories: " << bars[1].calories << endl;

	cout << "Bar 3: " << endl;
	cout << "Brand: " << bars[2].brand << endl;
	cout << "Weight: " << bars[2].weight << endl;
	cout << "Calories: " << bars[2].calories << endl;
	return;
}
void ex4_7(void) 
{
	string name;
	float diameter, weight;
	cout << "Enter the name of the pizza company: ";
	getline(cin, name);
	cout << "Enter the diameter of " << name << " ";
	cin >> diameter;
	cout << "Enter the weight of " << name << " ";
	cin >> weight;
	cout << "Name: " << name << endl;
	cout << "Diameter: " << diameter << endl;
	cout << "Weight: " << weight << endl;
	return;
}
void ex4_8(void) 
{
	string name;
	float diameter, weight;
	Pizza * pizza = new Pizza;
	cout << "Enter the diameter of a pizza: ";
	cin >> pizza->diameter;
	cin.ignore();
	cout << "Enter the name of the pizza company: ";
	getline(cin, pizza->name);
	cout << "Enter the weight of this pizza: ";
	cin >> pizza->weight;
	cout << "Name: " << pizza->name << endl;
	cout << "Diameter: " << pizza->diameter << endl;
	cout << "Weight: " << pizza->weight << endl;
	delete pizza;
	return;
}
void ex4_9(void)
{
	CandyBar * bars = new CandyBar[3];
	bars[0].brand = "type one";
	bars[0].weight = 1.1;
	bars[0].calories = 1; 
	
	bars[1].brand = "type two";
	bars[1].weight = 2.2;
	bars[1].calories = 2;
	
	bars[2].brand = "type three";
	bars[2].weight = 3.3;
	bars[2].calories = 3;

	//{"type one", 1.1, 1}, { "type two", 2.2, 2 }, { "type three", 3.3, 3 }
	cout << "Bar 1: " << endl;
	cout << "Brand: " << bars[0].brand << endl;
	cout << "Weight: " << bars[0].weight << endl;
	cout << "Calories: " << bars[0].calories << endl;

	cout << "Bar 2: " << endl;
	cout << "Brand: " << bars[1].brand << endl;
	cout << "Weight: " << bars[1].weight << endl;
	cout << "Calories: " << bars[1].calories << endl;

	cout << "Bar 3: " << endl;
	cout << "Brand: " << bars[2].brand << endl;
	cout << "Weight: " << bars[2].weight << endl;
	cout << "Calories: " << bars[2].calories << endl;
	delete[] bars;
	return;
}