#include "Course.h"
#include<iostream>
using namespace std;
class Cart{
private:
    Course* selection;
    string schedule[100];
    int numberCourses;
    double totalCost;
    int calcNumberCourses();
    double calcTotalCost();
    ~Cart();
public:
    Cart();
    void addToCart(const Course& c);
};