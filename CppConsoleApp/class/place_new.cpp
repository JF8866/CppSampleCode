//
//  place_new.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/2.
//

#include "place_new.hpp"
#include <iostream>
#include <string>
#include <new>
using namespace std;

const int BUF = 512;

class JustTest {
private:
    string words;
    int number;
public:
    JustTest(const string & s = "Just Test", int n = 0) {
        words = s;
        number = n;
        cout << words << " constructed\n";
    }
    ~JustTest() {
        cout << words << " destroyed\n";
    }
    void Show() const {
        cout << words << ", " << number << endl;
    }
};

void testPlaceNew() {
    char * buffer = new char[BUF];
    
    JustTest *pc1, *pc2;
    pc1 = new (buffer) JustTest;
    pc2 = new JustTest("Heap1", 20);
    
    cout << "Memory block addresses:\n" << "buffer: " << (void *) buffer << "   heap: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();
    
    JustTest *pc3, *pc4;
    //加偏移避免覆盖pc1
    pc3 = new (buffer + sizeof(JustTest)) JustTest("Better Idea", 6);
    pc4 = new JustTest("Heap2", 10);
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();
    
    delete pc2;
    delete pc4;
    //显式销毁对象
    pc3->~JustTest();//先销毁创建的比较晚的对象
    pc1->~JustTest();//再销毁创建的比较早的对象
    delete [] buffer;//该语句不会触发内存中存储的对象的析构函数
    cout << "Done\n";
}
