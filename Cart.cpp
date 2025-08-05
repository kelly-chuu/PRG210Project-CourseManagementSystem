#include <iostream>
#include "Cart.h"
using namespace std;
#include "Course.h"

Cart::Cart(){
    selection = new Course[100];
    //schedule remains empty
    numberCourses = 0;
    totalCost = 0.0;
}

int Cart::calcNumberCourses(){
    return numberCourses; 
}

void Cart::addToCart(const Course& c) { 
    selection[numberCourses] = c; 
    schedule[numberCourses] = c.getSchedule();
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
Cart::~Cart(){
    delete[] selection;
}
void Cart::display(){
    if(numberCourses ==0){
        cout << "Cart is empty!" <<endl;
    }
    else{
        for (int i= 0; i<numberCourses;i++){
            selection[i].display();
        }
    }
}

void Cart::clear(){
    delete[] selection;
    selection = new Course[100];
    for (int i = 0; i<numberCourses;i++){
        schedule[i] = "";
    }
    numberCourses = 0;
    totalCost = 0.0;
}