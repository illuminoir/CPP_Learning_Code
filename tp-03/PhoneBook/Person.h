#pragma once

#include "PhoneNumber.h"

#include<iostream>
#include<string>
#include<tuple>

class Person {
    public:
        void set_phone_number(const PhoneNumber& number);
        const PhoneNumber& get_phone_number() const;
        std::string get_full_name() const;
        std::string get_last_name() const;
        Person(std::string first, std::string last) :
            _firstName { first },
            _lastName { last },
            _number { PhoneNumber {-1,-1,-1,-1,-1} }
        {}

        Person(const std::string& first, const std::string& last, PhoneNumber number) :
            _firstName { first },
            _lastName { last },
            _number { number }
        {}

        bool operator<(const Person& other) const; 
        bool operator>(const Person& other) const; 
        bool operator<=(const Person& other) const; 
        bool operator>=(const Person& other) const; 
        bool operator==(const Person& other) const;

        bool operator==(const std::string& other) const; 


    private:
        std::string _firstName;
        std::string _lastName;
        PhoneNumber _number;

};