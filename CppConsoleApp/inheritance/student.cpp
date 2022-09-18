//
//  student.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/5.
//

#include "student.hpp"

using std::ostream;
using std::istream;
using std::endl;
using std::string;
using std::cout;
using std::cin;

double Student::Average() const {
    //“包含”使用对象来调用方法
//    if(scores.size() > 0) {
//        return  scores.sum() / scores.size();
//    }
    
    //私有继承使用类名和作用域解析运算符来调用基类的方法
    if(ArrayDb::size() > 0) {
        return ArrayDb::sum() / ArrayDb::size();
    }
    
    return 0;
}

const string & Student::Name() const {
//    return name;
    return (const string &) *this;
}

double & Student::operator[](int i) {
//    return scores[i];
    return ArrayDb::operator[](i);
}

double Student::operator[](int i) const {
//    return scores[i];
    return ArrayDb::operator[](i);
}

std::ostream & Student::arr_out(std::ostream &os) const {
    int i;
//    int lim = (int)scores.size();
    int lim = (int)ArrayDb::size();
    if(lim > 0) {
        for (i = 0; i < lim; i++) {
//            os << scores[i] << " ";
            os << ArrayDb::operator[](i) << " ";
            if(i % 5 == 4)
                os << std::endl;
        }
        if(i % 5 != 0)
            os << std::endl;
    } else {
        os << " empty array ";
    }
    return os;
}

std::ostream & operator<<(std::ostream & os, const Student & stu) {
    //    os << "Scores for " << stu.name << ":\n";
    //私有继承中，在不进行显式类型转换的情况下，不能将指向派生类的引用或指针赋给基类引用或指针
    os << "Scores for " << (const string &)stu << ":\n";//调用 string 的友元函数
    stu.arr_out(os);
    return os;
}

istream & operator>>(istream & is, Student & stu) {
//    is >> stu.name;
    is >> (string &) stu;
    return is;
}

istream & getline(istream & is, Student & stu) {
//    getline(is, stu.name);//调用 string 的友元函数
    getline(is, (string &) stu);
    return is;
}

Student::~Student() {
    
}


//测试代码

void set(Student & sa, int n) {
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++) {
        cin >> sa[i];
    }
    while (cin.get() != '\n') {
        continue;
    }
}

void testStudent() {
    const int pupils = 3;
    const int quizzes = 5;
    
    Student ada[pupils] = {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };
    int i;
    for (i = 0; i < pupils; ++i) {
        set(ada[i], quizzes);
    }
    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; i++) {
        cout << ada[i].Name() << endl;
    }
    cout << "\nResults:";
    for (i = 0; i < pupils; i++) {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
}
