#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>


#include "Exceptions.h" 
#include "Coordinate.h"
#include "Character.h"
#include "RGB.h"

using namespace std;

class Board{
    int boardSize;
  
  public:
    Character** mat;
    
    Board();
    Board(Board&);//copy c'tor
    Board (int);
    ~Board();
    void create(int size);
    void del();
    void init();
    void Initialize(int size);

    int size() const;
    string draw(int pixel);

    
    friend istream& operator>>(istream& in, Board& board);
    friend ostream& operator<<(ostream&, const Board&);

    Character& operator[](Coordinate);
    Character operator[](Coordinate) const;
    Board& operator=(const Board&);
    Board& operator=(char);
    friend bool operator== (Board const& x, Board const& y);
    friend bool operator!= (Board const& x, Board const& y);
    
};

inline ostream&  operator<<(ostream& out,const Board& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            out << board.mat[i][j].getChar();
        }
        out<<endl;
    }
    return out;
}
