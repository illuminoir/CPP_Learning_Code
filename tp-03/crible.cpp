#include <vector>
#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    auto max = 100000;
    auto x = std::vector<unsigned long>();
    auto limit = std::sqrt(max);

    for(int i = 2 ; i < max ; i++){
        x.push_back(i);
    }

    //remove
    for(auto it = x.begin() + 2 ; it != x.begin() + limit ; it++){
        for(int j = i * i ; j < max ; j += i){

        }
    }

    return 0;
}
