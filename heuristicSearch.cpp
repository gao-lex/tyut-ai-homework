//
// Created by gaolex on 18-4-20.
//

#include "heuristicSearch.h"
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
int myMap::evalutionFunction(int x,int y){
    return  pow(posEnd.x-(posCurrent.x+x),2)+pow(posEnd.y-(posCurrent.y+y),2);
}

void myMap::init(std::string filename){
    std::ifstream istrm;
    istrm.open(filename,std::ios::in);
    istrm>>length>>width;
    istrm.get();
    for(int w=0;w<width;w++)
    {
        std::string st;
        getline(istrm,st);
        auto posS = st.find('s');
        if(posS!=st.npos){
            posStart.x = w;
            posStart.y = posS;
        }
        auto posE = st.find('e');
        if(posE!=st.npos){
            posEnd.x = w;
            posEnd.y = posE;
        }

        m.push_back(st);
    }
    posCurrent = posStart;

}

int myMap::findPath() {
    if(posCurrent==posEnd)
        return 0;
    std::vector<int> value{};
    int upDown[]{-1,1,0,0};
    int leftRight[]{0,0,-1,1};
    for(int i=0;i<4;i++)
    {
        int nx = posCurrent.x+upDown[i],ny = posCurrent.y+leftRight[i];
        if(nx>=0&&nx<length&&ny>=0&&ny<width&&m[nx][ny]!='*'&&m[nx][ny]!='p')
            value.push_back(evalutionFunction(upDown[i],leftRight[i]));
        else
            value.push_back(std::numeric_limits<int>::max());
    }

    std::vector<int>::iterator p = std::min_element(value.begin(),value.end());
    auto d = std::distance(value.begin(),p);
    posCurrent.x +=upDown[d];
    posCurrent.y +=leftRight[d];
    if(m[posCurrent.x][posCurrent.y]!='e')
        m[posCurrent.x][posCurrent.y] = 'p';
    findPath();
}
