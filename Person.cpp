// implementation file for Person class
#include "Person.h"
#include <sstream>

// Default Constructor
Person::Person()
{
    firstName = "first name";
    lastName = "last name";
    userID = "user id";
    emailAddress = "example@gmail.com";
}

// Copy constructor
Person::Person(const Person& source)
{
    firstName = source.firstName;
    lastName = source.lastName;
    userID = source.userID;
    emailAddress = source.emailAddress;
}

// Value constructor
Person::Person(string newFirstName, string newLastName, string newUserID, string newEmailAddress)
{
    firstName = newFirstName;
    lastName = newLastName;
    userID = newUserID;
    emailAddress = newEmailAddress;
}

// Overloaded operator ==
bool Person::operator==(const Person& rhs) const
{
    bool fn = (this->getFirstName() == rhs.getFirstName());
    bool ln = (this->getLastName() == rhs.getLastName());
    bool ea = (this->getEmailAddress() == rhs.getEmailAddress());
    if (fn && ln && ea)
    {
        return true;
    }
    return false;
}

// Overloaded operator !=
bool Person::operator!=(const Person& rhs) const
{
    return this->lastName != rhs.lastName;
}

// Overloaded operator <
bool Person::operator<(const Person& rhs) const
{
    return this->lastName < rhs.lastName;
}

// Overloaded operator >
bool Person::operator>(const Person& rhs) const
{
    return this->lastName > rhs.lastName;
}

// Overloaded assignment = 
Person& Person::operator=(const Person& rhs)
{
    firstName = rhs.firstName;
    lastName = rhs.lastName;
    userID = rhs.userID;
    emailAddress = rhs.emailAddress;
    return *this;
}

// Person overloaded >> operator
istream& operator>>(istream& is, Person& rhs)
{
    // istringstream iss{line};
    string newFirstName, newLastName, newUserID, newEmailAddress;
    is >> newFirstName >> newLastName >> newUserID >> newEmailAddress;

    rhs.setFirstName(newFirstName);
    rhs.setLastName(newLastName);
    rhs.setUserID(newUserID);
    rhs.setEmailAddress(newEmailAddress);

    return is;
}

// Person overloaded << operator
ostream& operator<<(ostream& os, Person& rhs)
{
    // allow the incoming argument to have a valid this pointer
    // (so we can actually call functions from it)
    Person * person = (Person *)&rhs;

    // print person information and return the output stream
    os << " Name: " << rhs.getFirstName() << " " << rhs.getLastName() << endl;
    os << " User ID: " << rhs.userID << endl;
    os << " Email: " << rhs.emailAddress << endl;

    return os;
}

// "get" methods for first name, last name, email address, and user id
string Person::getFirstName() const { return this-> firstName; }
string Person::getLastName() const { return this->lastName; }
string Person::getUserID() const { return this->userID; }
string Person::getEmailAddress() const { return this->emailAddress; }

// "set" methods for first name, last name, email address, and user id
void Person::setFirstName(const string& newFirstName) { firstName = newFirstName; }
void Person::setLastName(const string& newLastName) { lastName = newLastName; }
void Person::setEmailAddress(const string& newEmailAddress) { emailAddress = newEmailAddress; }
void Person::setUserID(const string& newUserID) { userID = newUserID; }

// Print out information
void Person::print() const
{
    cout << "First Name: " << this->firstName << endl;
    cout << "Last Name: " << this->lastName << endl;
    cout << "User ID: " << this->userID << endl;
    cout << "Email: " << this->emailAddress << endl;
}

// Read in users.dat file from int main()
void Person::read(istream& is)
{
    is >> this->firstName >> this->lastName >> this->userID >> this->emailAddress;
}