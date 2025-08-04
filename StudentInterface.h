#include "Course.h"
#include "Interface.h"
#include <iostream>
using namespace std;
class StudentInterface : public Interface{
private:
    string menus[6];
    
public:
    StudentInterface();
};

/*have a function just for displaying the menu.
takes the question and options int as parameters
Actually no these already exist in the parent class
*/