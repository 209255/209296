/*! 
 * \file
 * \brief
 * Moduł główny programu
 *
 *
 * Program wkonuje serię 10 pomiarów czasu wykonania metody start
 * dla różncyh wielkości problemu obliczeniowego, dla każdego
 * zaimplemetowanego typu danych - LinkLista, ListaArr1, ListaArr2x. 
 * Procedura obliczeniowa polega na utworzeniu 'objektu'
 * przechoującego n danych (stałych liczb).
 * statystykę pomiarów 
 * zapisuje do pliku o nazwie "TypDaych.dat".
 * gdzie "TypDanych" to odpowiednio Lista, ListaArr1 i ListaArr2x
 *
 * OBSŁUGA PROGRAMU:
 * Aby wywołać program należy w lini poleceń wywołać jego nazę
 *  np: "./a.out"
 */

#include "../inc/Lista.hh"
#include "../inc/Stos.hh"
#include "../inc/Kolejka.hh"
#include "../inc/ListArr1.hh"
#include "../inc/ListArr2x.hh"
#include "../inc/Statystyka.hh"
#include "../inc/Benchmark.hh"


/*!
 * \brief
 * Ilośc powtórzeń danej próby
 *
 * Ilośc powtórzeń danej próby
 */
#define ILOSC_POWTORZEN 10

/*!
 * \brief
 * Ilość prób
 * 
 * Ilość prób = ilość rozmiarów prób
 */
#define ILOSC_PROB 6
using namespace std;
int main(int argc, char *argv[]) 
{

  std::string nazwaPlikuStat[] = {"ListArr2x.txt"};
  unsigned int iloscDanych[ILOSC_PROB] = {100,1000,10000,100000,1000000,10000000};
  ListArr2x<int> *LA2 = new ListArr2x<int>;
  Benchmark<int> *B = new Benchmark<int>(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);
  Framework *I;
  // LosujIntDoPliku(10000000,100);
  I = LA2;
  B ->Test(I,nazwaPlikuStat[0]);
  
 
return 0;
}
