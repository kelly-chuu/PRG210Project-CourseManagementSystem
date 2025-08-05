#include "Department.h"
#include "Course.h"
#include "Cart.h"
#include "StudentInterface.h"
#include "Admin_Interface.h"
#include "Interface.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;
Department *StoreDepartments = nullptr;
int TotalDepartments = 0;
const char *csvFile = "/workspaces/PRG210Project-CourseManagementSystem/courses_extended.csv";
void loadDepartmentsFromCSV(const char* filename);
int main()
{
    // TotalDepartments = 2;
    // StoreDepartments = new Department[TotalDepartments];

    // // Department 1: "Math"
    // StoreDepartments[0] = Department("Math");
    // StoreDepartments[0].addCourse(Course("22", "physics", "M/W", 150.0));
    // StoreDepartments[0].addCourse(Course("23", "math", "M/W", 120.0));

    // // Department 2: "CS"
    // StoreDepartments[1] = Department("CS");
    // StoreDepartments[1].addCourse(Course("34", "Intro to Programming", "M/W", 200.0));
    // StoreDepartments[1].addCourse(Course("34", "Data Structures", "M/W", 220.0));

    loadDepartmentsFromCSV(csvFile);

    while (true)
    {
        cout << "MAIN MENU" << endl;
        cout << "Select Role:\n";
        cout << "1. Student\n";
        cout << "2. Admin\n";
        cout << "3. Exit\n";
        string input;
        while (true)
        {
            cout << "Enter your choice [1, 2, 3]: ";
            cin >> input;
            if (input == "1" || input == "2" || input == "3")
            {
                break;
            }
            else
            {
                cout << "Invalid output! <<endl";
            }
        }
        if (input == "3")
        {
            cout << "Exiting program.\n";
            break;
        }
        else if (input == "1")
        {
            Interface* user = new StudentInterface(); //polymorphism!
        }
        else if (input == "2")
        {
            Interface* user = new AdminInterface();
        }
    }
    // Clean up
    delete[] StoreDepartments;
    return 0;
}

void loadDepartmentsFromCSV(const char* filename) { //this doesn't work yet
    ifstream file(filename); //opens file for reading
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return; //doesn't continue
    }

    string line;
    getline(file, line);
    TotalDepartments = stoi(line); //first line is the #departments
    StoreDepartments = new Department[TotalDepartments];

    for (int i = 0; i < TotalDepartments; i++) {//iterate departments
        // Read department name and course count
        getline(file, line);
        stringstream ss(line); //split line into parts
        string deptName, courseCountStr;
        getline(ss, deptName, ','); //first line gives dept name and total courses
        getline(ss, courseCountStr);

        StoreDepartments[i] = Department(deptName.c_str()); //add department (convert to char*)
        int numCourses = stoi(courseCountStr);

        for (int j = 0; j < numCourses; j++) { //add courses to department
            //GET COURSE
            getline(file, line);
            stringstream cs(line); //ready for splitting
            string courseName, schedule, priceStr;
            getline(cs, courseName, ','); //get course name
            getline(cs, schedule, ','); //get schedule
            getline(cs, priceStr); //get price

            double price = stod(priceStr); //convert to double
            //convention for course number
            Course course((to_string(i)+"000"+to_string(j)).c_str(),courseName.c_str(), schedule.c_str(), price);
            StoreDepartments[i].addCourse(course);
        }
        //StoreDepartments[i].setTotalCourses(numCourses); //maybe don't need this
    }

    file.close(); //close the file
}