// implementation file for Seller class
#include "Seller.h"
#include "Person.h"
#include <sstream>

// Default Constructor
Seller::Seller()
{
    averageRating = 0.0;
    totalSold = 0;
}

// Copy Constructor
Seller::Seller(const Seller& source)
{
    Person::firstName = source.firstName;
    Person::lastName = source.lastName;
    Person::userID = source.userID;
    Person::emailAddress = source.emailAddress;
    averageRating = source.averageRating;
    totalSold = source.totalSold;
}

Seller::Seller(string str)
{
  istringstream iss{str};
   iss >> firstName >> lastName >> userID >> emailAddress >> averageRating >> totalSold;
}

// "get" Methods for average star rating and total sold
double Seller::getAverageRating() { return this->averageRating; }
int Seller::getTotalSold() { return this->totalSold; }

// "set" Methods for average star rating and total sold
void Seller::setAverageRating(const double& ar) { averageRating = ar; }
void Seller::setTotalSold(const int& ts) { totalSold = ts; }

// Print out seller information
void Seller::print() const
{
    Person::print();
    cout << "Average Star Rating:  " << this->averageRating << endl;
    cout << "Total Items sold:   " << this->totalSold << endl;
}

// Read in sellers.dat from int main();
void Seller::read(istream& is)
{
    Person::read(is);
    is >> this->averageRating >> this->totalSold;
}

// Seller overloaded >> operator
istream& operator>>(istream& is, Seller& rhs)
{
    rhs.read(is);
    return is;
}

// Seller overloaded << operator
 ostream & operator<<(ostream &os, const Seller &rhs)
 {
     Seller* sellers = (Seller*)&rhs;
     os << "Average Star Rating:  " << rhs.averageRating << endl;
     os << "Total Items sold:   " << rhs.totalSold << endl;
      // print the seller's information and return the output stream
      return os;
  }