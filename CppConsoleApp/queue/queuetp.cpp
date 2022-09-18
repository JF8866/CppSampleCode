//
//  queuetp.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#include "queuetp.hpp"
#include <iostream>
#include <string>

void testQueueTP() {
    using std::string;
    using std::cin;
    using std::cout;
    
    QueueTP<string> cs(5);
    string temp;
    while (!cs.isfull()) {
        cout << "Please enter your name. You will be served in the order of arrival.\name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. Processing begins!\n";
    while (!cs.isempty()) {
        cs.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
}
