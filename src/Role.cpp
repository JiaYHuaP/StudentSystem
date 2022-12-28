#include "../include/Role.h"


Role::Role(const string &name, const string &sex, const string &account, const string &password, int role) : name(name),
                                                                                                             sex(sex),
                                                                                                             account(account),
                                                                                                             password(
                                                                                                                     password),
                                                                                                             role(role) {}

Role::Role(const string &name, const string &sex) : name(name), sex(sex) {}

Role::Role() {}

Role::Role(const string &account, const string &password, int role) : account(account), password(password),
                                                                      role(role) {}

const string &Role::getName() const {
    return name;
}

void Role::setName(const string &name) {
    Role::name = name;
}

const string &Role::getSex() const {
    return sex;
}

void Role::setSex(const string &sex) {
    Role::sex = sex;
}

const string &Role::getAccount() const {
    return account;
}

void Role::setAccount(const string &account) {
    Role::account = account;
}

const string &Role::getPassword() const {
    return password;
}

void Role::setPassword(const string &password) {
    Role::password = password;
}

int Role::getRole() const {
    return role;
}

void Role::setRole(int role) {
    Role::role = role;
}
