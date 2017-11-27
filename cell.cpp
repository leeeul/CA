#include "cell.hpp"

Cell::Cell(){
    x=0;
    y=0;
}

Cell::Cell(float x, float y, float gridSize){
    this->x = x;
    this->y = y;
    this->gridSize = gridSize;
    state = 0;
}

void Cell::update(int lightOn){
    
    switch (lightOn){
        case 0:
            state = 0;
            break;
        case 1:
            state = 1;
            break;
        default:
            break;
            
    }
}

void Cell::draw(){
    ofSetColor(0);
    
    if(getState()){
        ofFill();
        
    }else{
        ofNoFill();
    }
    ofDrawRectangle(x, y, gridSize, gridSize);
}

int Cell::getState(){
    return state;
}
