#ifndef DEMO_DATASYSTEM_H
#define DEMO_DATASYSTEM_H
#include <fstream>
#include <vector>
#include "Student.h"
#include <algorithm>
#include <iostream>
#include "./json/json.h"
struct nGrade{
    int nA,nB,nC,nD,nE;
};
class DataSystem {
    vector<Student> students{};
public:
    int loadFromJson(string);
    void addStudent(Student&);
    void changeStudentByIndex(int,Student &);
    void deleteStudentByIndex(int);
    Student getStudentByIndex(int);
    Student getStudentByName(const string &);
    Student getStudentByAccount(string);
    static void showStudent(const Student& s);
    void sortStudentsBySum();
    void showStudentsBySum();
    unsigned long long getStudentSize();
    double getSumForMath();
    double getSumForComputer();
    double getSumForEnglish();
    double getAveForMath();
    double getAveForComputer();
    double getAveForEnglish();
    double getAPassingGradeForMath();
    double getAPassingGradeForComputer();
    double getAPassingGradeForEnglish();
    nGrade getMathGrade();
    nGrade getComputerGrade();
    nGrade getEnglishGrade();
    void drawChart(nGrade);
    bool ifExistByIndex(int);
};

#endif //DEMO_DATASYSTEM_H
