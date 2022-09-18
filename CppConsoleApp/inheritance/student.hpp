//
//  student.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/5.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <valarray>

//通常，应使用包含来建立has-a关系；如果新类需要访问原有类的保护成员，或需要重新定义虚函数，则应使用私有继承。

/* 传统的 has-a 关系是通过包含另一个类的实例，来使用其功能，使用私有继承也可以实现 has-a 关系，之所以叫私有继承，是因为只能在类内部使用所继承的类的接口，但不会继承基类接口。 */
class Student : private std::string, private std::valarray<double> {
private:
    typedef std::valarray<double> ArrayDb;
//    std::string name;//包含
//    ArrayDb scores;
    std::ostream & arr_out(std::ostream & os) const;
public:
    //当初始化列表包含多个项目时，这些项目被初始化的顺序为它们被声明的顺序，而不是它们在初始化列表中的顺序。
//    Student() : name("Null Student"), scores() {}
//    explicit Student(const std::string & s) : name(s), scores() {}
//    explicit Student(int n) : name("Nully"), scores(n) {}
//    Student(const std::string & s, int n) : name(s), scores(n) {}
//    Student(const std::string & s, const ArrayDb & a) : name(s), scores(a) {}
//    Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {}
    
    //继承
    Student() : std::string("Null Student"), ArrayDb() {}
    explicit Student(const std::string & s) : std::string(s), ArrayDb() {}
    explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
    Student(const std::string & s, int n) : std::string(s), ArrayDb(n) {}
    Student(const std::string & s, const ArrayDb & a) : std::string(s), ArrayDb(a) {}
    Student(const char * str, const double * pd, int n) : std::string(str), ArrayDb(pd, n) {}
    
    ~Student();
    double Average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;
    
    //
    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);
    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
    
    //使用私有继承或保护继承时，可以使用 using 暴露基类接口，就像它们是 Student 的共有方法一样
    using std::valarray<double>::min;
    using std::valarray<double>::max;
};

void testStudent();

#endif /* student_hpp */
