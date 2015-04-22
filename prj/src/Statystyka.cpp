/*!
 * \file
 * \brief
 * Zawiera definicję metod klasy Statystyka.
 *
 * Plik zawiera definicję metod klasy Statystyka.
 */

#include "../inc/Statystyka.hh"
#include <fstream>
#include <cstdlib>
#include <string>

Statystyka::Statystyka(const unsigned int iloscProb, unsigned int *proby) {
  IleProb = iloscProb;
  Proba = new unsigned int[IleProb];
  Czas = new double[IleProb];
  for(unsigned int i=0; i<IleProb; i++)
     Proba[i] = proby[i];
}

void Statystyka::ZapiszStaty(std::string nazwaPliku) {

  std::fstream plik;

  plik.open(nazwaPliku.c_str(), std::ios::out|std::ios::trunc);
  if (plik.good()) {

      for(unsigned int i=0; i<IleProb; i++)
	plik << Proba[i] << " ";
      plik << std::endl;
      for(unsigned int i=0; i<IleProb; i++)
	plik << Czas[i] << " ";

    plik.close();
  }
  else {
    std::cerr << "Blad utworzenia pliku!" << std::endl;
    exit (-4);
  }
}
