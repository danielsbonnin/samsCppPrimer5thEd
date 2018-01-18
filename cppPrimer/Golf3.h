#pragma once
class Golf3
{
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	Golf3(const char * name = "unknown", int hc = 99);
	int setGolf();
	void setHandicap(int hc);
	void showGolf() const;
	~Golf3();
};

