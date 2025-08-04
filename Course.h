#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <cstring>

class Course {
private:
    char courseNumber[20];
    char* name;
    char schedule[4];
    double price;

public:
    Course();
    Course(const char* number, const char* name, const char* sched, double price);
    Course(const Course& other);
    Course& operator=(const Course& other);
    ~Course();

    const char* getName() const;
    const char* getNumber() const;
    const char* getSchedule() const;
    double getPrice() const;

    void display() const;
};

#endif