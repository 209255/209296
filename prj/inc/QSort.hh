#ifndef QSORT_HH
#define QSORT_HH
//************************************************************** 
/*!
 *\file Sortowanie Szybkie
 *
 * Plik zawiera implementacje algorymu sortowania 
 * szybkiego
 */
//************************************************************** 

//************************************************************** 
/*!
 *\brief Modeluje sortowanie szybkie
 *
 * Klasa zawiera implementacje algorytmu
 * sortowania szybkiego
 */
//************************************************************** 

template<class Typ>
class QSort:public ISortable<Typ>
{
//**************************************************************
/*!
 *\brief Metoda bedaca implementacja 
 * algorytmu sortowania szybkiego
 *
 *\param[in] l - poczatkowy indeks tablicy 
 *\param[in] h - koncowy indeks tablicy
 */
//**************************************************************
  void Qsort(int l,int h,Iterable<Typ> *K)
 {
    int p;
    if( l < h)
      {
	p = Partycjowanie(l,h,K);
	Qsort(l,p,K);
	Qsort(p+1,h,K);
      }
  }
//**************************************************************
  /*!
   *\brief Metoda segregujaca
   *
   * Metoda ma za zadanie wybor elementu, ktory ma byc
   * uzyty do podzialu i przenosi wszytskie elementy 
   * mniejsze na lewo od tego elementu, 
   * a wieksze elementy na prawo od wybranego elementu
   *\param[in] p - poczatkowy indeks podzbiotru
   *\param[in] k - koncowy indeks podzbioru
   *\return
   *
   */
//**************************************************************
  int Partycjowanie(int p,int k,Iterable<Typ> *K)
  {
    Typ Pivot = K->Wartosc((p+k)/2);
    int i = p; 
    int j = k;
    while(1)
      {
	while(K -> Wartosc(j) > Pivot) j--;
	while(K-> Wartosc(i) < Pivot) i++;
	if( i < j ){
	  K -> _Zamien(i,j);
	  i++; j--;}
      
	else return j;
      }
  }
//**************************************************************

public:
//**************************************************************
/*!
 *\brief Metoda inicjalizujaca sortowanie szybkie
 *
 * Metoda ma za zadanie zainicjalizowac algorytm sortowania 
 * szybkiego dla wybranej struktury danych
 *
 * \param[in] Kontener - rodzaj kontenera,ktory zostanie 
 * posortowany
 */
//**************************************************************
  void _Sort(Iterable<Typ> *Kontener)
  {
    Qsort(0,Kontener -> _Rozmiar()-1,Kontener);
  }
//**************************************************************
};

#endif
