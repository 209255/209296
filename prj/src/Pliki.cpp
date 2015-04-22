/*!
 * \file
 * \brief
 * Definicje funkcji obslugi plikow
 *
 * Plik zawiera definicje funkcji zwiazanych z obsluga plikow.
 */

#include "../inc/Pliki.hh"

void OtworzPlikIn(const char *nazwaPliku, std::fstream &plik) {
  plik.open(nazwaPliku, std::ios::in);
  if (!plik.good()) {
    std::cerr << "Blad otwarcia pliku: " << nazwaPliku << std::endl;
    exit (-1);
  }
}

void OtworzPlikOut(const char *nazwaPliku, std::fstream &plik) {
  plik.open(nazwaPliku, std::ios::out|std::ios::trunc);
  if(!plik.good()) {
    std::cerr << "Blad utworzenia pliku: " << nazwaPliku << std::endl;
    exit(-1);
  }
}

void LosujIntDoPliku(const unsigned int n, const unsigned int zakres) {

  std::fstream plik;
  srand(time(NULL));

  plik.open("dane.dat", std::ios::out|std::ios::trunc);
  if (plik.good()) {
    for(unsigned int i=0; i<n; i++)
      plik << rand()%zakres+1 << " ";
    plik.close();
  }
  else {
    std::cerr << "Blad utworzenia pliku!" << std::endl;
    exit (-5);
  }
}
      

