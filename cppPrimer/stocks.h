#pragma once
class Stock   // class declaration
{
private:
	char * company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const char * co, int n = 0, double pr = 0.0);
	Stock(const Stock &);
	~Stock();
	friend std::ostream & operator<<(std::ostream &, const Stock &);
	Stock & operator<<(const Stock &);
	Stock & operator=(const Stock &);
	const Stock & topval(const Stock & s) const;
	void acquire(const char * co, int n, double pr);
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	
	const char * getCompany() const;
	int getShares() const;
	double getShareVal() const;
	double getTotalVal() const;
};    // note semicolon at the end