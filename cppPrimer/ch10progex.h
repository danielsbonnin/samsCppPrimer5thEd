#pragma once
#include <string>
void ex10_1();
void ex10_2();
void ex10_3();
void ex10_4();
void ex10_5();
void ex10_6();
void ex10_7();
void ex10_8();
class Person {
private:
	static const int LIMIT = 25;
	std::string lname;        // Person's last name
	char fname[LIMIT];         // Person's first name
public:
	Person() { lname = ""; fname[0] = '\0'; } // #1
	Person(const std::string & ln, const char * fn = "Heyyou");  // #2
// the following methods display lname and fname
	void Show() const;        // firstname lastname format
	void FormalShow() const;  // lastname, firstname format
};