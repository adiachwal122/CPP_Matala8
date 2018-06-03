#pragma once

#include <exception>
#include <string>
using namespace std;


class IllegalCoordinateException : public exception{
    
    int first;
    int second;
    
    public:
        const char* theCoordinate() const throw ();
        void set_f(int );
        void set_s(int );
};

class IllegalCharException : public exception{
    
    char temp;
    
    public:
        const char* theChar() const throw ();
        void set_t(char);
};
