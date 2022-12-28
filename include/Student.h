#ifndef DEMO_STUDENT_H
#define DEMO_STUDENT_H
#include <string>
#include "Role.h"
#include "value.h"

using namespace std;
class Student :public Role{
private:
    string major;
    double math{};
    double computer{};
    double english{};
public:
    // 构造函数
    Student();
    Student(const string &account, const string &password, const int &role);
    Student(const string &account, const string &password, const int &role, const string &major, double math,
            double computer, double english);
    Student(Json::Value);
    Student(const string &name,const string &sex,const string &major,double math,
            double computer, double english);
    const string &getMajor() const;
    void setMajor(const string &major);
    double getMath() const;
    void setMath(double math);
    double getComputer() const;
    void setComputer(double computer);
    double getEnglish() const;
    void setEnglish(double english);
    double getSum() const;
};

#endif //DEMO_STUDENT_H
