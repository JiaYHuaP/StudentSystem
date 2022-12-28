#ifndef DEMO_MENU_H
#define DEMO_MENU_H
#include "DataService.h"
#include "UserService.h"

class Menu {
    DataService dataService;
    UserService userService;
public:
    int loadFromJson(string path);
    void loginMenu();
    void studentMainMenu();
    void managerMainMenu();
    void addStudentMenu();
    void changeStudentMenu();
    void deleteStudentMenu();
    void searchStudentMenu();
    void sortStudentMenu();
    void subjectMenu();
    void chartMenu();
    static void drawDelimiter();
};

#endif //DEMO_MENU_H
