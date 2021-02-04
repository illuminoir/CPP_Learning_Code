#include "Person.h"


void Person::set_phone_number(const PhoneNumber& number)
{
    this->_number = number;
}

const PhoneNumber& Person::get_phone_number() const
{
    return _number;
}

std::string Person::get_full_name() const{
    return _firstName + " "  + _lastName;
}

std::string Person::get_last_name() const{
    return _lastName;
}

bool Person::operator<(const Person& other) const 
{
    return std::tie(this->_lastName, this->_firstName) < std::tie(other._lastName, other._firstName);
}

bool Person::operator>(const Person& other) const 
{
    return std::tie(this->_lastName, this->_firstName) > std::tie(other._lastName, other._firstName);
}
bool Person::operator<=(const Person& other) const 
{
    return std::tie(this->_lastName, this->_firstName) <= std::tie(other._lastName, other._firstName);
}
bool Person::operator>=(const Person& other) const 
{
    return std::tie(this->_lastName, this->_firstName) >= std::tie(other._lastName, other._firstName);
}
bool Person::operator==(const Person& other) const 
{
    return std::tie(this->_lastName, this->_firstName) == std::tie(other._lastName, other._firstName);
}

bool Person::operator==(const std::string& other) const
{
    return this->_lastName == other;
}
