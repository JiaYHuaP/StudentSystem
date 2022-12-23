#include "../include/Role.h"

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

const string &Role::getPassword() const {
    return password;
}

void Role::setAccount(const string &account) {
    Role::account = account;
}

void Role::setPassword(const string &password) {
    Role::password = password;
}

const string &Role::getRole() const {
    return role;
}

void Role::setRole(const string &role) {
    Role::role = role;
}

Role::Role(const string &account, const string &password, const string &role) : account(account), password(password),
                                                                                role(role) {}

Role::Role() {}


