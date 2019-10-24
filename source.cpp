//Clement Boesmier
//ce programe en ligne de commande lit un fichier "figure.txt" situer dans la racine du projet
//il dessine les figure géométrique décrite a l'interieur sous le format :
/*
nom de la forme (string)
taille (entier)
espace de marge (entier)
caratère de dessin (charactère)
remplissage(fill/none)
*/
//les formes prise en charge :
/*
carre
triangle
triangle inverse
triangle rectangle
triangle rectangle inverse
losange
*/


#include <iostream>
#include <fstream>
#include <string>


//cette petit fonction crée un espace avant la forme
// elle prend en argument le nombre d'espace a écrire et ne revoie rien
void dessinerEspace(int unEspace)
{
  for (int leJ = 0; leJ < unEspace; leJ++)
  {
    std::cout << " ";
  }
}

//fonction qui dessine des carrés
//elle prend en argument la taille du carrés le nombre d'espace le caratère de modélisation du carré
  //et si il est plein ou non
//toute les fonction dessiner prenne les même argument
void dessinerCarre(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (int leI = 0; leI < uneTaille; leI++)//boucle pour la hauteur
  {
    dessinerEspace(unEspace);//fonction d'espace
    for (int leJ = 0; leJ < uneTaille; leJ++)
    {
      if (unRempl == "fill")//condition de remplissage
      {
        std::cout << unCar;
      }
      else
      {
        if ((leJ == 0 ) || leJ == (uneTaille - 1) || leI == 0 || leI == (uneTaille -1))
        {//condition de remplissage si on touche dessine une extémité
          std::cout << unCar;
        }
        else
        {//si non on est forcément a l'interieur
          std::cout << " ";
        }
      }
    }
    std::cout << '\n';//retour a la ligne
  }
}

// fonction qui dessine un triangle rectangle
//elle prend les même argument que dessinerCarre
void dessinerTriangleRectangle(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leSommai = 1;//utilisation d'une variable sommaie incrémanter a chaque retour a la ligne
  for (int leI = 0; leI < uneTaille; leI++)
  {
    dessinerEspace(unEspace);//finction d'espace

    for (int leJ = 0; leJ < leSommai; leJ++)
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

void dessinerTriangleRectangleInv(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leSommai = uneTaille;
  for (int leI = 0; leI < uneTaille; leI++)
  {
    for (int leJ = 0; leJ < unEspace; leJ++)
    {
      std::cout << " ";
    }

    for (int leJ = 0; leJ < leSommai; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if (leJ == 0 || leJ == (leSommai - 1) || leI == 0)
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
    leSommai--;
  }
}

void dessinerTriangle(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (int leI = 0; leI < (uneTaille / 2) + (uneTaille % 2); leI++)
  {
    for (int leJ = 0; leJ < (unEspace + leI); leJ++)
    {
      std::cout << " ";
    }
    for (int leJ = 0; leJ < (uneTaille - leI*2) ; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if ((leJ == 0 ) || leJ == ((uneTaille - 1) - (leI * 2)) || leI == 0 )
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


void dessinerTriangleInverse(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (int leI = (uneTaille / 2) + (uneTaille % 2); leI > -1; leI--)
  {
    for (int leJ = 0; leJ < (unEspace + leI); leJ++)
    {
      std::cout << " ";
    }
    for (int leJ = 0; leJ < (uneTaille - leI*2) ; leJ++)
    {
      if (unRempl == "fill")
      {
        std::cout << unCar;
      }
      else
      {
        if ((leJ == 0 ) || leJ == ((uneTaille - 1) - (leI * 2)) || leI == 0 )
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

void dessinerLosange(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leTabTest[2] = {uneTaille/2, uneTaille%2};
  bool leMilieur = false;
  for (int leI = 0; leI < uneTaille; leI++) {
    for (int leJ = 0; leJ < unEspace+leTabTest[0]; leJ++) {
      std::cout << " ";
    }
    for (int leJ = 0; leJ < leTabTest[1]; leJ++) {
      if (unRempl == "fill") {
        if (leJ == 0 || leJ == leTabTest[1]-1) {
          std::cout << unCar;
        } else {
          std::cout << " ";
        }
      } else {
        std::cout << unCar;
      }
    }
    std::cout << '\n';
    if (leMilieur == false) {
      leTabTest[0] --;
      leTabTest[1] += 2;
    }
    else
    {
      leTabTest[0]++;
      leTabTest[1] -= 2;
    }
    if (leTabTest[0] == 0) {
      leMilieur = true;
    }
  }
}


int decoderForme(std::string uneForme)
{
  std::string lesFormePossible[6]={"carre","triangle rectangle","triangle rectangle inverse","triangle","triangle inverse","losange"};
  for (int leI = 0; leI < 6; leI++)
  {
    if (uneForme == lesFormePossible[leI])
    {
      return leI;
    }
  }
  return -1;
}


int main()
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

      case 2:
        dessinerTriangleRectangleInv(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 3:
        dessinerTriangle(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 4:
        dessinerTriangleInverse(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 5:
        dessinerLosange(laTaille, laDecal, leCar, leRemplissage);
      break;

      default :
      std::cout << "ERROR ! \n forme non pris en charge" << '\n';
    }
  }
  return 0;
}
