//
// Created by 30369 on 2022/12/1.
//

#include <utility>
#include "../include/Student.h"

const string &Student::getMajor() const {
    return major;
}

void Student::setMajor(const string &major) {
    Student::major = major;
}

double Student::getMath() const {
    return math;
}

void Student::setMath(double math) {
    Student::math = math;
}

double Student::getComputer() const {
    return computer;
}

void Student::setComputer(double computer) {
    Student::computer = computer;
}

double Student::getEnglish() const {
    return english;
}

void Student::setEnglish(double english) {
    Student::english = english;
}




double Student::getSum() const {
    return getMath() + getEnglish() + getComputer();
}

Student::Student(const string &account, const string &password, const string &role, const string &major, double math,
                 double computer, double english) : Role(account, password, role), major(major), math(math),
                                                    computer(computer), english(english) {}

Student::Student(const string &account, const string &password, const string &role) : Role(account, password, role) {}

Student::Student() {}


