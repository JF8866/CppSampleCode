//
//  queue.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/3.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
#include "customer.hpp"

typedef Customer Item;


class Queue {
private:
    //定义一个类中嵌套的结构体
    struct Node {
        Item item;
        struct Node * next;
    };
    enum {Q_SIZE = 10};
    Node * front;//队首
    Node * rear;//队尾
    int itemCount;
    const int qsize;//队列容量
    //私有化复制构造函数、赋值成员函数以达到禁用相关功能的目的
    //禁止通过默认的复制构造函数使用另一个对象初始化一个新的对象
    Queue(const Queue & q) : qsize(0){}
    //禁止将一个已有的对象赋值给另一个对象
    Queue & operator=(const Queue & q) {
        return *this;
    }
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};

#endif /* queue_hpp */
