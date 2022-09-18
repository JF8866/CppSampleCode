//
//  functor_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/12.
//

#include "functor_test.hpp"

using namespace std;

void print_double(double d) {
    std::cout << d << " ";
}

void print_int(int n) {
    std::cout << n << " ";
}

void show_ints(std::list<int> ls) {
    std::for_each(ls.begin(), ls.end(), print_int);
    std::cout << std::endl;
}

void xfunctor() {
    using std::list;
    using std::cout;
    using std::endl;
    
    TooBig<int> f100(100);
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10);
    list<int> etcetera(vals, vals + 10);
    
    cout << "Original lists:\n";
    show_ints(yadayada);
    show_ints(etcetera);
    
    yadayada.remove_if(f100);
    //通过传递重载过 () 运算符的函数对象，可以传递额外的参数
    etcetera.remove_if(TooBig<int>(200));
    
    cout << "Trimmed lists:\n";
    show_ints(yadayada);
    show_ints(etcetera);
}


void transformFunctor() {
    const int LIM = 6;
    double arr1[LIM] = {28, 29, 30, 35, 38, 59};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};
    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8: \t";
    for_each(gr8.begin(), gr8.end(), print_double);
    cout << endl;
    
    cout << "m8: \t";
    for_each(m8.begin(), m8.end(), print_double);
    cout << endl;
    
    vector<double> sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    cout << "sum: \t";
    for_each(sum.begin(), sum.end(), print_double);
    cout << endl;
    
    vector<double> prod(LIM);
    //书上C++11 第4个参数是 bind1st(multiplies<double>(), 2.5)
    //multiplies接受两个参数，其中绑定了1个，第2个参数由新的可调用对象指定(即 gr8 中的元素)
    transform(gr8.begin(), gr8.end(), prod.begin(), bind<double>(multiplies<>(), 2.5, std::placeholders::_1));
    cout << "prod: \t";
    for_each(prod.begin(), prod.end(), print_double);
    cout << endl;
}


void stringSTL() {
    //输入一组字符，输出所有的排列组合
    string letters;
    cout << "Enter the letter grouping (q to quit): ";
    while (cin >> letters && letters != "q") {
        cout << "Permutations of " << letters << endl;
        sort(letters.begin(), letters.end());
        cout << " letters\n";
        while (next_permutation(letters.begin(), letters.end())) {
            cout << letters << endl;
        }
        cout << "Enter next sequence (q to quit): ";
    }
}

void testFunctor() {
    Linear f1;
    Linear f2(2.5, 10.0);
    double y1 = f1(12.5);
    double y2 = f2(0.4);
    
    cout << "y1 = " << y1 << endl;
    cout << "y2 = " << y2 << endl;
    
    vector<double> vd(2);
    vd[0] = 12.5;
    vd[1] = 0.4;
    
//    for_each(vd.begin(), vd.end(), f1);
//    for_each(vd.begin(), vd.end(), f2);
    
//    xfunctor();
    transformFunctor();
//    stringSTL();
}
