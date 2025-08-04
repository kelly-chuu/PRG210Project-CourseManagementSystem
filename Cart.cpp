#include <iostream>
#include "Cart.h"

Cart::Cart(){
    selection = new Course[100];
    numberCourses = 0;
    totalCost = 0.0;
}

int calcNumberCourses(){
    //return numberCourses; //what
}

void addToCart(const Course c) { //do i need the const here
    (this + numberCourses) = c;
    numberCourses++;
    totalCost = calcTotalCost();
}
double calcTotalCost(){
    
}