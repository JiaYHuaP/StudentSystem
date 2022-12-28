#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include "include/Menu.h"
using namespace std;
#include "include/json/json.h"
int main() {
    string jsonFile = "D:\\Workspace\\Cpp\\StudentSystem\\data\\data.json";
    Menu menu;
    menu.loadFromJson(jsonFile);
    menu.loginMenu();
    return 0;
}
