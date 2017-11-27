#include "ca.hpp"

Ca::Ca(float gridSize)
{
    xIndex = ceil(ofGetWidth()/gridSize);
    yIndex = ceil(ofGetHeight()/gridSize);
    this->gridSize = gridSize;
    
    list = vector<vector<Cell>>( yIndex, vector<Cell>(xIndex, Cell()));
    
    for(int y=0; y<yIndex; y++){
        for(int x=0; x<xIndex; x++){
            list[y][x] = Cell(x*gridSize, y*gridSize, gridSize);
        }
    }
    int mid = (list[0].size())/2;
    list[0][mid].update(1);
    cout<<list.size()<<endl;
}

void Ca::setRule(int i){
    int temp = ruleNum = i; //0~255
    
    for(int j=0; j<8; j++){
        ruleSet[j] = temp%2;
        temp/=2;
    }
}

void Ca::update(){
    
    if(!still && generation>yIndex){
        for(int y=0; y<yIndex; y++){
            if(y==yIndex-1){
                for(int x=0; x<xIndex; x++)
                    list[y][x].update(findNeigh(x, y));
            }else{
                for(int x=0; x<xIndex; x++){
                    list[y][x].state = list[y+1][x].getState();
                }
            }
        }
    }else{
        for(int y=generation-1; y<generation; y++){
            for(int x=0; x<xIndex; x++){
                list[y][x].update(findNeigh(x, y));
            }
        }
    }
    
    generation++;
    
    if(still){
        generation = ofClamp(generation, 1, yIndex);//yIndex
    }
    
    cout<<"gen : "<<generation<<endl;
    
}

void Ca::draw(){
    ofSetColor(255);
    ofSetLineWidth(1);
    //
    for(float y=0; y<yIndex; y++){
        for(float x=0; x<xIndex; x++){
            list[y][x].draw();
        }
    }
}

int Ca::findNeigh(int x, int y){
    int l;
    int m;
    int r;
    int rule;
    
    if(y==0){
        return 3; // stay still;
    }else{
        if(x==0){
            l=list[y-1][xIndex-1].getState();
            m=list[y-1][x].getState();
            r=list[y-1][x+1].getState();
        }else if(x==xIndex-1){
            l=list[y-1][x-1].getState();
            m=list[y-1][x].getState();
            r=list[y-1][0].getState();
            
        }else{
            l=list[y-1][x-1].getState();
            m=list[y-1][x].getState();
            r=list[y-1][x+1].getState();
        }
        
        rule = l*(4) + m*(2) + r*(1);
    }
    
    return ruleSet[int(rule)];
}

void Ca::stillMode(bool still){
    this->still = still;
}


