#include <iostream>
#include <string>

using namespace std;

// Implement the program here.
int main(){
    /*
    int number;
    do 
    {
        std::cin >> number;
        std::cout << "wowie " << number << "!" << std::endl;
    } 
    while(number != -1);
    */

   for(auto i = 0 ; i < 10 ; i++){
       string word;
       cin >> word;
       cout << "wowie " << word << "!" << endl;
   }
}