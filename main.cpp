#include "Department.h"
#include "Course.h"
#include "Cart.h"
#include "StudentInterface.h"
#include<iostream>
using namespace std;
Department* StoreDepartments = nullptr;
int TotalDepartments = 0;

int main(){
    TotalDepartments = 2;
    StoreDepartments = new Department[TotalDepartments];

    // Department 1: "Math"
    StoreDepartments[0] = Department("Math");
    StoreDepartments[0].addCourse(Course("22", "physics","M/W", 150.0));
    StoreDepartments[0].addCourse(Course("23", "math","M/W", 120.0));

    // Department 2: "CS"
    StoreDepartments[1] = Department("CS");
    StoreDepartments[1].addCourse(Course("34","Intro to Programming", "M/W", 200.0));
    StoreDepartments[1].addCourse(Course("34","Data Structures", "M/W", 220.0));

    // Launch student interface (if you have a class for it)
    StudentInterface s;

    // Clean up
    delete[] StoreDepartments;
    return 0;
}