
#include "../include/DataSystem.h"


int DataSystem::loadFromJson(string path) {
    // load from json
    Json::Value jsonRoot;
    Json::Reader jsonReader;
    ifstream ifs;
    ifs.open(path);
    if (!jsonReader.parse(ifs, jsonRoot)) {
        return -1;
    }
    ifs.close();
    // save as student

}

void DataSystem::addStudent(Student &student) {
    students.push_back(student);
}

void DataSystem::deleteStudentByIndex(int index) {
    students.erase(students.begin() + index);
}


unsigned long long DataSystem::getStudentSize() {
    return students.size();
}

bool DataSystem::ifExistByIndex(int index) {
    return index < students.size() && index >= 0;
}

void DataSystem::changeStudentByIndex(int index, Student &s) {
    students[index] = s;
}

Student DataSystem::getStudentByIndex(int index) {
    // 索引获取值要判空
    if (ifExistByIndex(index))
        return students[index];
    // todo:这列没有封装 Result 类，导致没有合适的返回类型
    return {};
}

Student DataSystem::getStudentByName(const string &name) {
    auto numptr = find_if(students.begin(), students.end(), [&name](Student &s) {
        return s.getName().compare(name);
    });
    if (numptr != students.end())
        return *numptr;
    else
        return {};
}

void DataSystem::showStudent(const Student &s) {
    cout << "姓名：" << s.getName() << endl;
    cout << "性别：" << s.getSex() << endl;
    cout << "专业：" << s.getMajor() << endl;
    cout << "编号：" << s.getAccount() << endl;
    cout << "数学成绩：" << s.getMath() << endl;
    cout << "计算机成绩：" << s.getComputer() << endl;
    cout << "英语成绩：" << s.getEnglish() << endl;
}

void DataSystem::sortStudentsBySum() {
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.getSum() < b.getSum();
    });
}

void DataSystem::showStudentsBySum() {
    int i = 1;
    cout << "姓名\t\t\t" << "排名\t" << "总成绩\t" << "英语\t" << "数学\t" << "计算机\t" << endl;
    for (const Student &student: students) {
        cout << student.getName() << "\t\t\t" << i++ << "\t" << student.getSum() << "\t" << student.getEnglish() << "\t"
             << student.getMath() << "\t" << student.getComputer() << "\t" << endl;
    }
}


double DataSystem::getSumForMath() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getMath();
    }
    return sum;
}

double DataSystem::getSumForComputer() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getComputer();
    }
    return sum;
}

double DataSystem::getSumForEnglish() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getEnglish();
    }
    return sum;
}

double DataSystem::getAveForMath() {
    return getSumForMath() / (double) students.size();
}

double DataSystem::getAveForComputer() {
    return getSumForComputer() / (double) students.size();
}

double DataSystem::getAveForEnglish() {
    return getSumForEnglish() / (double) students.size();
}

double DataSystem::getAPassingGradeForMath() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getMath() >= 60;
    }
    return sum / (double) students.size() * 100;
}

double DataSystem::getAPassingGradeForComputer() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getComputer() >= 60;
    }
    return sum / (double) students.size() * 100;
}

double DataSystem::getAPassingGradeForEnglish() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getEnglish() >= 60;
    }
    return sum / (double) students.size() * 100;
}

Student DataSystem::getStudentByAccount(string account) {
    auto numptr = find_if(students.begin(), students.end(), [&account](Student &s) {
        return s.getAccount().compare(account);
    });
    if (numptr != students.end())
        return *numptr;
    else
        return {};
}
