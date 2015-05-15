a#include"StrukturyBenchmark.hh"
#include "Wyniki.hh"
#include "HSort.hh"
#include "HybSort.hh"
#include "ListArr2x.hh"
#include "MSort.hh"
#include "QSort.hh"
#include "QSortOpt.hh"
#include "StosTab.hh"
#define ILOSC_POW 10
#define ILOSC_PROB 5
unsigned int Tablica_Rozmiarow[] = {100,1000,10000,100000,1000000};
using namespace std;

/*!
 *\file
 *\brief funkcja glowna programu
 */

int main()
{
  QSort<int> *k = new QSort<int>;
  // HSort<int> *h = new HSort<int>;
  //MSort<int> *M = new MSort<int>;
  //QSortOpt<int> *O = new QSortOpt<int>;
  //StosTab<int> *s = new StosTab<int>;
  //HybSort<int> *q = new HybSort<int>;
  //ListArr2x<int> *l= new ListArr2x<int>;
  StosTab<int> *p = new StosTab<int>;
  Wyniki *W = new Wyniki(ILOSC_POW,ILOSC_PROB,Tablica_Rozmiarow);
  StrukturyBenchmark<int> *S = new StrukturyBenchmark<int>(ILOSC_PROB,ILOSC_POW,Tablica_Rozmiarow);
  
  S -> _DodajObserwator(W);
  // S -> _Generator();
  S -> _Wczytaj("Dane.dat");
  cout <<"test" <<endl;
  S -> _Ustaw(k,p,p);
  S -> _WykonajTest();
  W -> _ZapiszWyniki("Wyniki.dat");
  S -> _UsunObserwator(W);
 
  return 0;
}
