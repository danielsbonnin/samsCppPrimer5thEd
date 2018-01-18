#pragma once
namespace SALES {
	class Sales1
	{
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales1();
		Sales1::Sales1(const double ar[], int n);
		~Sales1();
		// gathers sales for 4 quarters interactively, stores them
		// in the sales member of s and computes and stores the
		// average, maximum, and minumum values
		void setSales();
		// display all information
		void showSales() const;
		// assigns min, max, avg according to sales
		void setVars();
	};
}

