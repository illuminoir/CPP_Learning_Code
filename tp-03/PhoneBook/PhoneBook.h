#pragma once

#include <set>
#include <algorithm>
#include "Person.h"

class PhoneBook {
    public:
        bool empty();
        void insert(const Person& p);
        const Person* first_of_family(const std::string& name);

        PhoneBook() :
            _persons { }
        {}

        const Person& operator[](int index);

    private :
        std::set<Person> _persons;
};