#include "Rectangle.h"

#include <iostream>

int main()
{

    Rectangle::_default_size = 2.f;
    Rectangle s1;
    Rectangle s2;

    Rectangle::_default_size = 7.f;
    Rectangle s3;
    Rectangle s4;
    Rectangle s5;

    Rectangle rect(2.f, 4.f);
    Rectangle square(2.5f);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;
    std::cout << "{ L: " << square.get_length() << ", W: " << square.get_width() << " }" << std::endl;

    rect.scale(3);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    return 0;
}
