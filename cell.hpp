#ifndef cell_hpp
#define cell_hpp

#include <stdio.h>
#include "ofMain.h"

class Cell{
public:
    float x, y;
    int state;
    float gridSize;
    
    Cell();
    Cell(float x, float y, float gridSize=10);
    
    void update(int lightOn);
    void draw();
    int getState();
    
};

#endif /* cell_hpp */
