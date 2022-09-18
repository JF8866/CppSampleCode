//
//  vector_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/14.
//

#include "vector_test.hpp"
#include <ctime>

using namespace std;
const int ArSize = 16;


//计算0～15的阶乘
void calFactorials() {
    long long factorials[16];
    factorials[0] = factorials[1] = 1LL;
    for (int i = 2; i < ArSize; i++) {
        factorials[i] = i * factorials[i - 1];
    }
    for (int i = 0; i < ArSize; i++) {
        cout << i << "! = " << factorials[i] << endl;
    }
    //C++11新增的循环语法
    for(long long item : factorials) {
        cout << item << endl;
    }
    //&符号表明 item 是一个引用变量，可以对其值进行修改
    for(long long &item : factorials) {
        item /= 2;
    }
    
    for(int x : {1,2,3}) {
        cout << x << " ";
    }
    cout << endl;
}

void delay(double seconds) {
    cout << "befor delay" << endl;
    clock_t clocks = seconds * CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock() - start < clocks);
    cout << "after delay" << endl;
}

void show_double(double d) {
    cout << d << '\t';
}

void show_vd(const vector<double> & vd) {
    //使用 for_each() 函数遍历元素
    for_each(vd.begin(), vd.end(), show_double);
    cout << endl;
}

//迭代器
void testIterator() {
    cout << string(20, '*') << " testIterator() " << string(20, '*') << endl;
    
    vector<int> vi(5);
    //使用迭代器遍历元素，迭代器用法类似指针
    vector<int>::iterator it;
    for (it = vi.begin(); it != vi.end(); it++) {
        *it = rand() % 5 + 1;
    }
    for (auto iterator = vi.begin(); iterator != vi.end(); iterator++) {
        cout << *iterator << '\t';
    }
    cout << endl;
    
    vector<double> vd;//创建一个空的集合
    for (int i = 0; i < 5; i++) {
        vd.push_back((i + 1) * 0.1);//尾部添加元素
    }
    
    //删除指定区间 [it1, it2) 的元素
    vd.erase(vd.begin() + 2, vd.begin() + 4);
    
    //把 vi 的前两个元素插入到 vd 第2个元素的后面
//    vd.insert(vd.begin() + 2, vi.begin(), vi.begin() + 2);
    
    //把 vi 的所有元素追加到 vd 后面
    vd.insert(vd.end(), vi.begin(), vi.end());
    
    show_vd(vd);
    
//    random_shuffle(vd.begin(), vd.end());//打乱顺序
    
    
    //排序
    sort(vd.begin(), vd.end());
    
    show_vd(vd);
    
    //基于范围的 for 循环(C++11)，使用引用可修改元素
    for(auto & item : vd) {
        item += 1;
    }
    
    show_vd(vd);
    
    //将 vi 的数据复制到 vd 中，从指定的 vd 位置开始
    copy(vi.begin(), vi.begin() + 5, vd.begin());
    
    //从输入流中读取，直到文件结尾、类型不匹配或出现其他输入故障为止
//    istream_iterator<double, char> in_iter(cin);
//    copy(in_iter, istream_iterator<double, char>(), vd.begin());
    
    //把数据拷贝到输出流中，\t是分隔符
    ostream_iterator<double, char> out_iter(cout, "\t");
    copy(vd.begin(), vd.end(), out_iter);
    //使用反向迭代器反向输出
//    copy(vd.rbegin(), vd.rend(), out_iter);
    cout << endl;
    
    //back_insert_iterator 用于将元素插入到容器尾部
    back_insert_iterator<vector<double>> back_iter(vd);
    //把 vi 的前两个元素追加到 vd 的末尾
    copy(vi.begin(), vi.begin() + 2, back_iter);
    show_vd(vd);
    
    //把 vi 的第一个元素插入到 vd 的最前面
    insert_iterator<vector<double>> insert_iter(vd, vd.begin());
    copy(vi.begin(), vi.begin() + 1, insert_iter);
    show_vd(vd);
    
    //front_insert_iterator 用于将元素插入到指定的位置前面，但是不适用于 vector
//    front_insert_iterator<vector<double>> front_iter(vd);
}



// vector 类似 Java 的 List，使用 new 和 delete 动态管理内存，且这种工作是自动完成的
/* vector类的功能比数组强大，但付出的代价是效率稍低。如果您需要的是长度固定的数组，使用数组是更佳的选择，但代价是不那么方便和安全。有鉴于此，C++11新增了模板类array，它也位于名称空间std中。与数组一样，array对象的长度也是固定的，也使用栈（静态内存分配），而不是自由存储区，因此其效率与数组相同，但更方便，更安全。 */
void testVector() {
    vector<int> vi;//create a zero-size array of int
    vector<double> vd(10);//create an array of 10 doubles
    
    array<int, 5> ai;//create array object of 5 ints
    array<double, 4> ad = { 1.2, 2.1, 3.43, 4.3 };
    
    //C, original C++
    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    //C++98 STL
    vector<double> a2(4);
    a2[0] = 1.0/3.0;
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;
    //C++11 -- crete and initialize array object
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;
    a4 = a3;//valid for array objects of same size
    //use array notation
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    //misdeed
    //从打印的地址可知，array 和普通数组都存储在栈中，而vector存储在堆中
//    a1[-2] = 20.2;//这样会越界修改相邻地址的数组元素
//    a2.at(-2) = 2.3;//vector.at()方法会检测索引是否越界，如果越界则触发异常
    a3.at(2) = 2.3;//array.at()
//    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    
//    calFactorials();
//    delay(3.0);
    testIterator();
}

