

#ifndef DEMO_MENU_H
#define DEMO_MENU_H


#include "DataSystem.h"
#include "UserSystem.h"


class Menu {
    DataSystem dataSystem;
    UserSystem userSystem;
public:
    int loadUserData(string path);
    void mainMenu();
    void loginMenu();
    void studentMainMenu();
    void managerMainMenu();
    void addStudentMenu();
    void changeStudentMenu();
    void deleteStudentMenu();
    void searchStudentMenu();
    void sortStudentMenu();
    void subjectMenu();
    static void drawDelimiter();
};


#endif //DEMO_MENU_H
