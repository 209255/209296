#ifndef HYBSORT_HH
#define HYBSORT_HH
#define PROG 13
#define ILE 3
//************************************************************** 
/*!
 *\file Sortowania hybrydowego
 *
 * Plik zawiera implementacje algorymu sortowania 
 * przez kopcowanie
 */
//************************************************************** 

//************************************************************** 
/*!
 *\brief Modeluje sortowania hybrydowego
 *
 * Klasa zawiera implementacje algorytmu
 * sortowania hybrydowego
 */
//************************************************************** 

template <class Typ>
class HybSort:public ISortable<Typ>
{
//**************************************************************
  /*!
   *\brief Metoda segregujaca
   *
   * Metoda ma za zadanie wybor elementu, ktory ma byc uzyty do podzialu
   * i przenosi wszytskie elementy mniejsze na lewo od tego elementu, 
   * a wieksze elementy na prawo od wybranego elementu
   *\param[in] p - poczatkowy indeks podzbiotru
   *\param[in] k - koncowy indeks podzbioru
   *\return
   *
   */
//**************************************************************
  int Partycjowanie(int p,int k,Iterable<Typ> *K)
 {
   Typ Index[] = { K -> Wartosc(p), K -> Wartosc((p+k)/2)
		   ,K -> Wartosc(k)}; 
   Typ Pivot = Mediana(Index);
   int i = p; 
   int j = k;
   while(1)
     {
       while(K ->Wartosc(j) > Pivot) j--;
       while(K ->Wartosc(i) < Pivot) i++;
	if( i < j ){
	  K ->_Zamien(i,j);
	  i++; j--;}
	
	else return j;
     }
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
  Typ Mediana(Typ *W)
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
   
//**************************************************************
 /*!
  *\brief Sortowanie przez Wstawianie 
  * Metoda ma za zadanie posortowac tablice przyjmowana 
  * jako argument
  *\param[in] T - Wskaznik na tablice z danymi wejsciowymi
  *\param[in] l - Poczatkowy indeks elementu sortowanego
  *               podzbioru
  *\param[in] p - koncowy indeks elementu sortowanego 
  *               podzbioru
  */
//***************************************************************
  void Wstaw_Sort(int l,int p,Iterable<Typ> *K)
  {
    Typ temp;
    int j;
    for(int i = l ; i < p; ++i)
      {
	temp = K ->Wartosc(i);
	for(j = i -1; j >= 0 && K->Wartosc(j) > temp; --j)
	  K-> Adres(j+1) = K->Wartosc(j);
	K-> Adres(j+1) = temp;
      }
  }
//***************************************************************
/*!
 *\brief Metoda sortowania hybrydowego
 *
 * Metoda ta jest implementacja algorytmu sortowania
 * hybrydowego, bedacego polaczeniem sortowania szybkiego
 * i sortowania przez wstawianie
 * Po zakonczeniu rekurencyjnych wywolan Partycjowania,
 * tablica jest podzielona na szereg malych podzbiorow o 
 * o rozmiarze nie przekraczajacemu ustalonego progu.
 * Zbioru sa porozdzielana elementami ktore wykorzystywane byly
 * jako elementy osiowe.
 * Dla czesciowo posortowanej tablicy wywolywane jest sortowanie 
 * przez wstawianie, ktore jest wydajne dla tablic o malych 
 * rozmiarach
 *
 *\param[in] l - indeks poczatkowego elementu pozbioru
 *\param[in] h - indeks koncowego elementu podzbioru
 */
//**************************************************************
  void Sortowanie_Hybrydowe(int l, int h,Iterable<Typ> *K)
  {
    int p;
    if(l-h)
      {
	p = Partycjowanie(l,h,K);
	if(p  - l > PROG)
	  Sortowanie_Hybrydowe(l,p,K);
	else
	  Wstaw_Sort(l,p,K);
	if(h - p  > PROG)
	  Sortowanie_Hybrydowe(p+1,h,K);
	else
	  Wstaw_Sort(p+1,h,K);
      }
  }
//**************************************************************

public:

//****************************************************************
/*!
 *\brief Metoda inicjalizujaca sortowanie hybrydowe
 *
 * Metoda ma za zadanie zainicjalizowac algorytm sortowania 
 * hybrydowego dla wybranej struktury danych
 *
 * \param[in] Kontener - rodzaj kontenera,ktory zostanie 
 * posortowany
 */
//**************************************************************
  void _Sort(Iterable<Typ> *Kontener)
  {
    Sortowanie_Hybrydowe(0, Kontener ->_Rozmiar(),Kontener);
  }
//**************************************************************
};

#endif
