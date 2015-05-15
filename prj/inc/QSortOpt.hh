#ifndef QSORTOPT_HH
#define QSORTOPT_HH
#define ILE 3

//************************************************************** 
/*!
 *\file Sortowanie szybkie z opytymalizacja
 *
 * Plik zawiera implementacje algorymu sortowania 
 * szybkiego z optymalizjacja
 */
//************************************************************** 

//************************************************************** 
/*!
 *\brief Modeluje sortowanie szybkie z optymalizacja
 *
 * Klasa zawiera implementacje algorytmu
 * sortowania szybkiego z optymalizacja
 */
//************************************************************** 
template <class Typ>
class QSortOpt:public ISortable<Typ>
{
//**************************************************************
  /*!
   *\brief Zotymalizowane Sortowanie Szybkie
   *
   * Metoda modeluje algorytm sorotwanie szybkiego
   * z zaimplementowanym algorytmem doboru pivotu, 
   * tak aby nie zostal wybrany najmniejszy 
   * element w danym podzbiorze.
   *
   *\parma[in] lewy - poczatkowy indeks pozbioru
   *\param[in] prawy - koncowy indeks podzbioru
   */
//**************************************************************
  void QsortOpt(int lewy, int prawy1,Iterable<Typ> *K)
  {
    Typ Index[] = { K -> Wartosc(lewy), K -> Wartosc((lewy+prawy1)/2)
		    ,K -> Wartosc(prawy1)}; 
    Typ Pivot = Mediana(Index);
    int i = lewy;
    int j = prawy1;
    do
      {
	while(K -> Wartosc(i) < Pivot) i++;
	while(K -> Wartosc(j) > Pivot) j--;
	if( i <= j )
	{
	  K ->_Zamien(i,j);
	  ++i;--j;
	}
      }
    while( i <= j );
    if(j > lewy) QsortOpt(lewy,j,K);
    if(i < prawy1) QsortOpt(i,prawy1,K);
  }
//**************************************************************
/*!
 *\brief Mediana
 * Metoda wyznaczajaca mediana dla tablicy 3 elementowej.
 * Jest to metoda pomocnicza, wykorzystywana  przy optymalizacji
 * doboru pivotu w sortowaniu szybkim
 * \return Zwraca indeks na ktorym znajduje sie mediana 
 * w tablicy wejsciowej
 */
//**************************************************************
  int Mediana(Typ *W)const
  {
    if((W[0] <= W[1]) && (W[0] <= W[2])) {
      if(W[1] <= W[2])  return W[1]; 
      else return W[2];
    }
    
    if((W[1] <= W[0]) && (W[1] <= W[2])) {
      if(W[0] <= W[2])  return W[0];
      else return W[2];
    }
    return W[1];
  }
//***************************************************************

public:

//***************************************************************
/*!
 *\brief Metoda inicjalizujaca sortowanie szybkie z optymalizacja
 *
 * Metoda ma za zadanie zainicjalizowac algorytm sortowania 
 * szybkiego z optymalizacja dla wybranej struktury danych
 *
 * \param[in] Kontener - rodzaj kontenera,ktory zostanie 
 * posortowany
 */
//***************************************************************
  void _Sort(Iterable<Typ> *Kontener)
  {
    QsortOpt(0,Kontener -> _Rozmiar(),Kontener);
  }
//***************************************************************
};

#endif
