//
//  useless.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/17.
//

#include "useless.hpp"
#include <iostream>
#include <utility>

using namespace std;

// interface
class Useless {
private:
    int n;
    char * pc;
    static int ct;
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f);//常规复制构造函数
//    Useless(Useless && f);//move constructor
    ~Useless();
    Useless operator+(const Useless & f) const;
    Useless & operator=(const Useless & f);
    Useless & operator=(Useless && f);
    void ShowData() const;
};


// implementation
int Useless::ct = 0;

Useless::Useless() {
    ct++;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k) {
    ct++;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k) {
    ct++;
    cout << "int, char constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = ch;
    }
    ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n) {
    ct++;
    cout << "copy constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = f.pc[i];
    }
    ShowObject();
}

//移动构造函数，&& f 声明 f 是一个右值引用
//Useless::Useless(Useless && f) : n(f.n) {
//    ct++;
//    cout << "move constructor called; number of objects: " << ct << endl;
//    pc = f.pc;  //steal address
//    f.pc = nullptr;
//    f.n = 0;
//    ShowObject();
//}

Useless::~Useless() {
    ct--;
    cout << "destructor called; objects left: " << ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete [] pc;
}

Useless & Useless::operator=(const Useless &f) {
    cout << "copy 赋值运算符方法\n";
    if(this == &f) return *this;
    delete [] pc;
    n = f.n;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = f.pc[i];
    }
    return *this;
}

Useless & Useless::operator=(Useless &&f) {
    cout << "move 赋值运算符方法\n";
    if(this == &f) return *this;
    delete [] pc;
    n = f.n;
    pc = f.pc;
    f.n = 0;
    f.pc = nullptr;
    return *this;
}

Useless Useless::operator+(const Useless &f) const {
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++) {
        temp.pc[i] = pc[i];
    }
    for (int i = n; i < temp.n; i++) {
        temp.pc[i] = f.pc[i - n];
    }
    cout << "temp object:\n";
    cout << "Leaving operator+()\n";
    return temp;
}

void Useless::ShowObject() const {
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void*) pc << endl;
}

void Useless::ShowData() const {
    if(n == 0)
        cout << "(object empty)";
    else
        for (int i = 0; i < n; i++) {
            cout << pc[i];
        }
    cout << endl;
}

void case1() {
    Useless one(10, 'x');
    Useless two = one; //调用复制构造函数
    Useless three(20, 'o');
    Useless four(one + three);//调用 + 运算符函数以及移动构造函数
    cout << "object one: ";
    one.ShowData();
    cout << "object two: ";
    two.ShowData();
    cout << "object three: ";
    three.ShowData();
    cout << "object four: ";
    four.ShowData();
}

void case2() {
    Useless one(10, 'x');
    Useless two = one + one;
    cout << "object one: ";
    one.ShowData();
    cout << "object two: ";
    two.ShowData();
    
    Useless three, four;
    cout << "three = one\n";
    three = one;//调用 copy 版赋值运算符方法
    cout << "now object three = ";
    three.ShowData();
    cout << "and object one = ";
    one.ShowData();
    cout << "four = one + two\n";
    four = one + two;//调用 move 版赋值运算符方法
    cout << "now object four = ";
    four.ShowData();
    cout << "four = move(one)\n";
    four = move(one);//强制调用 move 版赋值运算符方法
    cout << "now object four = ";
    four.ShowData();
    cout << "and object one = ";
    one.ShowData();
}

void testMoveConstructor() {
//    case1();
    case2();
}
