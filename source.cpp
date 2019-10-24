//Clement Boesmier
//ce programme en ligne de commande lit un fichier "figure.txt" situer dans la racine du projet
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

    for (int leJ = 0; leJ < leSommai; leJ++)//boucle de hauteur
    {
      if (unRempl == "fill")//condition de remplissage
      {
        std::cout << unCar;
      }
      else
      {
        if (leJ == 0 || leJ == (leSommai - 1) || leI == (uneTaille - 1))//condition de contour
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
    leSommai++;//incrépent du sommaie pour arrivé a la base
  }
}

// fonction qui dessine un triangle rectangle inverser
//elle prend les même argument que dessinerCarre
void dessinerTriangleRectangleInv(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leSommai = uneTaille;//variable pour le sommai
  for (int leI = 0; leI < uneTaille; leI++)//boucle de hauteur
  {
    dessinerEspace(unEspace);//fonction d'espace
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
    std::cout <<'\n';//retour a la ligne
    leSommai--;//décrémentation du sommai
  }
}

// fonction qui dessine un triangle
//elle prend les même argument que dessinerCarre
void dessinerTriangle(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (int leI = 0; leI < (uneTaille / 2) + (uneTaille % 2); leI++)//boucle de hauteur avec condition pour trouvée la hauteur max
  {
    dessinerEspace(unEspace + leI);//fonction d'espace avec imcrément de l'espace
    for (int leJ = 0; leJ < (uneTaille - leI*2) ; leJ++)//boucle de ligne utilisation du leI pour avoir la pointe du triangle
    {
      if (unRempl == "fill")//condition remplissage
      {
        std::cout << unCar;
      }
      else
      {
        if ((leJ == 0 ) || leJ == ((uneTaille - 1) - (leI * 2)) || leI == 0 )//condition contour
        {
          std::cout << unCar;
        }
        else
        {
          std::cout << " ";
        }
      }
    }
    std::cout << '\n';//retour a la ligne
  }
}

// fonction qui dessine un triangle inverser
//elle prend les même argument que dessinerCarre
//fonctionne comme dessinerTriangle mais en décrémentation
void dessinerTriangleInv(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  for (int leI = (uneTaille / 2) + (uneTaille % 2); leI > -1; leI--)//
  {
    dessinerEspace(unEspace + leI);
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

// fonction qui dessine un losange
//elle prend les même argument que dessinerCarre
void dessinerLosange(int uneTaille, int unEspace, char unCar, std::string unRempl)
{
  int leTabTest[2] = {uneTaille/2, uneTaille%2};//petit tableau (pas obligatoire) pour savoir ou j'en suis dans le dessin de mon losange
  bool leMilieur = false;//variable conditionnel pour savoire quand on est au milieur du losange
  for (int leI = 0; leI < uneTaille; leI++) {//boucle pour la hauteur
    dessinerEspace(unEspace+leTabTest[0]);//fonction pour les espace
    for (int leJ = 0; leJ < leTabTest[1]; leJ++) {//fonction pour les lignes
      if (unRempl == "fill") {//contition pour le remplissage
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
    if (leMilieur == false) {//condition d'incrément /décrément pour les pointes
      leTabTest[0] --;//décrément de l'espace
      leTabTest[1] += 2;//incément du nombre de caratère
    }
    else
    {
      leTabTest[0]++;//incrément de l'espace
      leTabTest[1] -= 2;//décrément du nombre de caratère
    }
    if (leTabTest[0] == 0) {//détéction du milieu
      leMilieur = true;//milieur passer passe donc a true
    }
  }
}

//petite fonction qui renvoie le numéro de la forma a faire
int decoderForme(std::string uneForme)
{
  std::string lesFormePossible[6]={"carre","triangle rectangle","triangle rectangle inverse","triangle","triangle inverse","losange"};
  //tableau avec toutes les forme disponible
  for (int leI = 0; leI < 6; leI++)
  {
    if (uneForme == lesFormePossible[leI])
    {
      return leI;
    }
  }
  return -1;//si aucune forme ne corespond a la valeur entrée
}


int main()
{
  std::ifstream monFichier("figure.txt");//ouverture du fichier
  std::string laForme, leRemplissage;
  int laTaille, laDecal;
  char leCar;
  while (not monFichier.eof())//lecture du fichier
  {
    getline(monFichier, laForme);
    monFichier >> laTaille;
    monFichier.ignore();

    monFichier >> laDecal;
    monFichier.ignore();

    monFichier >> leCar;
    monFichier.ignore();

    getline(monFichier, leRemplissage);

    switch (decoderForme(laForme)) {//utilisation de la fonction decoderForme pour savoir a quel forme on a faire
    //petit switch pour sélection la bonne fonction suivant la forme voulu.
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
        dessinerTriangleInv(laTaille, laDecal, leCar, leRemplissage);
      break;

      case 5:
        dessinerLosange(laTaille, laDecal, leCar, leRemplissage);
      break;

      default :
      std::cout << "ERREUR ! \n forme non pris en charge" << '\n';//retoure d'érreur si forme non reconus
    }//PS : le retourne a la ligne de fin de fichier et reconnus comme une forme inconu d'ou l'erreur en fin de programme
  }
  monFichier.close();//fermeture du fichier
  return 0;//fin de programme
}
