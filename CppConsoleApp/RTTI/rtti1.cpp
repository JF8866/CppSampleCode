//
//  rtti1.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#include "rtti1.hpp"
#include <typeinfo>

Grand * GetOne() {
    Grand * p = nullptr;
    int randNum = std::rand() % 3;
    cout << randNum << std::endl;
    switch (randNum) {
        case 0:
            p = new Grand(std::rand() % 100);
            break;
            
        case 1:
            p = new Superb(std::rand() % 100);
            break;
            
        case 2:
            p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
            break;
    }
    return p;
}

void change(const int * pt, int n) {
    int * pc;
    pc = const_cast<int *>(pt);
    *pc += n;
}

void testRTTI1() {
    std::srand(std::time(0));
    Grand * pg;
    Superb * ps;
    Magnificent * pm;
    for (int i = 0; i < 5; i++) {
        pg = GetOne();
        pg->Speak();
        //dynamic_cast 如果转换失败返回空指针0
        if((ps = dynamic_cast<Superb *>(pg))) {
            ps->Say();
        }
        
        // typeid 如果 pg 是一个空指针将引发 bad_cast 异常
        const std::type_info & type = typeid(*pg);
        if(typeid(Magnificent) == type) {
            cout << "type name = " << type.name() << endl;
            pm = (Magnificent *) pg;
            pm->Say();
        }
    }
    
    //const_cast
    int pop1 = 38383;
    const int pop2 = 2000;
    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    change(&pop1, -103);
    change(&pop2, -103);
    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    
    //reinterpret_cast
    struct dat { short a; short b; };//函数中定义结构
    long value = 0xA224B118;
    dat * pd = reinterpret_cast<dat *>(&value);
    cout << std::hex << pd->a << endl;// B118
    cout << std::hex << pd->b << endl;// A224
}
