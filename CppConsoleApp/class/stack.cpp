//
//  stack.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/28.
//

#include "stack.hpp"
#include <iostream>
#include <cctype>

//不能将模版成员函数放在单独的实现文件中，如果单独定义在实现文件，外部代码将无法使用模版函数

void testStack() {
    using namespace std;
    Stack<int> stack;
    char ch;
    int po;
    cout << "Please enter A to add a purchase ordder,\n"
          << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if(!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if(stack.isfull()) {
                    cout << "Stack already full\n";
                } else {
                    stack.push(po);
                }
                break;
                
            case 'P':
            case 'p':
                if(stack.isempty()) {
                    cout << "Stack already empty\n";
                } else {
                    stack.pop(po);
                    cout << "PO # " << po << " popped\n";
                }
                break;
                
            default:
                break;
        }
        cout << "Please enter A to add a purchase ordder,\n"
              << "P to process a PO, or Q to quit.\n";
    }
    
    //Stack<std::string> names(3);
    Stack<const char *> names(3);
    names.push("C++");
    names.push("Java");
    names.push("Kotlin");
    names.push("JavaScript");
//    string item = "";//这里初始值不能给 nullptr
    const char * item;
    while (names.pop(item)) {
        cout << item << endl;
    }
    
    
    cout << "Bye\n";
}
