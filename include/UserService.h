#include <vector>
#include "Role.h"
#include <fstream>
#include "./json/json.h"
#include <iostream>
#ifndef STUDENTSYSTEM_USERSYSTEM_H
#define STUDENTSYSTEM_USERSYSTEM_H
#endif //STUDENTSYSTEM_USERSYSTEM_H

class UserService{
    vector<Role> roles{};
    Role currentRole;
public:
    const Role &getCurrentRole() const;
    int loadFromJson(string);
    int Login(string account,string password);
};


