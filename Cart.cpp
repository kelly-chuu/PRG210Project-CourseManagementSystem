#include <iostream>
#include "Cart.h"

Cart::Cart(){
    selection = new Course[100];
    numberCourses = 0;
    totalCost = 0.0;
}

int Cart::calcNumberCourses(){
    return numberCourses; //do i need this?
}

void Cart::addToCart(const Course& c) { //do i need the const here
    selection[numberCourses] = c; //why error
    numberCourses++;
    totalCost = calcTotalCost();
}
double Cart::calcTotalCost(){//check this pls
    double total = 0.0;
    for (int i = 0; i< numberCourses; i++){
        total+=selection[i].getPrice();
    }
    total *= 1.13;
    return total;
}
Cart::Cart(){
    delete[] selection;
}