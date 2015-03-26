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
#define ILOSC_PROB 3
using namespace std;
int main(int argc, char *argv[]) 
{
  
  unsigned int iloscDanych[ILOSC_PROB] = {1, 10, 10};
  //std::string nazwaPlikuStat[3] = {"LinkLista.dat" , "ListArr1.dat", "ListArr2x.dat"};
  // Framework *I;
  // // Lista<int> *LL = new Lista<int>;
  // ListArr1<int> *LA1 = new ListArr1<int>;
  ListArr2x<int> *LA2 = new ListArr2x<int>;
  // Benchmark<int> *B = new Benchmark<int>(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);
  srand(time(NULL));
  for(unsigned int i = 0; i <iloscDanych[2] ;++i)
    {
      LA2 -> push(rand()%100,i);
    }
  cout << "\nPrzed sortowaniem" << endl;
  LA2->Pokaz();
  cout << "\nPo sortowaniu" << endl;
  LA2 -> sortuj(0,(int)LA2->size());
  LA2 -> Pokaz();
  /*
  for(int j=0; j<3; j++) { 
    switch(j) {
    case 0: I = LL; break;
    case 1: I = LA1; break;
    case 2: I = LA2; break;
    default: std::cerr << "Brak przypisania wkaznika" << std::endl;
    }
    B -> Test(I, nazwaPlikuStat[j]);
  }
  */ 
return 0;
}
