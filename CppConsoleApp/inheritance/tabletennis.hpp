//
//  tabletennis.hpp
//  CppConsoleApp
//
//  Created by 贾捷飞 on 2022/9/4.
//

#ifndef tabletennis_hpp
#define tabletennis_hpp

#include <stdio.h>
#include <string>
using std::string;

//知识点：继承

class TableTennisPlayer {
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};


class RatedPlayer : public TableTennisPlayer {
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() const { return rating; }
    void ResetRating(unsigned int r) { rating = r; }
};

void testInheritance();

#endif /* tabletennis_hpp */
