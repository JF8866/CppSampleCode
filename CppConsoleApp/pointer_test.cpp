//
//  pointer_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/13.
//

#include "pointer_test.hpp"


void newArray() {
    const int len = 10;
    //使用 new 创建一个数组
    int *arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //释放数组，注意 delete 后面的中括号
    delete [] arr;
}

char * getName() {
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);
    return pn;
}


unique_ptr<int> make_int(int n) {
    return unique_ptr<int>(new int(n));
}

void show(unique_ptr<int> & pi) {//按引用传递
    cout << *pi << ' ';
}

/* 三个智能指针模板（auto_ptr、unique_ptr和shared_ptr）都定义了类似指针的对象，可以将new获得（直接或间接）的地址赋给这种对象。当智能指针过期时，其析构函数将使用delete来释放内存。因此，如果将new返回的地址赋给这些对象，将无需记住稍后释放这些内存：在智能指针过期时，这些内存将自动被释放。 */
void smartPointer() {
    unique_ptr<double> pd(new double);
    shared_ptr<string> ps(new string);
    
    cout << string(50, '*') << endl;
    
    //auto_ptr 采用所有权策略，对于特定的对象，只能有一个智能指针可拥有它，这
    //样只有拥有对象的智能指针的构造函数会删除该对象。然后，让赋值操作转让所有权。
    //但 auto_ptr 允许赋值操作，当把一个 auto_ptr 对象赋值给另一个 auto_ptr
    //对象后，原先的指针将不再指向有效数据
    
    //unique_ptr 也采用所有权策略，对于特定的对象，只能有一个智能指针可拥有它，这
    //样只有拥有对象的智能指针的构造函数会删除该对象。然后，让赋值操作转让所有权。
    //unique_ptr 与 auto_ptr 地区别在于，禁止把一个已经存在的 unique_ptr
    //对象赋值给另一个 unique_ptr 对象
    unique_ptr<Report> upr (new Report("using unique_ptr"));
    upr->comment();
    
    //shared_ptr 采用引用计数策略，仅当最后一个指针过期时，才调用 delete
    shared_ptr<Report> spr (new Report("using shared_ptr"));
    spr->comment();
    
    
    unique_ptr<string> films[5] = {
        unique_ptr<string>(new string("Fow1 Balls")),
        unique_ptr<string>(new string("Duck Walks")),
        unique_ptr<string>(new string("Chicken Runs")),
        unique_ptr<string>(new string("Turkey Errors")),
        unique_ptr<string>(new string("Goose Eggs"))
    };
    unique_ptr<string> pwin;
    //pwin = films[2];//不允许赋值
    pwin = unique_ptr<string>(new string("Yo!"));//允许赋值
    pwin = move(films[2]);//unique_ptr作为函数的返回值，允许赋值
    
    /* 使用new分配内存时，才能使用auto_ptr和shared_ptr，使用new []分配内存时，不能使用它们。
     不使用new分配内存时，不能使用auto_ptr或shared_ptr；不使用new或new []分配内存时，不能使
     用unique_ptr。  */
    
    vector<unique_ptr<int>> vp(5);
    for (int i = 0; i < vp.size(); i++) {
        vp[i] = make_int(rand() % 1000);
    }
    vp.push_back(make_int(rand() % 1000));
    for_each(vp.begin(), vp.end(), show);
    cout << endl;
}

void testPointer() {
    int nights = 1001;
    //使用 new 在运行时分配内存
    int *pt = new int;
    *pt = 1001;
    
    cout << "nights value = " << nights
        << ": location " << &nights
        << endl;
    
    cout << "int value = " << *pt
        << ": location " << pt
        << endl;
    
    cout << "sizeof(pt) = " << sizeof(pt)
        << ", sizeof(*pt) = " << sizeof(*pt)
        << endl;
    
    delete pt;
//    delete pt;//不能重复释放已经释放的内存块
    //???释放后还能用
    *pt = 1002;
    cout << *pt << endl;
    
    int x = 5;
    int *px = &x;
//    delete px;//delete 只能用来释放 new 分配的内存块，这行在运行时报错
    
    newArray();
    
    char *name = getName();
    cout << name << " at " << (int*)name << endl;
    delete [] name;
    
    smartPointer();
}
