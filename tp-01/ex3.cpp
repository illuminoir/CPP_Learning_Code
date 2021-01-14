// 1. Remplacez les XX par les bons types, de manière à ce que le programme
// compile et affiche 42.

#include <iostream>
#include <vector>

int add(int a, const int b) {
  return a + b;
}

void add_to(int& a, int b) {
  a += b;
}

void another_add_to(int* a, int b) {
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

/*
Par valeur si pas besoin de modifier le paramètre et pas trop couteuse
Par référence si paramètre de fonction qui va être modifié
Référence constante = paramètre coûteux que l'on veut pas modifier
*/

// 3. Modifiez les signatures des fonctions suivantes de manière à ce que le passage 
//de paramètres soit le plus efficace et sécurisé possible.

int         count_a_occurences(std::string& s);
void        update_loop(const float& dt, std::string errors_out);
bool        are_all_positives(const std::vector<int>& values, int& negative_indices_out, size_t& negative_count_out);
std::string concatenate(const std::string& str1, const std::string& str2);
