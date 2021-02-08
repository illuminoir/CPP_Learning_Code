# TP3 - Conteneurs de la STL

## Exercice 1 - Syntaxe et complexité

1. Indiquez dans le tableau suivant les complexités en temps de chaque opération :

https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md

| conteneur    | insertion (en tête / en fin) | suppression (en tête / en fin) | accès |
|--------------|-----------|----------|-----------|
| array        | N/A       | N/A      |  O(N)     |
| vector       | O(1)      | O(1)     |  O(1)     | (vector insertion/suppression en fin constant, linéaire en tête)
| deque        | O(1)      | O(1)     |  O(1)     |
| forward_list | O(1)      | O(1)     |  O(n)     |
| list         |  ^        |   ^      |   ^       |
| set          | O(log(n)) | O(log(n))|  O(log(n))|
| unordered_set| O(n)      | O(n)     |  O(n)     |

2. Supposons que vous avez récupéré un itérateur sur un élément d'un conteneur avec : `auto it = std::find(c.begin(), c.end(), element_to_find)`.
En fonction du type de conteneur, quelles sont les opérations succeptibles d'invalider cet itérateur ? Essayez d'être précis dans vos réponses.\
Exemple : Si `c` est un `std::vector`, alors `it` peut être invalidé en cas de suppression d'un élément précédant `it` dans le conteneur.


`std::deque`

`shrink_to_fit, clear, insert, emplace, push_front, push_back, emplace_front, emplace_back` invalide toujours l'itérateur
`erase` au début : seulement les éléments effacés
`erase` à la fin : seulement les éléments effacés  et le past-the-end iterator (`end()`)
`erase` sinon : tous les itérateurs invalidés même `end()`
`pop_front` seulement l'élément effacé
`pop_back` seulement l'élément effacé et `end()`
`resize` si la nouvelle taille < ancienne : seulement les éléments effacés et l'itérateur `end()`
`resize` si la nouvelle taille > ancienne : tous les itérateurs invalidés
`resize` sinon : aucun invalidés

`std::set et std::unordered_set`

Si c est un `std::set`, rien n'invalide l'itérateur. Si c est un `std::unordered_set` alors it peut être invalidé dans le cas de `clear`, `rehash`, `reserve` ou une assignation. Si l'une des opérations suivantes font un rehash, it est invalidé: `insert`, `emplace`, `emplace_hint`.

`std::array et std::vector`

si c'est un std::array, l'itérateur n'est jamais invalidé, mais après un appel à swap, l'itérateur pointe toujours sur le même élément du tableau, et donc changer sa valeur.

si c'est un std::vector, l'iterateur peut etre invalidé en cas de suppression d'un élément précédant l'itérateur ou si le conteneur change de taille


3. Quelle est la différence entre les fonctions `push_back` et `emplace_back` de la classe `std::vector<std::string>` ?

la différence est que emplace_back crée un objet via le constructeur et l'insère et push_back insère une copie
prof:
3- Diff push_back / emplace_back  on peut passer les paramètres de construction de T direct dans emplace_back, alors que pour push_back, il faut passer un objet de type T déjà construit 

4. Dans le code suivant, la classe `RelativePoint` modélise un point en 2D, dont la position est relative à celle d'un point d'origine.
Pourquoi est-ce que l'expression `std::vector<RelativePoint>(3)` ne compile pas, alors que `std::vector<AbsolutePoint>(3)` compile ?\
Ajoutez ce qu'il manque à la classe `RelativePoint` pour faire compiler le code précédent.

```cpp
struct AbsolutePoint {
  double x = 0.0, y = 0.0;
};

AbsolutePoint default_origin;

class RelativePoint {
  const AbsolutePoint& _origin;
  AbsolutePoint        _shift;
public:
  double get_x() const { return _origin.x + _shift.x; }
  double get_y() const { return _origin.y + _shift.y; }
};
```

manque le constructeur sans paramètres, implémenter par exemple un constructeur utilisant default et origin


5. [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)\
Remplissez un `std::vector<unsigned long>` avec les nombres allant de 2 à 100'000. Ensuite, pour chaque entier `x` tel que `x² <= 100'000`, supprimez du tableau tous les entiers divisibles par `x`, excepté `x` lui-même. Les nombres restants dans le tableau devraient correspondre à tous les nombres premiers compris entre 2 et 100'000.\
Combien y en a-t-il ? Ecrivez ce résultat dans la console.\
Copiez et modifiez votre algorithme, afin d'utiliser en place du `std::vector` une `std::deque`, un `std::set` et un `std::unordered_set`. Augmentez ensuite l'intervalle d'exécution à \[2; 1'000'000\] et testez chacune des quatre versions. Que pouvez-vous constater ?

6. Pourquoi le programme suivant ne compile pas ? Ajoutez le nécessaire à la classe `NumAndName` pour le corriger et faire en sorte qu'il affiche `zero un deux trois`.\
Modifiez-le de nouveau afin d'obtenir `trois deux un zero`.

```cpp
#include <iostream>
#include <set>
#include <string>

class NumAndName {
  const int         _number;
  const std::string _name;
  
public:
  NumAndName(int number, std::string_view name) :
    _number { number }, _name { name }
  {}
  
  friend std::ostream& operator<<(std::ostream& os, const NumAndName& n) {
    return os << n._name;
  }
};

const std::set<NumAndName> num_and_names { { 3, "trois" }, { 1, "un" }, { 2, "deux" }, { 0, "zero" } };

int main() {
  for (const auto& nn: num_and_names) {
    std::cout << nn << ' ';
  }
  
  return 0;
}
```

## Exercice 2 - Annuaire téléphonique

Vous allez implémenter un annuaire téléphonique (comme le gros bottin qui traîne sur une étagère chez vos grand-parents).

L'intérêt de l'annuaire, c'est que vous pouvez y rechercher facilement les numéros de téléphone de vos amis et ennemis, dès lors que vous connaissez leur
nom et prénom. Le bottin étant trié par ordre alphabétique, quelle est la complexité de la recherche d'une personne dedans ?
Afin d'avoir cette même complexité dans votre programme, quel conteneur pouvez-vous utiliser pour stocker les entrées de l'annuaire ? 

Vous aurez également besoin de modéliser un numéro de téléphone, qui correspond à une série de 5 nombres entiers.
Quel est le conteneur le plus adapté pour représenter cet objet ?

Une fois que vous aurez répondu aux questions ci-dessus, vous pourrez commencer à implémentez les classes modélisant la situation.

Comme on est gentils, nous vous avons défini les fonctions de tests permettant de vérifier que votre API fonctionne.
Activez ces tests l'un après l'autre, afin d'implémenter vos classes et leurs fonctionnalités au-fur-et-à-mesure, en vérifiant à chaque étape que le code que vous
ajoutez/modifiez compile et se comporte comme attendu.\
=> Regardez dans tp-03/PhoneBook/Tests.h pour activer ou désactiver un test 

Pensez bien à modifier le CMakeLists.txt du TP3 ainsi que le fichier Tests.cpp (pour les includes) dès que vous ajouter un nouveau fichier au projet.

---

Céline Noël, Stéphane Vialette, Mathias Weller  
C++ Master 1    
2020 - 2021
