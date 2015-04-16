#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "Framework.hh"
#include <ctime>
#include "Statystyka.hh"

/*!
 * \file
 * \brief
 * Definicja klasy Benchmark
 *
 * Plik zawiera definicję klasy Benchmark wraz z definicją jej metod.
 */

/*!
 * \brief
 * Modeluje pojęcie Benchmarku
 *
 * Modeluje pojęcie Benchmarku czyli objektu mierzącego czas wykonywania
 * algoytmu
 */
template < class typ> 
class Benchmark {
/*!
 * \brief
 * Statystyki testu
 *
 * Pole przechowuje wyniki testów
 */
Statystyka *stat;

/*!
 * \brief
 * Ilość prób
 *
 * Ilość powtórzeń każdej seriii
 */
unsigned int IleProb;

/*!
 * \brief
 * Tablica liczności serii
 *
 * Tablica z licznościami elementów dla kojenych serii
 */
unsigned int *IleDanych;

/*!
 * \brief
 * Ilość powtórzeń
 *
 * Ilość powtórzeń każdej serii
 */
unsigned int IlePowtorzen;

public:

/*!
 * \brief
 * Konstruktor 2 argumentowy
 *
 * Tworzy objekt klasy Benchmark i inicjuje nową statystykę dla objektu
 *
 * \param[in] ileProb - ilość prób, które zostaną wykonane
 * \param[in] ileDanych - wkaźnik na tablice z licznościami kolejnych serii
 * \param[in] ilePowtorzen - ilość powtórzeń każdej serii
 */
 Benchmark(const unsigned int ileProb, unsigned int *ileDanych, unsigned int ilePowtorzen) {
  IleProb = ileProb;
  IleDanych = ileDanych;
  IlePowtorzen = ilePowtorzen; 
  stat = new Statystyka(IleProb, IleDanych);
}

/*!
 * \brief
 * Testowanie algorytmu
 *
 * Metoda testuje algorytm w okreslonej liczbie serii i powtórzeniach
 * pomiary zapisuje do pliku podanego pez użytkownika
 *
 * \param[in] I - objekt klasy na której zostanie przeprowadzony test
 * \param[in] nazwaPliku - nazwa pliku do którego zostaną zapisane statystyki
 */
void Test(Framework *I,std::string nazwaPliku) {
  std::clock_t poczatek, koniec;
  double suma;
  for(int j = 0; j < IleProb; ++j) {
    suma = 0;
   for(int k = 0; k < IlePowtorzen; ++k) {
      I -> WczytajDane("dane.dat",IleDanych[j]);
      // std::cout << "Przed" << std::endl;
      //I -> Pokaz();
      poczatek = std::clock();
      I -> Start();
      koniec = std::clock();
      //std::cout << "Po: " << std::endl;
      // I -> Pokaz();
      suma +=(koniec - poczatek);
      I -> Zwolnij();
    }
   (*stat)[j] = (suma/IlePowtorzen)/(double)(CLOCKS_PER_SEC/1000);
   }
 stat -> ZapiszStaty(nazwaPliku);
 }
};

#endif
