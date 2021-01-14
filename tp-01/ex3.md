## Exercice 3 - Les fonctions et leurs paramètres

1. Remplacez les `XX` par les bons types, de manière à ce que le programme compile et affiche `42`.

```cpp
#include <iostream>

int add(const int a, const int b) {
  return a + b;
}

void add_to(int& a, const int b) {
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
```

2. En C++, vous pouvez passer vos paramètres par valeur, par référence et par référence constante.
Quelles sont les différences entre ces différentes méthodes de passage ?
Dans quels contextes est-il préférable de passer par valeur ? Par référence ? Et par référence constante ?

	Référence = une variable qui va référencer la même zone mémoire : comme un
		pointeur mais sans les déréférencements, adresses, nullptr, etc...
	Par valeur si pas besoin de modifier le paramètre et pas trop couteuse
	Par référence si paramètre de fonction qui va être modifié
	Référence constante = paramètre coûteux que l'on veut pas modifier

	thought process : 
	est-ce que modification du paramètre? si oui : référence, si non : valeur ou réf constante.
	si type = primitif ou petit objet -> valeur
	si gros truc -> réf. constante



3. Modifiez les signatures des fonctions suivantes de manière à ce que le passage de paramètres soit le plus efficace et sécurisé possible.
```cpp
int         count_a_occurences(std::string s);
void        update_loop(const float& dt, std::string* errors_out);
bool        are_all_positives(std::vector<int> values, int* negative_indices_out, size_t* negative_count_out);
std::string concatenate(char* str1, char* str2);
```

```cpp
unsigned int         count_a_occurences(const std::string& s);
void        update_loop(const float dt, std::string& errors_out);
bool        are_all_positives(const std::vector<int>& values, int& negative_indices_out, size_t& negative_count_out);
std::string concatenate(const std::string& str1, const std::string& str2);
```


avec pointeurs, possibilité de null (nullptr)
si on s'attend pas à null on utilise un autre type
