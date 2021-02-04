#include "PhoneBook.h"


bool PhoneBook::empty()
{
    return _persons.empty();
}

void PhoneBook::insert(const Person& p)
{
    for(auto it = _persons.begin() ; it != _persons.end() ; it++)
    {
        if(it->get_full_name().compare(p.get_full_name()) == 0)
        {
            _persons.erase(*it);
            break;
        }
    }

    _persons.insert(p);
}

const Person& PhoneBook::operator[](int index)
{
    auto it = _persons.begin();

    for(int i = 0 ; i < index ; i++)
    {
        it++;
    }

    return *it;
}

const Person* PhoneBook::first_of_family(const std::string& name)
{
    for(auto it = _persons.begin() ; it != _persons.end() ; it++)
    {   
        if(it->get_last_name().compare(name) == 0)
        {
            return &(*it);
        }
    }

    return nullptr;
}