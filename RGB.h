#ifndef TTTTASK_MASTER_RGB_H
#define TTTTASK_MASTER_RGB_H

#include <iostream>

struct RGB {
    uint8_t red, green, blue;
public:
    RGB() {}
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

#endif //TTTTASK_MASTER_RGB_H