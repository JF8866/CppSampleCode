//
//  worker.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/5.
//

#ifndef worker_hpp
#define worker_hpp

#include <stdio.h>
#include <string>

// MI 是多重继承的简写

//觉得多重继承简直反人类，这里只抄了个头文件就。。。
//如果想再次了解多重继承可以参考《C++ Primer Plus》（第6版）14.3 多重继承

//抽象基类
class Worker {
private:
    std::string fullname;
    long id;
public:
    Worker() : fullname("no one"), id(0) {}
    Worker(const std::string & s, long n) : fullname(s), id(n) {}
    virtual ~Worker() = 0;//纯虚析构函数，类似Java的抽象方法
    virtual void Show() const;
};


// Waiter
class Waiter : public Worker {
private:
    int panache;
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
    Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};


// Singer
class Singer : public Worker {
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};//通过枚举定义常量
private:
    static char * pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other) : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};


#endif /* worker_hpp */
