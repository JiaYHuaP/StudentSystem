#include <iostream>
#include "../include/Menu.h"
#include<iomanip>
void Menu::managerMainMenu() {
    int point;
    while (true)
    {
        system("cls");//清屏  clear screen
        cout << "-----------高校学籍管理系统------------" << endl;
        cout << "1、展示所有学生信息" << endl;
        cout << "2、添加学生信息" << endl;
        cout << "3、更改指定信息" << endl;
        cout << "4、删除学生信息" << endl;
        cout << "5、查找指定学生信息" << endl;
        cout << "6、按成绩排名展示学生信息" << endl;
        cout << "7、各科平均成绩及及格率" << endl;
        cout << "8、班级学生成绩占比（柱状图）" << endl;
        cout << "0、退出" << endl;
        cout << "-------------------------------------" << endl;
        cout << "请输入你的命令" << endl;
        cin >> point;
        cout << "------------------------------------" << endl;
        system("cls");//清屏  clear screen
        switch (point)
        {
        case 1:
            dataSystem.showStudentsBySum();
            break;
        case 2:
            addStudentMenu();
            break;
        case 3:
            changeStudentMenu();
            break;
        case 4:
            deleteStudentMenu();
            break;
        case 5:
            searchStudentMenu();
            break;
        case 6:
            sortStudentMenu();
            break;
        case 7:
            subjectMenu();
            break;
        case 8:
            chartMenu();
            break;
        case 0:
            exit(0);
        default:
            cout << "输入错误，请重新输入：";
            break;
        }
        drawDelimiter();
    }
}

void Menu::drawDelimiter() {
    cout << "------------------------------------" << endl;
}

void Menu::addStudentMenu() {
    system("cls");
    int n;
    cout << "请输入要添加的学生人数：";
    cin >> n;
    // 1. 输入的值抽离出来
    string name, sex, major, num;
    double math, computer, english;
    for (int i = 0; i < n; i++) {
        cout << "请输入学生姓名：";
        cin >> name;
        cout << "请输入学生性别：";
        cin >> sex;
        while (sex != "男" && sex != "女")
        {
            cout << "请重新输入，只能输入男或女！";
            cin >> sex;
        }
        cout << "请输入学生专业：";
        cin >> major;
        cout << "请输入学生编号：";
        cin >> num;
        cout << "请输入学生数学成绩：";
        cin >> math;
        while (math > 100 || math < 0)
        {
            cout << "成绩应在[0,100]，请重新输入：";
            cin >> math;
        }
        cout << "请输入学生计算机成绩：";
        cin >> computer;
        while (computer > 100 || computer < 0)
        {
            cout << "成绩应在[0,100]，请重新输入：";
            cin >> computer;
        }
        cout << "请输入学生英语成绩：";
        cin >> english;
        while (english > 100 || english < 0)
        {
            cout << "成绩应在[0,100]，请重新输入：";
            cin >> english;
        }
        // 2. 用对象的构造函数接收输入
        Student s(name, sex,major, math, computer, english);
        // 3. 用数据管理接受
        dataSystem.addStudent(s);
    }
}

void Menu::changeStudentMenu() {
    int index, option = 1;
    cout << "请输入你要更改的学生的序号：";
    cin >> index;
    while (!dataSystem.ifExistByIndex(index)) {
        cout << "该学生不存在，学生序号范围为(0," << dataSystem.getStudentSize() << ")请重新选择：";
        cin >> index;
    }
    Student s = dataSystem.getStudentByIndex(index);
    string inputString;
    double inputDouble = 0;
    while (option) {
        cout << "1.姓名 2.性别 3.专业 4.编号 5.数学成绩 6.计算机成绩 7.英语成绩 0.退出";
        cout << "选择修改哪一项信息:";
        cin >> option;
        // 1. 输入的值抽离出来
        switch (option) {
        case 1:
            cout << "该学生姓名改为：";
            cin >> inputString;
            s.setName(inputString);
            break;
        case 2:
            cout << "该学生性别改为：";
            cin >> inputString;
            s.setSex(inputString);
            break;
        case 3:
            cout << "该学生专业改为：";
            cin >> inputString;
            s.setMajor(inputString);
            break;
        case 4:
            cout << "该学生编号改为：";
            cin >> inputString;
            s.setAccount(inputString);
            break;
        case 5:
            cout << "该学生数学成绩改为：";
            cin >> inputDouble;
            s.setMath(inputDouble);
            break;
        case 6:
            cout << "该学生计算机成绩改为：";
            cin >> inputDouble;
            s.setComputer(inputDouble);
            break;
        case 7:
            cout << "该学生英语成绩改为：";
            cin >> inputDouble;
            s.setEnglish(inputDouble);
            break;
        case 0:
            break;
        default:
            cout << "输入错误，请重新输入：";
            break;
        }
        if (option >= 0 && option <= 7)
            break;
    }
    // 2. 用对象的set函数接收输入
    if (option != 0)
        dataSystem.changeStudentByIndex(index, s);
    cout << "该学生信息为：" << endl;
    cout << "姓名\t\t\t" << "性别\t" <<"专业\t\t\t" <<"编号\t\t\t" << "英语成绩\t" << "数学成绩\t" << "计算机成绩\t" << endl;
    cout << s.getName() << "\t\t" << s.getSex() << "\t" << s.getMajor() << "\t" << s.getAccount() << "\t" << s.getEnglish() << "\t\t" << s.getMath() << "\t\t" << s.getComputer() << "\t\t" << endl;
}

