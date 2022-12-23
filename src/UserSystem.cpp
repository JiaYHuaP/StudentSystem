//
// Created by 30369 on 2022/12/21.
//

#include "../include/UserSystem.h"

int UserSystem::loadFromJson(string path) {
    // load from json
    Json::Value jsonRoot;
    Json::Reader jsonReader;
    ifstream ifs;
    ifs.open(path);
    if (!jsonReader.parse(ifs, jsonRoot)) {
        return -1;
    }
    ifs.close();
    // save as roles
    for (auto item: jsonRoot) {
        for (auto user: item) {
            Role r(user["account"].asString(),
                   user["password"].asString(),
                   user["role"].asString());
            roles.push_back(r);
        }
    }
    for (auto r: roles) {
        cout << r.getAccount() + " " + r.getPassword() + " " + r.getRole() << endl;
    }
}

string UserSystem::Login(string account, string password) {
    for(auto r:roles){
        if(r.getAccount()==account && r.getPassword()==password){
            currentRole = r;
            return r.getRole();
        }
    }
    return "no";
}

const Role &UserSystem::getCurrentRole() const {
    return currentRole;
}

