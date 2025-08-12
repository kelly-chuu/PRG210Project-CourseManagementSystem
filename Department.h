#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Course.h"

class Department {
private:
    char name[100];
    Course* courses;//adding this pointer to an array of course objects to show the cousres offered by this depatrtment
    int totalCourses;

public:
    Department();
    Department(const char* deptName);//this way the constructor sets the dept.name right away
    ~Department();
    Department(const Department& other);
    Department& operator=(const Department& other);//using a copy construc. to copy one dept to another 
    void setTotalCourses(int num);
    const char* getName() const;
    void addCourse(const Course& course);
    void listCourses() const;
    int getTotalCourses() const;
    Course getCourse(int index);//adding the index so that it returns a specific course at a given index in the list
};

#endif