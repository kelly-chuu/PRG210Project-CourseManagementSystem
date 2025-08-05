#include "Admin_Interface.h"
#include "Interface.h"
#include <fstream>
#include <cstring>
extern Department* StoreDepartments;
extern int TotalDepartments;
extern const char* csvFile;

AdminInterface::AdminInterface(){
    showMainMenu();
}

void AdminInterface::showMainMenu() {
    int choice;//will display admin menu selections 
    do {
        std::cout << "\n Admin Menu\n";
        std::cout << "1. List Departments\n";
        std::cout << "2. Add Department\n";
        std::cout << "3. Add Course to Department\n";
        std::cout << "4. Save Changes to CSV\n";
        std::cout << "5. Exit\n";
        choice = stoi(getValidation(5, 1, "Enter your choice (1-5): \n"));

        if (choice == 1) listDepartments();
        else if (choice == 2) addDepartment();
        else if (choice == 3) addCourseToDepartment();
        else if (choice == 4) saveChangesToCSV();

    } while (choice != 5);
}
// i'm printing all the departments for the safe side
void AdminInterface::listDepartments() {
    for (int i = 0; i < TotalDepartments; ++i) {
        std::cout << i + 1 << ". " << StoreDepartments[i].getName() <<endl;
    }
}

void AdminInterface::addDepartment() {//adding a new department and using a pointer to change the department array size if needed? do i really
    std::cin.ignore();
    std::string name;
    std::cout << "Enter department name: ";
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cout << "invalid input!!!";
        return;
    }

    Department* temp = new Department[TotalDepartments + 1];
    for (int i = 0; i < TotalDepartments; ++i)
        temp[i] = StoreDepartments[i];

    temp[TotalDepartments] = Department(name.c_str());
    delete[] StoreDepartments;
    StoreDepartments = temp;
    TotalDepartments++;

    std::cout << "Department added.\n";
}
//ask user to add a course to a department with full input 
void AdminInterface::addCourseToDepartment() {
    listDepartments();
    int choice = stoi(getValidation(TotalDepartments, 0, "Enter department number (0 will take you back) "));
    if (choice == 0) return;

    Department& dept = StoreDepartments[choice - 1];
    std::cin.ignore();

    // after choosing the department the user can enter the info for new courses
    std::string crsnum, crsname, sched;
    double price;

    std::cout << "Enter course number: ";
    std::getline(std::cin, crsnum);
    while (crsnum.empty()) {
        std::cout << "Invalid!!Try again ";
        std::getline(std::cin, crsnum);
    }

    std::cout << "Enter course name: ";
    std::getline(std::cin, crsname);

    std::cout << "Enter schedule (M/W, T/R, W/F): ";
    std::getline(std::cin, sched);
    while (sched != "M/W" && sched != "T/R" && sched != "W/F") {
        std::cout << "Invalid!!Try again ";
        std::getline(std::cin, sched);
    }

    std::cout << "Enter course price: ";
    while (!(std::cin >> price) || price <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid!! Try again ";
    }

    dept.addCourse(Course(crsnum.c_str(), crsname.c_str(), sched.c_str(), price));
    std::cout <<  "The course has been added" <<endl;
}
//save data to csv file
void AdminInterface::saveChangesToCSV() {
    std::ofstream outFile(csvFile); //call the file for writing outFile
    if (!outFile) { //if path is wrong
        std::cerr << "Error: Unable to open CSV file for writing." << std::endl;
        return;
    }

    outFile << TotalDepartments << std::endl; //puts #departments at the top

    for (int i = 0; i < TotalDepartments; ++i) { //for each department
        Department& dept = StoreDepartments[i]; //for easier access
        outFile << dept.getName() << "," << dept.getTotalCourses() << std::endl;
        for (int j = 0; j < dept.getTotalCourses(); ++j) {//write each course
            Course course = dept.getCourse(j); //iterate through department
            outFile << course.getName() << "," 
                    << course.getSchedule() << "," 
                    << course.getPrice() << std::endl;
        }
    }
    outFile.close(); //close the file
    std::cout << "Changes saved to CSV successfully." << std::endl;
}