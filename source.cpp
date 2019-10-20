#include <iostream>
#include <fstream>
#include <string>





void lireFichier(){
  std::ifstream monFichier("figure.txt");
  if (monFichier.is_open()) {
    std::string line;
    while (std::getline(monFichier, line)) {
      std::cout << line << '\n';
    }
    monFichier.close();
  }
  else {
    std::cerr << "Unable to open file\n";
  }
}

int main()
{
  lireFichier();
  std::cout << "Hello Word !!!" << '\n';
  return 0;
}
