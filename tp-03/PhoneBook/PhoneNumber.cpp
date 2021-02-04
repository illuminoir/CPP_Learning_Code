#include "PhoneNumber.h"

bool PhoneNumber::is_valid() const
{
    for(auto doubleDigits : _digits)
    {
        if(doubleDigits < 0 || doubleDigits > 99)
        {
            return false;
        }
    }

    return true;
}


std::stringstream& PhoneNumber::operator<<(std::stringstream& stream)
{
    stream << std::hex << this->_digits[0] << " "
    << this->_digits[1] << " " << this->_digits[2] << " " << this->_digits[3]
    << " " << this->_digits[4] << " " << this->_digits[5];

    return stream;
}