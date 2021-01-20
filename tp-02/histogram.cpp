

#include "histogram.h"
#include <vector>
#include <cctype>

using namespace std;

Histogram::Histogram() 
{
  cout << "constructeur defaut" << this << endl;

  this->_count = new unsigned int[26];
}

Histogram::Histogram(const Histogram& other)
{
  cout << "constructeur copie" << this << endl;

  this->_count = new unsigned[26]{};

  for(int i = 0 ; i < 26 ; ++i)
  {
    this->_count[i] = other._count[i];
  }
}

Histogram::~Histogram()
{
  cout << "destructeur " << this << endl;

  delete[] this->_count;
}

Histogram& Histogram::operator=(const Histogram& other)
{
  this->_count = other._count;

  return *this;
}

void Histogram::analyze(const std::string& word)
{
  std::vector<unsigned int> counts(26, 0u);
  for(const char& c : word)
  {
    if(islower(c))
    {
      int position = c - 'a';
      (this->_count[position])++;
    }
  }


}

void Histogram::print() const{
  char c = 'a';

  for(int i = 0 ; i < 26 ; i++)
  {
    std::cout << c++ << " : " << this->_count[i] << ", ";
  }

  std::cout << std::endl;
}


int main(int argc, char const *argv[])
{
  std::string read;
  std::string concat;

  Histogram h1, h2;
  Histogram h3{Histogram{h1}};

  while(true)
  {
    getline(std::cin, read);
    if(read == "")
    {
      break;
    }
    concat += read;
    
    h1.analyze(read);
  
    h1.print();
  }

  std::cout << "concat : " << concat << std::endl;

  return 0;
}


/*
  l'ordre d'evaluation de chaque constructeur est comme une pile :
  on empile chaque construction
  on depile chaque construction
*/

/* 3.
  
*/