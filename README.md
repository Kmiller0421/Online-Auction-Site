# Online-Auction-Site
Designs an online auction site that keeps track of all sellers in the system. Uses derived classes for Seller and PowerSeller. Inputs the sellers.dat file and outputs the sellers listed in the menu options.

# Purpose
I first built a simple version of this project but wanted to practice by adding classes and overloading operators. So, I created multiple classes, overloading operators, 
and figured out how to get each class file to grab information from each other and perform its task.

# How it works
- User types in user login
  - User successfully logs in
    - Introduced with a menu with five choices
      - Print all seller information (Display all seller information on screen)
      - Check information of one seller (Check existing seller information and display on screen)
      - Add a new seller (Add a new seller onto a sellers.txt file and display the message of the new seller added)
      - Remove an existing seller (Remove a seller off sellers.txt file and display the message of the seller being removed)
      - Quit
  - User unsuccessfully logs in
    - Exit the whole program

# Challenges
Challenges I faced when doing this project were working with multiple class files and getting down the logic. I had to break down 
the task to understand how to grab information from Person.h and forward it to Seller.cpp . For logic, I went to my whiteboard and created 
a flowchart to help me organize my thoughts, allowing me to figure out problems more effectively than inside my head.
