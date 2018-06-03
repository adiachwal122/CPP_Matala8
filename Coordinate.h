#pragma once

#include <sstream>
#include <iostream>
using namespace std;

class Coordinate{

private:

    int row;
    int column;
    
public:
    Coordinate();
    Coordinate(int, int);

    void setRow(int row){ this->row = row;}
    void setColumn(int column){ this->column = column;}
    int getRow(){ return this->row;}
    int getColumn(){ return this->column;}
    
    friend ostream& operator<<(ostream&, Coordinate&);
       
};

inline ostream& operator<<(ostream& os, Coordinate& c){
	    os << "{" << c.getRow() << ", "<< c.getColumn() <<"}"<< endl;
        return os;
}
