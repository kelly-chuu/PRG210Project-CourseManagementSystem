#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Course.h"

class Department {
private:
    char name[100];
    Course* courses;
    int totalCourses;

public:
    Department();
    Department(const char* deptName);
    ~Department();
    Department(const Department& other);
    Department& operator=(const Department& other);
    void setTotalCourses(int num);
    const char* getName() const;
    void addCourse(const Course& course);
    void listCourses() const;
    int getTotalCourses() const;
    Course getCourse(int index);
};

#endif