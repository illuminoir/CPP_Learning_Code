#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <iomanip>

class PhoneNumber {
  public:
    bool is_valid() const;
    PhoneNumber(int a, int b, int c,
        int d, int e) :
        _digits { std::array<int, 5>{a,b,c,d,e} }
    {}

  std::stringstream& operator<<(std::stringstream& stream);

  private:
    std::array<int, 5> _digits;
};