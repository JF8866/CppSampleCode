//
//  stock.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/27.
//

#include "stock.hpp"

//实现默认构造函数
Stock::Stock() {
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

//实现自定义构造函数
Stock::Stock(const std::string &co, long n, double pr) {
    company = co;
    if(n < 0) {
        std::cout << "Number of shares can't be negative; "
                    << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::acquire(const std::string &co, long n, double pr) {
    company = co;
    if(n < 0) {
        std::cout << "Number of shares can't be negative; "
                    << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price) {
    if(num < 0) {
        std::cout << "Number of shares purchased can't be negative. "
                    << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using std::cout;
    if(num < 0) {
        cout << "Number of shares sold can't be negative. "
        << "Transaction is aborted.\n";
    } else if(num > shares) {
        cout << "You can't sell more than you have! "
        << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() const {//const 保证函数不会修改调用对象
    using std::cout;
    using std::ios_base;
    //set format to #.###
    ios_base::fmtflags  orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    
    std::cout << "Company: " << company
    << " Shares: " << shares << '\n';
    cout << " Share Price: $" << share_val;
    
    //set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';
    
    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

//每个成员函数（包括构造函数和析构函数）都有一个this指针。this指针指向调用对象。如果方法需要引用整个调用对象，则可以使用表达式*this。在函数的括号后面使用const限定符将this限定为const，这样将不能使用this来修改对象的值。
const Stock & Stock::topval(const Stock & stock) const {
    if(stock.total() > this->total_val) {//类可以像结构体那样使用 this 指针以及 -> 运算符访问成员
        return stock;
    }
    return *this;
}

Stock::~Stock() {
    //可以在此做一些清理工作
    std::cout << "~Stock()\n";
}

void testObjectArray() {
    //对象数组，要创建类对象数组，则这个类必须有默认(无参)构造函数
    const int stks = 4;
    Stock stocks[stks] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };
    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < stks; st++) {
        stocks[st].show();
    }
    const Stock *top = &stocks[0];
    for (st = 1; st < stks; st++) {
        top = &top->topval(stocks[st]);
    }
    std::cout << "\nMost valuable holding:\n";
    top->show();
}


void testClass() {
    Stock stock3;//默认(无参)构造函数
    Stock stock4 = Stock();
    Stock *pstock2 = new Stock;
    Stock stock = Stock("NanoSmart", 20, 12.50);//显式调用构造函数
    Stock stock2("NanoSmart", 20, 12.50);//隐式调用构造函数
    Stock *pstock = new Stock("NanoSmart", 20, 12.50);//new 构造函数返回的是指向实例的指针
    //stock.acquire("NanoSmart", 20, 12.50);
    stock.show();
    stock.buy(15, 18.125);
    stock.show();
    stock.sell(400, 20.00);
    stock.show();
    stock.buy(300000, 40.125);
    stock.show();
    stock.sell(300000, 0.125);
    stock.show();
    
    delete pstock;
    delete pstock2;
    
    testObjectArray();
}


