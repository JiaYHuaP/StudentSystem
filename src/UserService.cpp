#include "../include/UserService.h"
int UserService::loadFromJson(string path) {
    // load from json
    Json::Value jsonRoot;
    Json::Reader jsonReader;
    ifstream ifs;
    ifs.open(path);
    if (!jsonReader.parse(ifs, jsonRoot)) {
        return 0;
    }
    ifs.close();
    // save as roles
    for (auto item: jsonRoot) {
        for (auto user: item) {
            Role r(user["account"].asString(),
                   user["password"].asString(),
                   user["role"].asInt());
            roles.push_back(r);
        }
    }
    return 1;
}

int UserService::Login(string account, string password) {
    for(auto r:roles){
        if(r.getAccount()==account && r.getPassword()==password){
            currentRole = r;
            return r.getRole();
        }
    }
    return -1;
}

const Role &UserService::getCurrentRole() const {
    return currentRole;
}

