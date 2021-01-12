// 1. Remplacez les XX par les bons types, de manière à ce que le programme
// compile et affiche 42.

#include <iostream>

XX add(XX a, XX b) {
  return a + b;
}

XX add_to(XX a, XX b) {
  a += b;
}

XX another_add_to(XX a, XX b) {
  *a += b;
}

int main() {
  const int x{10};
  int y = add(x, x);
  another_add_to(&y, y);
  add_to(y, 2);
  std::cout << y << std::endl;
  
  return 0;
}

/*
2. En C++, vous pouvez passer vos paramètres par valeur, par référence et par 
  référence constante. 
Quelles sont les différences entre ces différentes méthodes 
  de passage ? Dans quels contextes est-il préférable de passer par valeur ? 
Par référence ? Et par référence constante ?
*/

// 3. Modifiez les signatures des fonctions suivantes de manière à ce que le passage 
//de paramètres soit le plus efficace et sécurisé possible.

int         count_a_occurences(std::string s);
void        update_loop(const float& dt, std::string* errors_out);
bool        are_all_positives(std::vector<int> values, int* negative_indices_out, size_t* negative_count_out);
std::string concatenate(char* str1, char* str2);
