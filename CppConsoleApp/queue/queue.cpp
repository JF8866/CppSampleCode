//
//  queue.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/3.
//

#include "queue.hpp"

//cont 成员 qsize 类似 Java 中的 final 成员，但是不能在构造函数的函数体中进行初始化
//成员初始化列表只能用于构造函数，非静态const成员和引用成员只能通过该方式进行初始化
Queue::Queue(int qs) : qsize(qs) {
    front = rear = nullptr;
    itemCount = 0;
}


bool Queue::isempty() const {
    return itemCount == 0;
}

bool Queue::isfull() const {
    return itemCount == qsize;
}

int Queue::queuecount() const {
    return itemCount;
}

bool Queue::enqueue(const Item &item) {
    if(isfull()) return false;
    
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    itemCount++;
    if(front == nullptr) front = add;
    else rear->next = add;
    rear = add;
    return true;
}

bool Queue::dequeue(Item &item) {
    if(isempty()) return false;
    
    item = front->item;
    itemCount--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if(itemCount == 0) {
        rear = nullptr;
    }
    return true;
}

Queue::~Queue() {
    Node * temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
}
