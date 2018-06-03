#include "Character.h"

Character :: Character(){
    this->setChar('.');
}

Character :: Character(char c){
    this->setChar(c);
}

Character :: Character(Character& other){
    this->setChar(other.getChar());
}

Character& Character :: operator = (char s){
    this->setChar(s);
    return *this;
}

Character& Character :: operator = (Character& other){
    this->setChar(other.getChar());
    return *this;
}

bool Character::operator==(char c1) const {
    return this->getChar() == c1;
}

bool Character::operator!=(char c1) const {
    return this->getChar() != c1;
}
    
bool Character::operator==(const Character& c1) const {
    return this->getChar() == c1.getChar();
}
    
bool Character::operator!=(const Character& c1) const {
    return this->getChar() !=  c1.getChar();
}