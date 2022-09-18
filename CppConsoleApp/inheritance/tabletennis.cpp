//
//  tabletennis.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/4.
//

#include <iostream>
#include "tabletennis.hpp"
#include "brass.hpp"
#include "dma.hpp"

void fr(BaseAcct & rb);
void fp(BaseAcct * pb);

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht) {}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

//调用父类的构造函数初始化父类成员
RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht) {
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r) {}


void testBrass() {
    using std::cout;
    using std::endl;
    using std::cin;
    
    Brass piggy("Porcelot Pigg", 381299, 4000.0);
    BrassPlus hoggy("Horatio Hogg", 382288, 3000.0);
    piggy.ViewAcct();
    cout << endl;
    
    hoggy.ViewAcct();
    cout << endl;
    cout << "Depositing $1000 into the Hogg Account:\n";
    hoggy.Deposit(1000);
    cout << "New balance: $" << hoggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Pigg Account:\n";
    piggy.Withdraw(4200);
    cout << "Pigg account balance: $" << piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Hogg Account:\n";
    hoggy.Withdraw(4200);
    hoggy.ViewAcct();
    
    //多态只能由引用或指针体现出来，按值传递只调用基类方法
    cout << "多态" << endl;
    fr(piggy);
    fr(hoggy);
    cout << endl;
    fp(&piggy);
    fp(&hoggy);
    cout << endl;

    
    //数组要装下具有继承关系的多个类，元素需要使用指向基类的指针
    int clients = 4;
    BaseAcct * p_clients[clients];
    string temp;
    long tempnum;
    double tempbal;
    char kind;
    
    for (int i = 0; i < clients; i++) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or 2 fro BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2')) {
            cout << "Enter either 1 or 2: ";
        }
        if(kind == '1') {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        } else {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n') {
            continue;
        }
    }
    cout << endl;
    for (int i = 0; i < clients; i++) {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for (int i = 0; i < clients; i++) {
        delete p_clients[i];
    }
    cout << "Done.\n";
}


void fr(BaseAcct & rb) {
    rb.ViewAcct();
}

void fp(BaseAcct * pb) {
    pb->ViewAcct();
}



void testInheritance() {
    using std::cout;
    using std::endl;
    
    TableTennisPlayer player("Tara", "Boomdea", false);
    RatedPlayer rplayer(1140, "Mallory", "Duck", true);
    
    rplayer.Name();
    if(rplayer.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }
    
    player.Name();
    if(player.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }
    
    cout << "Name: ";
    rplayer.Name();
    cout << "; Rating: " << rplayer.Rating() << endl;
    
    RatedPlayer rplayer2(1212, player);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;
    cout << endl;
    
//    testBrass();
    
    testDMA();
}
