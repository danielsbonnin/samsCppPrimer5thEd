#pragma once
class Plorg
{
	char name[20];
	int ci;
public:
	Plorg(const char * thename = "Plorga");
	void setCI(int n) { ci = n > 0 ? n : 0; }
	void print() const;
	~Plorg();
};

