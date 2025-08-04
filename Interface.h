#include <iostream>
using namespace std;
class Interface{
protected:
    virtual void displayMenu(string question);
    virtual string getValidation(int choices, string question);
};

/*prints the start menu ? (or in main)
has question and valid-answer data
has functions for displaying questions
has function for repeating question until valid input
returns
Flow:
Display question
loop --> read input
validate
if invalid restart
if valid, break and move to next 'menu'
*/