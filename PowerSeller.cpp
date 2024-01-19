// implementation file for Powerseller class

#include "Powerseller.h"
#include <sstream>

// Default Constructor
PowerSeller::PowerSeller()
{
    website = "https://www.example.com";
    currentSold = 0;
}

// Copy Constructor
PowerSeller::PowerSeller(const PowerSeller& source)
{
    Seller::setFirstName(source.getFirstName());
    Seller::setLastName(source.getLastName());
    Seller::setUserID(source.getUserID());
    Seller::setEmailAddress(source.getEmailAddress());
    website = source.website;
    currentSold = source.currentSold;
}

PowerSeller::PowerSeller(string str)
{
    istringstream iss{ str };
    iss >> firstName >> lastName >> userID >> emailAddress >> averageRating >> totalSold >> website
        >> currentSold;
}

// "get" Methods for website and current year sold
string PowerSeller::getWebsite() { return this->website; }
int PowerSeller::getCurrentYear() { return this->currentSold; }

// "set" Methods for website and current year sold
void PowerSeller::setwebsite(const string& web) { website = web; }
void PowerSeller::setCurrentYear(const int& cy) { currentSold = cy; }

void PowerSeller::read(istream& is)
{
    Seller::read(is);
    is >> website >> currentSold;
}

// PowerSeller overloaded >> operator
istream& operator>>(istream& is, PowerSeller& rhs)
{
    rhs.read(is);
    return is;
}

// PowerSeller overloaded << operator
ostream& operator<<(ostream& os, const PowerSeller& rhs)
{
    // Print base class information

    // rhs.print();

    // Print PowerSeller information
    os << "Website Address: " << rhs.website << endl;
    os << "Current Year Products Sold: " << rhs.currentSold << endl;

    // print the seller's information and return the output stream
    return os;
}

// Print out Power seller information
void PowerSeller::print() const {
    Seller::print();
    cout << "Website Address: " << this->website << endl;
    cout << "Current Year Products Sold: " << this->currentSold << endl;
}