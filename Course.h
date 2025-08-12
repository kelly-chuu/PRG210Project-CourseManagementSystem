#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <cstring>

class Course {
private:
    char courseNumber[20];
    char* name;//dynamiclally allocating memory for the course name
    char schedule[4];
    double price;

public:
    Course();
    Course(const char* number, const char* name, const char* sched, double price);
    Course(const Course& other); //this allows you to make a new course as a copy of another course
    Course& operator=(const Course& other);// in here we add a copy constructor because it allows to assign one course to another
    ~Course();//clears memory allocated for name

    const char* getName() const;
    const char* getNumber() const;
    const char* getSchedule() const;
    double getPrice() const;//returns info

    void display() const;
};

#endif