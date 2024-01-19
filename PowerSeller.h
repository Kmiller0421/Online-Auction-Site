#ifndef POWERSELLER_H
#define POWERSELLER_H

#include "Seller.h"

#include <string>

class PowerSeller : public Seller {
public:
	// Constructors
	PowerSeller();
	PowerSeller(const PowerSeller& source);
	PowerSeller(string str);

	// "get" Methods for website and current sold
	string getWebsite();
	int getCurrentYear();

	// "set" Methods for website and currenty sold
	void setwebsite(const string& web);
	void setCurrentYear(const int& cy);

	// overloaded stream input and output operators for getting and setting
	// Person information easily.
	friend istream& operator>>(istream& is, PowerSeller& rhs);
	friend ostream& operator<<(ostream& os, const PowerSeller& rhs);

	// Read in file from int main() and print out Power seller information
	void print() const;
	void read(istream& is);

protected:
	string website;
	int currentSold;
};
#endif