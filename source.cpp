#include <iostream>
#include <fstream>
#include <string>

void dessinerCarre(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (size_t leI = 0; leI < uneTaille; leI++)
  {
    for (size_t leJ = 0; leJ < unEspace; leJ++)
    {
      std::cout << " ";
    }
    for (size_t leJ = 0; leJ < uneTaille; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if ((leJ == 0 ) || leJ == (uneTaille - 1) || leI == 0 || leI == (uneTaille -1))
        {
          std::cout << unCar;
        }
        else
        {
          std::cout << " ";
        }
      }
    }
    std::cout << '\n';
  }
}

void dessinerTriangleRectangle(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leSommai = 1;
  for (size_t leI = 0; leI < uneTaille; leI++)
  {
    for (size_t leJ = 0; leJ < unEspace; leJ++)
    {
      std::cout << " ";
    }

    for (size_t leJ = 0; leJ < leSommai; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if (leJ == 0 || leJ == (leSommai - 1) || leI == (uneTaille - 1))
        {
          std::cout << unCar;
        }
        else
        {
          std::cout << " ";
        }
      }
    }
    std::cout <<'\n';
    leSommai++;
  }
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



    switch (decoderForme(laForme)) {
      case 0:
        dessinerCarre(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 1:
        dessinerTriangleRectangle(laTaille, laDecal, leCar, leRemplissage);
      break;

      default :
      std::cout << "ERROR ! \n forme non pris en charge" << '\n';
    }
  }
}

int main()
{
  lireFichier();
  std::cout << "fin de Programme" << '\n';
  return 0;
}
