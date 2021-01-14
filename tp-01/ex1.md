# TP1 - Introduction au C++


## Exercice 1 - Compilation et exécution

1. Quels sont les avantages et désavantages d'un langage dit "compilé" (C, C++, Pascal) ou "semi-compilé" (Java) comparé à un langage dit "interpreté" (Python, PHP, Javascript, etc) ?

	L'avantage premier est au niveau des performances, il n'est pas néecessaire de passer par un interpréteur à chaque exécution avec un langage compilé ce qui est généralement bien plus rapide.

2. Quelle est la différence entre une erreur de compilation et une erreur d'exécution ? (à quel moment se produisent-elles, dans quelles circonstances, comment les identifier, comment les corriger, ...)

Les erreurs de compilation sont généralement syntaxique ou des erreurs de typage, les erreurs d'exécution sont généralement sur des choses calculées à l'exécution, par exemple les types paramétrés en Java, des valeurs null.

	Pour identifier les erreurs de compilation, les grands IDE existent - pour les erreurs d'exécution : afficher le contenu des variables, vérifier leur valeur en entrée de fonction, etc.

3. Que signifie en pratique l'expression "undefined behavior" (UB) ? Peut-on compiler un programme contenant du code classifié UB par le standard ? Si oui, que peut-il se produire au moment de son exécution ?

un code qui compile mais sans garantie au niveau de ce que ça fait à l'exécution
