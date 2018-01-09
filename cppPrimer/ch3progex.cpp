#include "stdafx.h"
#include "ch3progex.h"
#include <iostream>
#include <climits>
using namespace std;

void ex3_1(void)
{
	// Programming exercises ch3 Dealing with Data
	//ex. 1

	int height = 0;
	cout << "Please enter your height in inches: __\b\b";
	cin >> height;
	int feet = height / INCHES_TO_FEET;
	int inches = height % INCHES_TO_FEET;
	cout << "Your height is: " << feet << '\'' << inches << '\"' << endl;
	return;
}
void ex3_2(void)
{
	// ex. 2
	int feet = 0;
	int inches = 0;
	int weight = 0;
	float kgs = 0.0F;
	float meters = 0.0F;
	double heightSquared = 0.0;
	double bmi = 0.0;

	cout << "Please enter your height:\n";
	cout << "Feet: _\b";
	cin >> feet;
	cout << "Inches: __\b\b";
	cin >> inches;
	cout << "Please enter your weight in whole pounds: ___\b\b\b";
	cin >> weight;
	inches = inches + feet * INCHES_TO_FEET;
	meters = inches * METERS_PER_INCH;
	heightSquared = meters * meters;
	kgs = weight / LBS_PER_KG;
	bmi = kgs / heightSquared;
	cout << "Your BMI is: " << bmi << endl;
	return;
}
void ex3_3(void)
{
	float degrees, minutes, seconds;
	degrees = minutes = seconds = 0.0F;
	const int ARC_SECONDS_PER_MINUTE = 60;
	const int ARC_MINUTES_PER_DEGREE = 60;

	cout << "Enter a latitude in degrees, minutes, and seconds:\n";
	cout << "First, enter the degrees: ";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: ";
	cin >> minutes;
	cout << "Finally, enter the seconds of arc: ";
	cin >> seconds;
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = ";
	cout << degrees + (minutes + seconds / ARC_SECONDS_PER_MINUTE) / ARC_MINUTES_PER_DEGREE << " degrees" << endl;
	return;
}
void ex3_4(void)
{
	const int HOURS_PER_DAY = 24;
	const int MINUTES_PER_HOUR = 60;
	const int SECONDS_PER_MINUTE = 60;
	long days, hours, minutes, seconds;
	days, hours = minutes = seconds = 0;
	cout << "Enter the number of seconds: ______\b\b\b\b\b\b";
	cin >> seconds;
	minutes = seconds / SECONDS_PER_MINUTE;
	hours = minutes / MINUTES_PER_HOUR;
	days = hours / HOURS_PER_DAY;
	hours = hours % HOURS_PER_DAY;
	minutes = minutes % MINUTES_PER_HOUR;
	cout << seconds << " seconds = ";
	seconds = seconds % SECONDS_PER_MINUTE;
	cout << days << " days, " << hours << " hours, ";
	cout << minutes << " minutes, " << seconds << " seconds" << endl;
	return;
}
void ex3_5(void)
{
	int miles, gals;
	miles = gals = 0;
	cout << "Enter how many miles you have driven: ___\b\b\b";
	cin >> miles;
	cout << "Enter how many gallons of gas you have used: ___\b\b\b";
	cin >> gals;
	cout << "Your car gets " << double(miles) / double(gals) << " per gallon\n";
	return;
}
void ex3_6(void)
{
	const float MILES_PER_KM = 0.6214;
	const float GALS_PER_L = 0.258065;
	const float MPG_TO_KPL = 2.4079205;
	const float MPG_TO_LPK = 0.4152961;  // inv of MPG_TO_KPL

	return;
}