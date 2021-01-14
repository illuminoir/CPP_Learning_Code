//En C++, il existe plein de syntaxes différentes pour 
//initialiser une variable de type primitif (int, char, bool, etc) :

#include <iostream>
/*
int v;       // pas d'initialisation            -> valeur indéfinie
int v = 2;   // initialisation avec '= value'   -> value
int v {};    // initialisation avec '{}'        -> tous les bits à 0
int v { 2 }; // initialisation avec '{ value }' -> value
int v(2);    // initialisation avec '(value)'   -> value
*/
int main(int argc, char const *argv[])
{


    /*
    1. Parmi les lignes suivantes, lesquelles déclenchent des erreurs de compilation ? 
    Quelles sont ces erreurs et comment les corriger ?
    Mêmes questions en ajoutant l'option -Werror à la compilation.
    Vous pouvez utiliser CompilerExplorer pour tester la compilation de petits snippets de code.
    CompilerExplorer : https://www.godbolt.org/z/rPPoro
    */

    short s0;
    int   i1 = 2;
    bool  b2{false};
    bool  b3{i1};
    bool* b4;
    unsigned       u5{0x10};
    unsigned short us6 = -10;
    unsigned long  ul7{b3 + u5 + us6};
    //char c8{"a"};
    char c9 = -10;
    //double  d10{i1};
    //double* d11{d10};
    //double& d12;
    const double d13{.0f};
    const int    i14 = i1;
    int* i15 = &i1;
    //int* i16 = &b2;
    int  i17 = *i15;
    //int& i18{i14};
    const int* i19{nullptr};
    //const bool b20;


    // 2. Pouvez-vous donner la valeur de s0 ? De *i15 ? De ul7 ?

    std::cout << "s0 = " << s0 << "\n*i15 = " << *i15 << "\nul7 = " << ul7 << std::endl;
    std::cout << us6 << std::endl;
    std::cout << u5 << std::endl;
    std::cout << b3 << std::endl;

    return 0;
}