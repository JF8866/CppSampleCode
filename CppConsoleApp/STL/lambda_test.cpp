//
//  lambda_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/17.
//

#include "lambda_test.hpp"


void testLambda() {
    vector<int> numbers(100);
    generate(numbers.begin(), numbers.end(), rand);
    
    //C++的 Lambda 函数以中括号代替函数名，即匿名函数
    long count = count_if(numbers.begin(), numbers.end(), [](int x) { return x % 3 == 0; });
    printf("count=%ld\n", count);
    
    //仅当 lambda 表达式只有一条返回语句时，自动类型推断才管用；否则，需要显示声明返回类型
    count = count_if(numbers.begin(), numbers.end(), [](int x) -> bool {
        int y = x * x;
        return x % 13 == 0;
    });
    printf("count=%ld\n", count);
    
    int count3 = 0;//numbers中能被3整除的元素数量
    int count13 = 0;//numbers中能被13整除的元素数量
    // Lambda 表达式的中括号中指定按引用或者按值访问作用域内的变量
    for_each(numbers.begin(), numbers.end(), [&](int x) {
//        printf("x=%d\n", x);
        count3 += (x % 3 == 0);
        count13 += (x % 13 == 0);
//        if(x % 3 == 0) count3++;
//        if(x % 13 == 0) count13++;
    });
    printf("count3=%d, count13=%d\n", count3, count13);
}


double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

void testWrapper() {
    double y = 1.21;
//    cout << "Function pointer dub:\n";
//    cout << " " << use_f(y, dub) << endl;
//    cout << "Function pointer square:\n";
//    cout << " " << use_f(y, square) << endl;
//
//    cout << "Function object Fp:\n";
//    cout << " " << use_f(y, Fp(5.0)) << endl;
//    cout << "Function object Fq:\n";
//    cout << " " << use_f(y, Fq(5.0)) << endl;
//
//    cout << "Lambda expression 1:\n";
//    cout << " " << use_f(y, [](double u) { return u * u; }) << endl;
//    cout << "Lambda expression 2:\n";
//    cout << " " << use_f(y, [](double u) { return u + u / 2.0; }) << endl;
    
    
    //使用包装器，这样只会创建一个 use_f 实例
//    function<double(double)> fun_dub = dub;
//    function<double(double)> fun_square = square;
//    function<double(double)> fun_fp = Fp(5.0);
//    function<double(double)> fun_fq = Fq(5.0);
//    function<double(double)> fun_ef5 = [](double u) { return u * u; };
//    function<double(double)> fun_ef6 = [](double u) { return u + u / 2.0; };
//
//    typedef function<double(double)> fdd;
    
    cout << "Function pointer dub:\n";
    cout << " " << use_f<double>(y, dub) << endl;
    cout << "Function pointer square:\n";
    cout << " " << use_f<double>(y, square) << endl;
    
    cout << "Function object Fp:\n";
    cout << " " << use_f<double>(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << " " << use_f<double>(y, Fq(5.0)) << endl;
    
    cout << "Lambda expression 1:\n";
    cout << " " << use_f<double>(y, [](double u) { return u * u; }) << endl;
    cout << "Lambda expression 2:\n";
    cout << " " << use_f<double>(y, [](double u) { return u + u / 2.0; }) << endl;
}


void show_list() {
}

template<typename T>
void show_list(T value) {
    cout << value << endl;
}

template<typename T, typename... Args>
void show_list(T value, Args... args) {
    cout << value << ", ";
    show_list(args...);
}

void testVarargs() {
    int n = 14;
    double x = 2.71828;
    string mr = "Mr. String objects";
    show_list(n, x);
    show_list(x * x, '!', 7, mr);
}
