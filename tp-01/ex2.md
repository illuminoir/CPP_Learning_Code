## Exercice 2 - Primitives et initialisation

En C++, il existe plein de syntaxes différentes pour initialiser une variable de type primitif (int, char, bool, etc) :
```cpp
int v;       // pas d'initialisation            -> valeur indéfinie
int v = 2;   // initialisation avec '= value'   -> value
int v {};    // initialisation avec '{}'        -> tous les bits à 0
int v { 2 }; // initialisation avec '{ value }' -> value
int v(2);    // initialisation avec '(value)'   -> value
```

1. Parmi les lignes suivantes, lesquelles déclenchent des erreurs de compilation ? Quelles sont ces erreurs et comment les corriger ?\
Mêmes questions en ajoutant l'option -Werror à la compilation.\
Vous pouvez utiliser [CompilerExplorer](https://www.godbolt.org/z/rPPoro) pour tester la compilation de petits snippets de code.

```cpp
short s0;
int   i1 = 2;
bool  b2{false};
bool  b3{i1};
bool* b4;
unsigned       u5{0x10};
unsigned short us6 = -10;
unsigned long  ul7{b3 + u5 + us6};
char c8{"a"};
char c9 = -10;
double  d10{i1};
double* d11{d10};
double& d12;
const double d13{.0f};
const int    i14 = i1;
int* i15 = &i1;
int* i16 = &b2;
int  i17 = *i15;
int& i18{i14};
const int* i19{nullptr};
const bool b20;
```

	erreur ligne 25 : passer en 'a' la corrige
	erreur ligne 28 : cannot convert double to double*
	erreur ligne 29 : d12 declared as reference but not initialized (ref sur rien)
	erreur ligne 33 : cannot convert bool* to int*
	erreur ligne 35 : binding reference on type 'int&' to 'const int' discards qualifiers
		-> reference sur un const int = illogique
	erreur ligne 37 : uninitialized 'const b20'

avec -Werror (all warnings treated as errors) :

	erreur ligne 20 : narrowing conversion of i1 from int to bool
	erreur ligne 27 : narrowing conversion of i1 from int to double


2. Pouvez-vous donner la valeur de `s0` ? De `*i15` ? De `ul7` ?

à l'aveugle : `s0 = 0`, `*i15 = i1 = 2` et `ul7 = b3 + u5 + us6 = 2 + 16 + 10 = 8` (+10 car unsigned, le signe est ignoré)

testé:
	
	`s0 = 0
	*i15 = 2
	ul7 = 65543
	us6 = 65526
	u5 = 16
	b3 = 1`

techniquement on ne peut pas donner la valeur de s0, il faut toujours initialiser un type primitif
i15 dépend de i1 donc pas de problème, ul7 dépend de vlaeurs initialisées aussi