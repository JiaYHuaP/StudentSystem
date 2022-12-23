//
// Created by 30369 on 2022/12/21.
//

#include <vector>
#include "Role.h"
#include <fstream>
#include "./json/json.h"
#include <iostream>
#ifndef STUDENTSYSTEM_USERSYSTEM_H
#define STUDENTSYSTEM_USERSYSTEM_H

#endif //STUDENTSYSTEM_USERSYSTEM_H

class UserSystem{
    vector<Role> roles{};
    Role currentRole;
public:
    const Role &getCurrentRole() const;


    int loadFromJson(string);
    string Login(string account,string password);
};


