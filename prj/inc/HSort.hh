#ifndef HSORT_HH
#define HSORT_HH
//************************************************************** 
/*!
 *\file Sortowanie przez kopcowanie
 *
 * Plik zawiera implementacje algorymu sortowania 
 * przez kopcowanie
 */
//************************************************************** 

//************************************************************** 
/*!
 *\brief Modeluje sortowanie przez kopcowanie
 *
 * Klasa zawiera implementacje algorytmu
 * sortowania przez kopcowanie
 */
//************************************************************** 

template<class Typ>
class HSort: public ISortable<Typ>
{
//************************************************************** 
 /*!
  *\brief Metoda sortowania przez Kopcowanie
  *
  * Metoda realizujaca sortowanie rosnace,wykorzystujac przy tym 
  * kopiec.
  *
  * \param[in] Rozmiar -  Rozmiar kopca do zbudowania,
  * ilość danych do posortowania.
  */
//**************************************************************
  void SortowanieKopiec(int Rozmiar,Iterable<Typ> *K)
 {
   BudujKopiec(Rozmiar,K);
    for(unsigned int i = Rozmiar; i > 0; --i)
      {
	K->_Zamien(0,i);
	--Rozmiar;
	Kopiec(Rozmiar,0,K);
      }
  }
//**************************************************************
/*!
 *\brief Metoda skladajaca kopiec
 *
 * Metoda ma za zadanie poprze porownywanie i ustawianie elementow
 * odtworzenie porzadku kopcowego.
 *
 *\param[in] Rozmiar - Rozmar kopca
 *\param[in] i - indeks ostatniego elementu podzbioru
 */
//**************************************************************
  void Kopiec(int Rozmiar,const int i,Iterable<Typ> *K)
  {
    int Duzy;
    int lewy = 2*i+1;
    int prawy = (2*i)+2;
    if(lewy <= Rozmiar && K ->Wartosc(lewy) > K->Wartosc(i))
      Duzy = lewy;
    else Duzy = i;
    if(prawy <= Rozmiar && K->Wartosc(prawy) > K->Wartosc(Duzy))
      Duzy = prawy;
    if(Duzy!= i)
      {
	K -> _Zamien(Duzy,i);
	Kopiec(Rozmiar,Duzy,K);
      }
  }
//**************************************************************
 /*!
   *\brief Metoda tworzaca kopiec
   *
   * Metoda ma za zadanie utworzyc abstrakycjny kopiec
   * z tablicy o podanym poprzez argument rozmiarze
   *
   \param[in] Rozmiar - Rozmiar kopca
   */
//****************************************************************
  void BudujKopiec(int Rozmiar,Iterable<Typ> *K)
  {
    for(int i = Rozmiar/2 -1; i >= 0; --i)
      Kopiec(Rozmiar,i,K);
  }
//****************************************************************

public:
//****************************************************************
/*!
 *\brief Metoda inicjalizujaca sortowanie przez kopcowanie
 *
 * Metoda ma za zadanie zainicjalizowac algorytm sortowania 
 * przez kopcowania dla wybranej struktury danych
 *
 * \param[in] Kontener - rodzaj kontenera,ktory zostanie 
 * posortowany
 */
//****************************************************************
  void _Sort(Iterable<Typ> *Kontener)
  {
    SortowanieKopiec(Kontener -> _Rozmiar(),Kontener);
  }
//****************************************************************
};

#endif
