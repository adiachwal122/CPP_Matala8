#include "Coordinate.h" 

Coordinate :: Coordinate(){
    this->row = 0;
    this->column = 0;
}

Coordinate :: Coordinate(int row, int column){
    this->setRow(row);
    this->setColumn(column);
}