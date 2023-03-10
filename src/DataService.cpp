#include "../include/DataService.h"

int DataService::loadFromJson(string path) {
    // load from json
    Json::Value jsonRoot;
    Json::Reader jsonReader;
    ifstream ifs;
    ifs.open(path);
    if (!jsonReader.parse(ifs, jsonRoot)) {
        return 0;
    }
    ifs.close();
    // save as student
    for (auto item: jsonRoot) {
        for (auto user: item) {
            Student s(user);
            if(s.getRole())
            students.push_back(s);
        }
    }
    return 1;
}

void DataService::addStudent(Student &student) {
    students.push_back(student);
}

void DataService::deleteStudentByIndex(int index) {
    students.erase(students.begin() + index);
}

unsigned long long DataService::getStudentSize() {
    return students.size();
}

bool DataService::ifExistByIndex(int index) {
    return index < students.size() && index >= 0;
}

void DataService::changeStudentByIndex(int index, Student &s) {
    students[index] = s;
}

Student DataService::getStudentByIndex(int index) {
    // 索引获取值要判空
    if (ifExistByIndex(index))
        return students[index];
    return {};
}

Student DataService::getStudentByName(const string &name) {
    auto numptr = find_if(students.begin(), students.end(), [&name](Student &s) {
        return !s.getName().compare(name);
    });
    if (numptr != students.end())
        return *numptr;
    else
        return {};
}

void DataService::showStudent(const Student &s) {
    cout << "姓名：" << s.getName() << endl;
    cout << "性别：" << s.getSex() << endl;
    cout << "专业：" << s.getMajor() << endl;
    cout << "编号：" << s.getAccount() << endl;
    cout << "数学成绩：" << s.getMath() << endl;
    cout << "计算机成绩：" << s.getComputer() << endl;
    cout << "英语成绩：" << s.getEnglish() << endl;
}

void DataService::sortStudentsBySum() {
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.getSum() > b.getSum();
    });
}

void DataService::showStudentsBySum() {
    int i = 1;
    cout << "姓名\t\t\t" << "排名\t" << "总成绩\t" << "英语\t" << "数学\t" << "计算机\t" << endl;
    for (const Student &student: students) {
        cout << student.getName() << "\t\t\t" << i++ << "\t" << student.getSum() << "\t\t" << student.getEnglish() << "\t"
             << student.getMath() << "\t" << student.getComputer() << "\t" << endl;
    }
}

double DataService::getSumForMath() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getMath();
    }
    return sum;
}

double DataService::getSumForComputer() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getComputer();
    }
    return sum;
}

double DataService::getSumForEnglish() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getEnglish();
    }
    return sum;
}

double DataService::getAveForMath() {
    return getSumForMath() / (double) students.size();
}

double DataService::getAveForComputer() {
    return getSumForComputer() / (double) students.size();
}

double DataService::getAveForEnglish() {
    return getSumForEnglish() / (double) students.size();
}

double DataService::getAPassingGradeForMath() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getMath() >= 60;
    }
    return sum / (double) students.size() * 100;
}

double DataService::getAPassingGradeForComputer() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getComputer() >= 60;
    }
    return sum / (double) students.size() * 100;
}

double DataService::getAPassingGradeForEnglish() {
    double sum = 0;
    for (auto &student: students) {
        sum += student.getEnglish() >= 60;
    }
    return sum / (double) students.size() * 100;
}

Student DataService::getStudentByAccount(string account) {
    auto numptr = find_if(students.begin(), students.end(), [&account](Student &s) {
        return !s.getAccount().compare(account);
    });
    if (numptr != students.end())
        return *numptr;
    else
        return {};
}

nGrade DataService::getMathGrade() {
    nGrade ngrade={0,0,0,0,0};
    for (auto &student: students) {
        ngrade.nA+=student.getMath()<60;
        ngrade.nB+=student.getMath()>=60&&student.getMath()<=69;
        ngrade.nC+=student.getMath()>=70&&student.getMath()<=79;
        ngrade.nD+=student.getMath()>=80&&student.getMath()<=89;
        ngrade.nE+=student.getMath()>=90&&student.getMath()<=100;
    }
    return ngrade;
}

nGrade DataService::getComputerGrade() {
    nGrade ngrade={0,0,0,0,0};
    for (auto &student: students) {
        ngrade.nA+=student.getComputer()<60;
        ngrade.nB+=student.getComputer()>=60&&student.getComputer()<=69;
        ngrade.nC+=student.getComputer()>=70&&student.getComputer()<=79;
        ngrade.nD+=student.getComputer()>=80&&student.getComputer()<=89;
        ngrade.nE+=student.getComputer()>=90&&student.getComputer()<=100;
    }
    return ngrade;
}

nGrade DataService::getEnglishGrade() {
    nGrade ngrade={0,0,0,0,0};
    for (auto &student: students) {
        ngrade.nA+=student.getEnglish()<60;
        ngrade.nB+=student.getEnglish()>=60&&student.getEnglish()<=69;
        ngrade.nC+=student.getEnglish()>=70&&student.getEnglish()<=79;
        ngrade.nD+=student.getEnglish()>=80&&student.getEnglish()<=89;
        ngrade.nE+=student.getEnglish()>=90&&student.getEnglish()<=100;
    }
    return ngrade;
}

void DataService::drawChart(nGrade ngrade) {
    cout<<"0~59\t";
    for(int i=0;i<ngrade.nA;i++)
        cout<<"*";
    cout<<endl;
    cout<<"60~69\t";
    for(int i=0;i<ngrade.nB;i++)
        cout<<"*";
    cout<<endl;
    cout<<"70~79\t";
    for(int i=0;i<ngrade.nC;i++)
        cout<<"*";
    cout<<endl;
    cout<<"80~89\t";
    for(int i=0;i<ngrade.nD;i++)
        cout<<"*";
    cout<<endl;
    cout<<"90~100\t";
    for(int i=0;i<ngrade.nE;i++)
        cout<<"*";
    cout<<endl;
}










