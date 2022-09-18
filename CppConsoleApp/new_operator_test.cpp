//
//  new_operator_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/21.
//

#include "new_operator_test.hpp"

void newPlace();

char buffer[BUF];//开辟一块静态内存

void testNewOperator() {
    // new 运算符初始化
    int *pi = new int(6);
    double *pd = new double{99.99};
    int *ar = new int[4]{1, 2, 3, 4};
    Xyz *one = new Xyz {1.2, 2.3, 3.4};
    
    delete pi;
    delete pd;
    delete [] ar;
    delete one;
    
    newPlace();
}

// new 运算符定位
void newPlace() {
    int i;
    
//    cout << (0x618 - 0x5f0) << endl;
    
    cout << "Calling new and placement new:\n";
    double* pd1, *pd2;
    pd1 = new double[N];//use heap
    pd2 = new (buffer) double[N];//use buffer array
    for (i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    }
    cout << "Memory addresses:\n" << "  heap: " << pd1
          << "  static: " << (void*)buffer << endl;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    
    cout << "\nCalling new and placement new a second time:\n";
    double* pd3, *pd4;
    pd3 = new double[N];//use heap
    pd4 = new (buffer) double[N];//use buffer array
    for (i = 0; i < N; i++) {
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    }
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }
    
    cout << "\nCalling new and placement new a third time:\n";
    delete [] pd1;
    pd1 = new double[N];//use heap
    pd2 = new (buffer + N * sizeof(double)) double[N];//use buffer array
    for (i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 60.0 * i;
    }
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    delete [] pd1;
    delete [] pd3;
}
