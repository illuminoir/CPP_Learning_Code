#pragma once

#include "Rank.h"
#include "Employee.h"

#include <string>
#include <string_view>

class Boss : public Employee
{
public:
    Boss::Boss(std::string_view name, std::string_view surname, unsigned int salary, bool is_nice)
    : Employee { name, surname, salary, Rank::TopManagement }
    , _is_nice { is_nice }
    {}
    
    void assign_task(Staff& staff) const;
    void ask_coffee(Intern& intern) const;

private:
    bool              _is_nice;
};
