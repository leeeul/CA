#ifndef ca_hpp
#define ca_hpp

#include <stdio.h>
#include <ofMain.h>
#include "cell.hpp"

class Ca{
public:
    float gridSize = 10;
    int xIndex;
    int yIndex;
    vector<vector<Cell>> list;
    bool still=false;
    
    int generation=1; //1~64 -> 0~63
    
    int ruleNum; //0~255
    int ruleSet[8];
    
    Ca(float gridSize=10);
    
    void setRule(int i);
    void update();
    void draw();
    
    int findNeigh(int x, int y);
    void stillMode(bool still);
};

#endif
