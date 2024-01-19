// header file for Seller class
// header file for Powerseller class
#ifndef SELLER_H
#define SELLER_H

#include "Person.h"

class Seller : public Person
{
public:
    // Constructors
    Seller();
    Seller(const Seller& source);
    Seller(string str);

    // "get" Methods for average star rating and total sold
    double getAverageRating();
    int getTotalSold();

    // "set" Methods for average star rating and total sold
    void setAverageRating(const double& ar);
    void setTotalSold(const int& ts);

    // overloaded stream input and output operators for getting and setting
    // Person information easily.
    friend istream& operator>>(istream& is, Seller& rhs);
    friend ostream& operator<<(ostream& os, const Seller& rhs);

    // Read in file from int main() and print seller information
    void print() const;
    void read(istream& is);

protected:
    double averageRating;
    int totalSold;
};
#endif