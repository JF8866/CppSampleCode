//
//  stack.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/8/28.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>


template<typename T>
class Stack {
private:
    enum {SIZE = 10};//default size
    int stacksize;
    T * items;
    int top;
    
public:
    explicit Stack(int size = SIZE);
    Stack(const Stack & st);
    ~Stack() {
        delete [] items;
    }
    bool isempty() const { return top == 0; }
    bool isfull() const { return top == stacksize; }
    bool push(const T & item);
    bool pop(T & item);
    Stack & operator=(const Stack & st);
};

//不能将模版成员函数放在单独的实现文件中，如果单独定义在实现文件，外部代码将无法使用模版函数

template<typename T>
Stack<T>::Stack(int size) : stacksize(size), top(0) {
    items = new T[stacksize];
}

template<typename T>
Stack<T>::Stack(const Stack & st) {
    stacksize = st.stacksize;
    top = st.top;
    items = new T[stacksize];
    for (int i = 0; i < stacksize; i++) {
        items[i] = st.items[i];
    }
}


template<typename T>
bool Stack<T>::push(const T & item) {
    if(isfull()) return false;
    items[top++] = item;
    return true;
}

template<typename T>
bool Stack<T>::pop(T & item) {
    if(isempty()) return false;
    item = items[--top];
    return true;
}


template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> &st) {
    if(this == &st) {
        return *this;
    }
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new T[stacksize];
    for (int i = 0; i < stacksize; i++) {
        items[i] = st.items[i];
    }
    return *this;
}

void testStack();

#endif /* stack_hpp */
