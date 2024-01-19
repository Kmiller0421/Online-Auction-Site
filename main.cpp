// if late, give reason and pass # here
/*
 PROGRAMMER:       	Kaleb Miller
 Program Description:
 Designs an online auction site for "BidHere.com". Keeps track of all sellers in
 the system. Uses derived classes for Seller and PowerSeller. Inputs the
 sellers.dat file and outputs the sellers listed in the menu options.
*/

#include "Person.h"
#include "Powerseller.h"
#include "Seller.h"

#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

// Function Defintions
void printAllSellers(list<Person*> sellers);
void checkSellerRecord(list<Person*> sellers);

int main(){
    
    string password = "LETMEIN";
    string fn, ln, pw, sc;
    bool flag = true;
    bool foundUser = false;
    bool foundUser_1 = false;
    int choice = 0;

    // Read in users.txt and push information into list<Person>
    const string userFileName = "users.txt";
    ifstream userFile;
    userFile.open(userFileName);
    list<Person*> users;
    // Read in users.dat until end of file
    while (!userFile.eof()){
        Person* pc = new Person();
        pc->read(userFile);
        users.push_back(pc);
    }

    const string sellersFileName = "sellers.txt";
    list<Person*> sellers;
    ifstream sellersFile;
    sellersFile.open(sellersFileName);
    // Read in sellers.dat while sellers.dat is open
    if (sellersFile.is_open())
    {
        char c;
        while (sellersFile >> c)
        {
            // PowerSeller
            if (c == 'P')
            {
                PowerSeller* ps_ptr = new PowerSeller();
                ps_ptr->read(sellersFile);
                sellers.push_back(ps_ptr);
            }
            // Seller
            else if (c == 'S')
            {
                Seller* s_ptr = new Seller();
                s_ptr->read(sellersFile);
                sellers.push_back(s_ptr);
            }
            else
            {
                std::cout << "something went wrong";
            }
        }
    }
    

    cout << "User login:" << endl;
    cout << "\nFirst Name: ";
    cin >> fn;
    cout << "Last Name: ";
    cin >> ln;

    // Input validation to see if first name and last name are equal to users in .dat file
    for (Person *p : users) {
        if ((p->getFirstName() == fn) && (p->getLastName() == ln)) {
            foundUser = true;
            break;
        }
        else {
            foundUser = false;
        }
    }

    // If user was not found
    if (foundUser == false) {
        // error! exit
        std::cout << "Invalid user... exit." << endl;
        exit(1);
    }

    cout << "Password: ";
    cin >> pw;

    // Input validation to see if password is correct
    if (password == pw) {
        std::cout << "User authentication successful... Loading Main Menu" << endl;
        flag = true;
    }
    else {
        // Exit the whole program
        cout << "Invalid password... exit.";
        exit(1);
    }

    // Menu for Seller Mangaement
    while (flag != false) {
        cout << "\nPlease choose from the following menu: " << endl;
        cout << "------------------------------------" << endl;
        cout << "1 - Print all seller information." << endl;
        cout << "2 - Check information of one seller." << endl;
        cout << "3 - Add a new seller." << endl;
        cout << "4 - Remove an existing seller." << endl;
        cout << "5 - Quit." << endl;
        cout << "\nEnter your selection: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            // Call function
            printAllSellers(sellers);
            break;
        case 2:
            // Call function
            checkSellerRecord(sellers);
            break;
        case 3:
            // Wanted to print out in function but could not figure out how to update list
            // adding seller
            cout << "Please enter the following information (enter invalid type to quit):";
            cout << "\nIs the seller a (S)eller or (P)ower Seller? ";
            cin >> sc;
            cout << endl;

            if (sc == "S") {
                string line;
                cout << "Enter: [First Name] [Last Name] [User ID] [Email] [Avg. Rating] [Total Sold]" << endl;
                cin.ignore();
                getline(cin, line);
                Seller* seller = new Seller(line);
                sellers.push_back(seller);
                cout << "\nThe new Seller has been added.Returning to Seller Management...";
            }
            else if(sc == "P") {
                string line;
                cout << "Enter: [First Name] [Last Name] [User ID] [Email] [Avg. Rating] [Total Sold] [Website] [Yearly Total Sold]" << endl;
                cin.ignore();
                getline(cin, line);
                PowerSeller* ps = new PowerSeller(line);
                sellers.push_back(ps);
                cout << "\nThe new Power Seller has been added.  Returning to Seller Management..." << endl;
            }
            break;
        case 4:
            // Wanted to print out in function but could not figure out how to update list
            // adding seller
            cout << "Enter First Name: ";
            cin >> fn;
            cout << "Enter Last Name: ";
            cin >> ln;

            // Loop through to find seller and delete them off
            for (list<Person*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
                Person* p = *it;
                if ((p->getFirstName() == fn) && (p->getLastName() == ln)) {
                    list<Person*>::iterator p = sellers.erase(it);
                    foundUser_1 = true;
                    cout << "\nSuccessfully deleted seller... Returning to Seller Management..." << endl;
                    break;
                }
            }
            
            // If seller was not found
            if (foundUser_1 == false) {
                cout << "\nSorry, couldn't find seller." << endl;
            }
            break;
        case 5:
            cout << "Exiting program.\n";
            flag = false;
            break;
        }
    }
   
    return 0;
}

// Print out all sellers
void printAllSellers(list<Person*> sellers) {
    cout << "Printing all sellers information.\n";
    // Loop through sellers to find who is a seller or powerseller
    for (Person* p : sellers) {
        Seller* s = dynamic_cast<Seller*>(p);
        PowerSeller* ps = dynamic_cast<PowerSeller*>(p);
        if (s != nullptr && ps == nullptr) {
            // Print information of Seller
            s->print();
        }
        else if (ps != nullptr) {
            // Print information of PowerSeller
            ps->print();
        }
    }
}

// Checks and prints out the seller
void checkSellerRecord(list<Person*> sellers) {
    string fn, ln;
    bool foundUser = false;

    cout << "Enter first name: ";
    cin >> fn;
    cout << "Enter last name: ";
    cin >> ln;
    // Loop through sellers and check if seller exist
    for (Person* p : sellers) {
        // If seller exist print out information for that seller
        if ((p->getFirstName() == fn) && (p->getLastName() == ln)) {
            foundUser = true;
            p->print();
            break;
        }
    }
    
    // If seller was not found
    if (foundUser == false) {
        cout << "\nSorry, couldn't find seller." << endl;
    }
}