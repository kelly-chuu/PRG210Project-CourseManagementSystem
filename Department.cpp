#include "Department.h"
#include <cstring>
#include <iostream>
using namespace std;

Department::Department() : courses(nullptr), totalCourses(0) {
    strcpy(name, "");
}

Department::Department(const char* deptName) : courses(nullptr), totalCourses(0) {
    strcpy(name, deptName);
}
Department::~Department(){
    delete[] courses;
}
Department::Department(const Department& other) {
    strcpy(name, other.name);
    totalCourses = other.totalCourses;

    if (totalCourses > 0) {
        courses = new Course[totalCourses];
        for (int i = 0; i < totalCourses; ++i) {
            courses[i] = other.courses[i]; // relies on Course copy constructor
        }
    } else {
        courses = nullptr;
    }
}

Department& Department::operator=(const Department& other) {
    if (this != &other) {
        delete[] courses;

        strcpy(name, other.name);
        totalCourses = other.totalCourses;

        if (totalCourses > 0) {
            courses = new Course[totalCourses];
            for (int i = 0; i < totalCourses; ++i) {
                courses[i] = other.courses[i]; // relies on Course operator=
            }
        } else {
            courses = nullptr;
        }
    }
    return *this;
}
const char* Department::getName() const {
    return name;
}
void Department::setTotalCourses(int num){
    totalCourses = num;
}

void Department::addCourse(const Course& course) {
    Course* temp = new Course[totalCourses + 1];
    for (int i = 0; i < totalCourses; ++i) temp[i] = courses[i];
    temp[totalCourses] = course;
    delete[] courses;
    courses = temp;
    totalCourses++;
}

void Department::listCourses() const{
    for (int i = 0; i<totalCourses;i++){
        cout << i + 1 <<". ";
        courses[i].display();
    }
}

int Department::getTotalCourses() const{
    return totalCourses;
}

Course Department::getCourse(int index){
    return courses[index];
}