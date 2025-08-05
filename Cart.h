#pragma once
#include "Course.h"
#include<iostream>
using namespace std;
class Cart{
private:
    Course* selection;
    string schedule[100];
    int numberCourses;
    double totalCost;
    
public:
    Cart();
    void addToCart(const Course& c);
    ~Cart();
    double calcTotalCost();
    int calcNumberCourses();
    void display();
    void clear();
};