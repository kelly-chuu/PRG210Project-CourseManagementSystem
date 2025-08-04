#include "Department.h"
#include <cstring>
using namespace std;

Department::Department(){
    strncpy(name, "N/A", 4);
    name[4] = '\0';
    courses = new Course[100];
    totalCourses = 0;
}
Department::Department(const char* deptName){
    strncpy(name, deptName, strlen(deptName)+1);
    name[strlen(deptName)+1] = '\0';
    courses = new Course[100];
    totalCourses = 0;
}
Department::~Department(){

}
const char* Department::getName() const {
    return name;
}

void Department::addCourse(const Course& course){
    
}