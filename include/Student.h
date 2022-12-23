

#ifndef DEMO_STUDENT_H
#define DEMO_STUDENT_H
// 类的属性一般是私有的，不能外部直接访问。
#include <string>
#include "Role.h"
using namespace std;

class Student :public Role{
private:
public:
    Student();

private:
    string major;
    double math{};
    double computer{};
    double english{};
public:
    // 构造函数
    Student(const string &account, const string &password, const string &role);
    Student(const string &account, const string &password, const string &role, const string &major, double math,
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
