#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        std::cerr << "no argument provided" << std::endl;
        return 1;
    }
    
    std::cout << argv[1] << std::endl;

    int length = std::stoi(argv[1]);
    
    std::vector<int> array;

    for(int i = 0 ; i < length ; i++)
    {
        array.emplace_back(i+1);
    }

    for (int value : array)
    {
        std::cout << value << std::endl;
    }

    return 0;
    
}
