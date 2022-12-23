#pragma once

#include <string>
using namespace std;

class Role {
private:
    string name;
    string sex;
    string account;
    string password;
    string role;
public:
    Role();

public:
    Role(const string &account, const string &password, const string &role);

    const string &getRole() const;

    void setRole(const string &role);

public:
    void setAccount(const string &account);

    void setPassword(const string &password);

public:
    const string &getName() const;

    void setName(const string &name);

    const string &getSex() const;

    void setSex(const string &sex);

    const string &getAccount() const;

    const string &getPassword() const;



};