void Menu::deleteStudentMenu() {
    int index;
    cout << "请输入你要删除学生的学号：";
    cin >> index;
    while (!dataSystem.ifExistByIndex(index))
    {
        cout << "该学生不存在，学生序号范围为[0," << dataSystem.getStudentSize() << ")请重新选择：";
        cin >> index;
    }
    dataSystem.deleteStudentByIndex(index);
    cout << "删除成功！" << endl;
}

void Menu::searchStudentMenu() {
    int t;
    string name;
    string num;
    cout << "请输入想查找学生的姓名（1）或学号（2）：";
    cin >> t;
    while (t != 1 && t != 2)
    {
        cout << "输入错误，请重新输入：";
        cout << "请输入想查找学生的姓名（1）或学号（2）：";
        cin >> t;
    }
    if (t == 1) {
        cout << "请输入学生姓名：";
        cin >> name;
        Student s=dataSystem.getStudentByName(name);
        if(s.getName()=="")
            cout<<"该学生不存在"<<endl;
        else
        DataSystem::showStudent(dataSystem.getStudentByName(name));

    }
    else if (t == 2) {
        cout << "请输入学生学号：";
        cin >> num;
        Student s=dataSystem.getStudentByAccount(num);
        if(s.getName()=="")
            cout<<"该学生不存在"<<endl;
        else
            DataSystem::showStudent(dataSystem.getStudentByAccount(num));
    }
}

void Menu::sortStudentMenu() {
    dataSystem.sortStudentsBySum();
    dataSystem.showStudentsBySum();
}

void Menu::subjectMenu() {
    cout << "数学平均成绩为：" <<setprecision (4)<< dataSystem.getAveForMath() << "\t\t\t" << "及格率为：" <<setprecision (4)<< dataSystem.getAPassingGradeForMath() <<"%"<< endl;
    cout << "英语平均成绩为： " <<setprecision (4) << dataSystem.getAveForEnglish()<< "\t\t\t" << "及格率为："<<setprecision (4) << dataSystem.getAPassingGradeForEnglish()<< "%" << endl;
    cout << "计算机平均成绩为：" <<setprecision (4)<< dataSystem.getAveForComputer() << "\t\t\t" << "及格率为："<<setprecision (4) << dataSystem.getAPassingGradeForComputer()<< "%" << endl;
}

void Menu::chartMenu() {
    cout<<"数学成绩柱状图："<<endl;
    dataSystem.drawChart(dataSystem.getMathGrade());
    cout<<"计算机成绩柱状图："<<endl;
    dataSystem.drawChart(dataSystem.getComputerGrade());
    cout<<"英语成绩柱状图："<<endl;
    dataSystem.drawChart(dataSystem.getEnglishGrade());
}

void Menu::studentMainMenu() {
    int point;
    while (true)
    {
        system("cls");//清屏  clear screen
        cout << "-----------高校学籍管理系统------------" << endl;
        cout << "1、查询信息" << endl;
        cout << "0、退出" << endl;
        cout << "-------------------------------------" << endl;
        cout << "请输入你的命令" << endl;
        cin >> point;
        cout << "------------------------------------" << endl;
        system("cls");//清屏  clear screen
        switch (point)
        {
            case 1:
                DataSystem::showStudent(dataSystem.getStudentByAccount(userSystem.getCurrentRole().getAccount()));
                break;
            case 0:
                exit(0);
            default:
                cout << "输入错误，请重新输入：";
                break;
        }
        drawDelimiter();
    }
}

void Menu::loginMenu() {
    string account,password;
    system("cls");//清屏  clear screen
    cout << "-----------登录------------" << endl;
    cout << "Account:  " << endl;
    cin >> account;
    cout << "Password: " << endl;
    cin >> password;
    cout << "------------------------------------" << endl;
    system("cls");//清屏  clear screen
    int res = userSystem.Login(account,password);
    if(res==0){
        Menu::managerMainMenu();
    }
    else if(res==1){
        Menu::studentMainMenu();
    }
    else{
        cout<<"账号或密码有误"<<endl;
        drawDelimiter();
    }
}

int Menu::loadFromJson(string path) {
    return dataSystem.loadFromJson(path) && userSystem.loadFromJson(path);
}



