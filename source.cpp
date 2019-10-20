#include <iostream>
#include <fstream>
#include <string>





void lireFichier()
{
  std::ifstream monFichier("figure.txt");
  std::string laForme, leRemplissage;
  int laTaille, laDecal;
  char leCar;
  while (not monFichier.eof())
  {
    getline(monFichier, laForme);
    monFichier >> laTaille;
    monFichier.ignore();

    monFichier >> laDecal;
    monFichier.ignore();

    monFichier >> leCar;
    monFichier.ignore();

    getline(monFichier, leRemplissage);

    std::cout << "leCar : " << leCar << '\n';
    std::cout << "laForme : " << laForme << '\n';
  }
}

int main()
{
  lireFichier();
  std::cout << "Hello Word !!!" << '\n';
  return 0;
}
