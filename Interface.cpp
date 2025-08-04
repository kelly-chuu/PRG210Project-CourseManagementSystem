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
        //do stoi(input) here and surround with try catch
        try{
            int inputInt = stoi(input);
            if (inputInt <= choices && inputInt >= 0) {
                return input;
            }
        }
        catch(const invalid_argument& e){
            cout << "Invalid input!" <<endl;
            continue;
        }
        
        cout << "Invalid input!" <<endl;
    }
    
}