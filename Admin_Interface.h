#ifndef ADMIN_INTERFACE_H
#define ADMIN_INTERFACE_H

#include "Interface.h"
#include "Department.h"

extern Department* SchoolDepartments;
extern int TotalDepartments;
extern const char* csvFile;

class AdminInterface : public Interface {
public:
    void showMainMenu() override;// allows user to loop through options 1-5

private:
    void listDepartments();//current department names
    void addDepartment();
    void addCourseToDepartment();//in here we validate course numbers, schedules and prices
    void saveChangesToCSV();
};

#endif

