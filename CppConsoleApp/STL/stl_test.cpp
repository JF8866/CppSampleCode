//
//  stl_test.cpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/11.
//

#include "stl_test.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <array>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>
#include <valarray>
#include "functor_test.hpp"

// 序列容器
// vector 可参考 vector/vector_test.cpp
// deque 双端队列（double-ended queue）
// list 双向链表
// forward_list 单向链表
// queue
// priority_queue
// stack
// array


// 关联容器（associative container）即 Java 中的 Map，大家常说的字典
//有序关联容器
// set 元素不可重复
// multiset 元素可重复
// map 每个键对应一个值
// multimap 一个键可以关联多个值且有序
//无序关联容器
// unordered_set
// unordered_multiset
// unordered_map
// unordered_multimap

void outint(int n) {
    std::cout << n << " ";
}

void show_int_list(std::list<int> & ls) {
    std::for_each(ls.begin(), ls.end(), outint);
    std::cout << std::endl;
}

bool is_even(const int & i) {
    return i % 2 == 0;
}

void listf() {
    using namespace std;
    
    list<int> one(5, 2);//创建一个包含5个2的链表
    int stuff[5] = {1,2,4,8,6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6,4,2,4,6,5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);
    
    cout << "List one: ";
    show_int_list(one);
    
    cout << "\nList two: ";
    show_int_list(two);
    
    cout << "\nList three: ";
    show_int_list(three);
    
    //删除值为2的元素
    three.remove(2);
    //删除偶数
    //three.remove_if(is_even);
    cout << "\nList three minus 2s: ";
    show_int_list(three);
    
    //拼接，这里是把 one 的所有元素拼接到 three 前面，one 本身变为空链表
    three.splice(three.begin(), one);
    cout << "\nList three after splice: ";
    show_int_list(three);
    
    cout << "\nList one: ";
    show_int_list(one);
    
    //去重
    three.unique();
    cout << "\nList three after unique: ";
    show_int_list(three);
    
    //unique()只能将相邻的相同值压缩为单个值，先排序再去重才是真正的去重
    three.sort();
    three.unique();
    cout << "\nList three after sort & unique: ";
    show_int_list(three);
    
    two.sort();
    three.merge(two);
    cout << "\nSorted two merged into three: ";
    show_int_list(three);
    
    cout << endl;
}


void listf2() {
    using namespace std;
    
    const int LIM = 10;
    int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    list<int> la(ar, ar + LIM);
    list<int> lb(la);
    
    cout << "Original list contents:\n";
    show_int_list(la);
    //使用 list 的 remove 方法删除值为4的元素
    la.remove(4);
    cout << "After using the remove() method:\n";
    cout << "la:\t";
    show_int_list(la);
    
    list<int>::iterator last;
    //使用STL 提供的 remove 函数删除值为4的元素
    /* 由于该 remove() 函数不是成员，因此不能调整链表的长度。它将没被删除的元素放在链表的开始位置，
     并返回一个指向新的超尾值的迭代器。这样，便可以用该迭代器来修改容器的长度。例如，可以使用链表的
     erase()方法来删除一个区间，该区间描述了链表中不再需要的部分。 */
    last = remove(lb.begin(), lb.end(), 4);
    cout << "After using the remove() function:\n";
    cout << "lb:\t";
    show_int_list(lb);
    
    lb.erase(last, lb.end());
    cout << "After using the erase() method:\n";
    cout << "lb:\t";
    show_int_list(lb);
}

void setf() {
    using namespace std;
    
    const int N = 6;
    string s1[N]  = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};
    
    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);
    
    //用于输出的迭代器
    ostream_iterator<string, char> out(cout, " ");
    
    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    
    cout << "\nSet B: ";
    copy(B.begin(), B.end(), out);
    
    //并集
    cout << "\nUnion of A and B: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    
    //交集
    cout << "\nIntersection of A and B: ";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    
    //差集: A 减去 A B 的交集
    cout << "\nDifference of A and B: ";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    
    //将 A B 的并集存储到集合 C
    set<string> C;
    cout << "\nSet C: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    copy(C.begin(), C.end(), out);
    
    string s3("grungy");
    C.insert(s3);
    cout << "\nSet C after insertion: ";
    copy(C.begin(), C.end(), out);
    
    cout << "\nShowing a range: ";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    
    cout << endl;
}


void multimapf() {
    using namespace std;
    
    multimap<int, string> codes;
    codes.insert(pair<const int, string>(415, "San Francisco"));
    codes.insert(pair<const int, string>(510, "Oakland"));
    codes.insert(pair<const int, string>(718, "Brooklyn"));
    codes.insert(pair<const int, string>(718, "Staten Island"));
    codes.insert(pair<const int, string>(415, "San Rafael"));
    codes.insert(pair<const int, string>(510, "Berkeley"));
    
    cout << "Number of cities with area code 415: " << codes.count(415) << endl;
    cout << "Number of cities with area code 510: " << codes.count(510) << endl;
    cout << "Number of cities with area code 718: " << codes.count(718) << endl;
    cout << "Area Code City\n";
    
    multimap<int, string>::iterator it;
    for (it = codes.begin(); it != codes.end(); it++) {
        cout << "    " << (*it).first << "    " << (*it).second << endl;
    }
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> range = codes.equal_range(718);
    cout << "Cities with area code 718:\n";
    for (it = range.first; it != range.second; it++) {
        cout << (*it).second << endl;
    }
}


void testSTL() {
//    listf();
//    setf();
//    multimapf();
    testFunctor();
//    listf2();
}
