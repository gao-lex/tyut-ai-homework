//
// Created by gaolex on 18-4-19.
//

#ifndef AI_HOMEWORK_HEURISTICSEARCH_H
#define AI_HOMEWORK_HEURISTICSEARCH_H

#include <string>
#include <vector>


class position{
public:
    position(){};
    bool operator==(position p){return p.x==x&&p.y==y;}
    position(int i,int j):x{i},y{j}{}
    int x,y;
};

class myMap{
public:
    int evalutionFunction(int ,int);
    void init(std::string);
    int length,width;
    position posCurrent,posStart,posEnd;
    std::vector<std::string> m;
    int findPath();
};



#endif //AI_HOMEWORK_HEURISTICSEARCH_H
