#include "Department.h"
#include "Course.h"
#include "Cart.h"
#include<iostream>
using namespace std;

int main(){
    char a[] = "Physics";
    Course c(a, a, "M/T", 20.00);
    c.display();
    Course b;
    //b.display();
    //b=c;
    //something is happening here, b isn't displaying at all
    //b.display();
    Department d("Mathematics");
    d.addCourse(c);
    d.addCourse(c);
    d.listCourses();
    return 0;
}