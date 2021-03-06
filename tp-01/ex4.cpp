/*
1. Ecrivez un programme qui utilise std::cin pour lire une variable de type std::string,
  puis calcule et affiche pour chaque lettre miniscule ('a', 'b', ..., 'z') le nombre 
  de fois où elle apparait.
Le comptage des lettres se fera dans une fonction count_lower prenant une chaîne de 
  caractère en paramètre et renvoyant un std::vector<unsigned int>. La première case du 
  tableau contiendra le nombre d'occurences de 'a', la seconde de 'b', etc.
Vous afficherez ce tableau dans une seconde fonction display_lower_occ.
Essayez d'utiliser les signatures qui rendront votre programme le plus efficace possible.
*/

#include <iostream>
#include <vector>
#include <cctype>

std::vector<unsigned int> count_lower(const std::string& word)
{
  std::vector<unsigned int> counts(26, 0u);
  for(const char& c : word)
  {
    if(islower(c))
    {
      int position = c - 'a';
      counts[position]++;
    }
  }

  std::vector<unsigned int> res;

  for(int i = 0 ; i < 26 ; i++){
    res.emplace_back(counts[i]);
  }

  return res;
}

void display_lower_occ(const std::vector<unsigned int>& counts){
  char c = 'a';
  for(const unsigned int& count : counts)
  {
    std::cout << c++ << " : " << count << ", ";
  }

  std::cout << std::endl;
}


int main(int argc, char const *argv[])
{
  std::string read;
  std::string concat;

  while(true)
  {
    getline(std::cin, read);
    if(read == "")
    {
      break;
    }
    concat += read;

    const auto vect = count_lower(read);
  
    display_lower_occ(vect);
  }

  std::cout << "concat : " << concat << std::endl;

  return 0;
}




/*
2. Modifiez le programme pour que l'utilisateur puisse entrer plusieurs chaînes de
  caractères, jusqu'à ce qu'il entre la chaîne vide.
Vous afficherez en plus des occurences la concaténation de toutes les chaînes de 
  caractères renseignées par l'utilisateur.

*/