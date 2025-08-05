#include "Course.h"

Course::Course() : name(nullptr), price(0.0) {
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
    price = other.price;
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        strcpy(courseNumber, other.courseNumber);
        strcpy(schedule, other.schedule);
        price = other.price;
    }
    return *this;
}

Course::~Course() {
    delete[] name;
}

const char* Course::getName() const { return name; }
const char* Course::getNumber() const { return courseNumber; }
const char* Course::getSchedule() const { return schedule; }
double Course::getPrice() const { return price; }

void Course::display() const {
    std::cout << std::string(courseNumber) << " - " << name << " (" << schedule << ") - $" << price << std::endl;
}
