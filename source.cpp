#include <iostream>
#include <fstream>
#include <string>

void dessinerCarre()
{

}

int decoderForme(std::string uneForme)
{
  std::string lesFormePossible[5]={"carre","triangle rectangle","triangle rectangle inverse","triangle","losange"};
  for (size_t leI = 0; leI < 5; leI++)
  {
    if (uneForme == lesFormePossible[leI])
    {
      return leI;
    }
  }
  return -1;
}


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

    std::cout << decoderForme(laForme) << '\n';
  }
}

int main()
{
  lireFichier();
  std::cout << "Hello Word !!!" << '\n';
  return 0;
}
