## Exercice 3 - Les fonctions et leurs paramètres

1. Remplacez les `XX` par les bons types, de manière à ce que le programme compile et affiche `42`.

```cpp
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
```