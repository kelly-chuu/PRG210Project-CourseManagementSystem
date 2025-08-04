#include "Course.h"
#include "Interface.h"
#include "StudentInterface.h"
#include <iostream>
using namespace std;

StudentInterface::StudentInterface(){
    menus[0] = "***Student Interface***\nOptions\n" //Main student menu
        "Show Cart [1]\nBrowse Departments [2]\nExit [3]\n"
        "Enter your choice [1,2,3]";
        
    menus[1] = "***Cart Menu***\nOptions\n" //Show cart menu
        "List Courses [1]\nCheckout [2]\nReturn to Main Menu [3]\n"
        "Enter your choice [1,2,3]\n"; 
    menus[2] = "***Browse Department Menu\n" //Browse Department menu
        "List Courses of a Department [1]\n"
        "Go Back to Main Menu [2] \n"
        "Enter your choice [1,2]\n"; 
    menus[3] = "Enter department number [0 to go back]\n"; //Choose department #
    menus[4] = "Add to Cart a Course [1]\n" //Add to cart?
        "Go Back to Browse Department Menu\n"
        "Enter your choice [1,2]\n";
    menus[5] = "Enter course number to buy [0 to go back]\n"; //Buy course?
}