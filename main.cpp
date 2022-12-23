#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include "include/Menu.h"


using namespace std;
#include "include/json/json.h"
int main() {
    string jsonFile = "D:\\Workspace\\Cpp\\StudentSystem\\data\\user.json";
    Menu menu;
    menu.loadUserData(jsonFile);
    menu.loginMenu();
//    menu.mainMenu();
    return 0;
}
