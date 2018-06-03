#pragma once

#include <iostream>
#include <sstream>
#include "Exceptions.h"
using namespace std;



class Character{
private:
    char sign;
    
public:
    Character();
    Character(char);
    Character(Character&);

    Character& operator= (char);
    Character& operator= (Character&);
    //friend istream& operator>>(istream&, Character&);
    friend ostream& operator<<(ostream&, Character&);
    bool operator==(char) const;
    bool operator!=(char) const;
    bool operator==(const Character&) const;
    bool operator!=(const Character&) const;
        
    void setChar(char c){
        if (c != 'X' && c != 'O' && c != '.'){
            IllegalCharException charException;
            charException.set_t(c);
            throw charException;
        }
        else{
            this->sign = c;
        }
    }
        
    char getChar() const{
        return this->sign;
    }
        
};

/*inline istream& operator>>(istream& in, Character& c){
    in >> c.sign;
    return in;
}*/
inline ostream& operator<<(ostream& os, Character& c){
	os << c.getChar() << endl;
    return os;
}
