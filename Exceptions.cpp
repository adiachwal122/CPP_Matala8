#include "Exceptions.h"

const char* IllegalCoordinateException :: theCoordinate() const throw (){
    return (to_string(first) + ',' +to_string(second) + '\n').c_str();
}
void IllegalCoordinateException :: set_f(int f){ this ->first = f;}
void IllegalCoordinateException :: set_s(int s){ this ->second = s;}

const char* IllegalCharException :: theChar() const throw (){
    const char* ans =  &temp;
    return ans;
}

void IllegalCharException :: set_t(char t){ this ->temp = t;}