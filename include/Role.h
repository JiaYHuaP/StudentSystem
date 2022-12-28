#pragma once
#include <string>
using namespace std;

class Role {
private:
    string name;
    string sex;
    string account;
    string password;
    int role;
public:
    Role(const string &name, const string &sex, const string &account, const string &password, int role);
    Role(const string &account, const string &password, int role);
    Role();

    Role(const string &name, const string &sex);

    const string &getName() const;

    void setName(const string &name);

    const string &getSex() const;

    void setSex(const string &sex);

    const string &getAccount() const;

    void setAccount(const string &account);

    const string &getPassword() const;

    void setPassword(const string &password);

    int getRole() const;

    void setRole(int role);
};