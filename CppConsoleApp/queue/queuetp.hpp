//
//  queuetp.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/10.
//

#ifndef queuetp_hpp
#define queuetp_hpp

#include <stdio.h>

template<typename Item>
class QueueTP {
private:
    enum {Q_SIZE = 10};
    //嵌套类
    class Node {
    public:
        Item item;
        Node * next;
        Node(const Item & i) : item(i), next(0) {}
    };
    Node * front;
    Node * rear;
    int itemCount;
    const int qsize;
    QueueTP(const QueueTP & q) : qsize(0) {}
    QueueTP & operator=(const QueueTP & q) {
        return *this;
    }
public:
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();
    bool isempty() const {
        return itemCount == 0;
    }
    bool isfull() const {
        return itemCount == qsize;
    }
    int queuecount() const {
        return itemCount;
    }
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};


template<typename Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs) {
    front = rear = 0;
    itemCount = 0;
}

template<typename Item>
QueueTP<Item>::~QueueTP() {
    Node * temp;
    while (front != 0) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<typename Item>
bool QueueTP<Item>::enqueue(const Item & item) {
    if(isfull()) return false;
    Node * add = new Node(item);
    if(front == 0)
        front = add;
    else
        rear->next = add;
    rear = add;
    itemCount++;
    return true;
}

template<typename Item>
bool QueueTP<Item>::dequeue(Item &item) {
    if(front == 0) return false;
    item = front->item;
    Node * temp = front;
    front = front->next;
    delete temp;
    itemCount--;
    if(itemCount == 0) rear = 0;
    return true;
}

void testQueueTP();

#endif /* queuetp_hpp */
