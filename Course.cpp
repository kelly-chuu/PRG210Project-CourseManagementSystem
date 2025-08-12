#include "Course.h"
#include <iomanip>
Course::Course() : price(0.0) {//price is set when the obj.is created
    name = new char[1];
    name[0] = '\0'; 
    strcpy(courseNumber, "");
    strcpy(schedule, "");
}

Course::Course(const char* number, const char* n, const char* sched, double p) : price(p) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    strcpy(courseNumber, number);
    strcpy(schedule, sched);
}

Course::Course(const Course& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    strcpy(courseNumber, other.courseNumber);
    strcpy(schedule, other.schedule);
    price = other.price;  // creating a new course as a copy of another
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {// points to the current obj
        delete[] name;//delete old name memory and create a new one
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        strcpy(courseNumber, other.courseNumber);
        strcpy(schedule, other.schedule);
        price = other.price;
    }
    return *this;//the actual obj.
}

Course::~Course() {
    delete[] name;
}

const char* Course::getName() const { return name; }
const char* Course::getNumber() const { return courseNumber; }
const char* Course::getSchedule() const { return schedule; }
double Course::getPrice() const { return price; }// stopped from making modifications 

void Course::display() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::string(courseNumber) << " - " << name << " (" << schedule << ") - $" << price << std::endl;
}
