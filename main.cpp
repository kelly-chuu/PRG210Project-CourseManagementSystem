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

int main()
{
    TotalDepartments = 2;
    StoreDepartments = new Department[TotalDepartments];

    // Department 1: "Math"
    StoreDepartments[0] = Department("Math");
    StoreDepartments[0].addCourse(Course("22", "physics", "M/W", 150.0));
    StoreDepartments[0].addCourse(Course("23", "math", "M/W", 120.0));

    // Department 2: "CS"
    StoreDepartments[1] = Department("CS");
    StoreDepartments[1].addCourse(Course("34", "Intro to Programming", "M/W", 200.0));
    StoreDepartments[1].addCourse(Course("34", "Data Structures", "M/W", 220.0));

    // Launch student interface
    // StudentInterface s;
    // AdminInterface a;

    while (true)
    {
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
                cout << "You chose option " << input << endl;
                if (input == "3")
                {
                    cout << "Exiting program.\n";
                    break;
                }
                else if (input == "1")
                {
                    Interface user = StudentInterface();
                }
                else if (input == "2")
                {
                    Interface user = AdminInterface();
                }
            }
            else
            {
                cout << "Invalid output! <<endl";
            }
        }
    }
    // Clean up
    delete[] StoreDepartments;
    return 0;
}

// void loadDepartmentsFromCSV(const char* filename) { //this doesn't work yet
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cout << "Failed to open file: " << filename << std::endl;
//         return;
//     }

//     std::string line;
//     getline(file, line);
//     TotalDepartments = std::stoi(line);
//     StoreDepartments = new Department[TotalDepartments];

//     for (int i = 0; i < TotalDepartments; i++) {
//         // Read department name and course count
//         getline(file, line);
//         std::stringstream ss(line);
//         std::string deptName, courseCountStr;
//         getline(ss, deptName, ',');
//         getline(ss, courseCountStr);

//         Department& dept = StoreDepartments[i];
//         dept.setName(deptName.c_str());
//         int numCourses = std::stoi(courseCountStr);
//         dept.setTotalCourses(numCourses);

//         for (int j = 0; j < numCourses; j++) {
//             getline(file, line);
//             std::stringstream cs(line);
//             std::string courseName, schedule, priceStr;

//             getline(cs, courseName, ',');
//             getline(cs, schedule, ',');
//             getline(cs, priceStr);

//             double price = std::stod(priceStr);
//             Course course(courseName.c_str(), schedule.c_str(), price);
//             dept.addCourse(course); // Add this method to dynamically append courses
//         }
//     }

//     file.close();
// }