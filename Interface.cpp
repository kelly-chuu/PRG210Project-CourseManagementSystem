#include <iostream>
using namespace std;
#include "Interface.h"

void Interface::displayMenu(string question){
    cout<< question; //don't know if necessary
}

string Interface::getValidation(int choices, string question){
    string input = "";
    while (true){
        displayMenu(question);
        cin >> input;
        if (stoi(input) <= choices && stoi(input) >= 0) {
            return input;
        }
        cout << "Invalid input!" <<endl;
    }
    
}