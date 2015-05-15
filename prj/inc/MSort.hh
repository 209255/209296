#ifndef MSORT_HH
#define MSORT_HH
//************************************************************** 
/*!
 *\file Sortowanie przez scalanie
 *
 * Plik zawiera implementacje algorymu sortowania 
 * przez kopcowanie
 */
//************************************************************** 

//************************************************************** 
/*!
 *\brief Modeluje sortowanie przez scalanie
 *
 * Klasa zawiera implementacje algorytmu
 * sortowania przez scalanie
 */
//************************************************************** 

///////////////////////DEFINICJA KLASY/////////////////////////
template<class Typ>
class MSort:public ISortable<Typ>
{
//**************************************************************
  /*!
   *\brief Metoda Dzielaca tablice
   *
   * Metoda ma za zadanie przekopiowac zawartosc zbiotu glownego do 
   * tablicy tymczasowej.Nastepnie operujac na kopii ustawia wskazniki
   * na poczatki kolejnych zbiorow i porownywane sa wskaane wartosci.
   * Mniejsze wpisujemy do zbioru glownego i przesuwamy odpowiedni wskaznik
   * Czynnos wykonujemy rekurencyjnie az do momentu gdy jeden ze wskaznikow
   * osiagnie koniec zbioru
   *
   *\param[in] Temp - Wskaznik na tablice pomocnicza
   *\param[in] l - Poczatkowy indeks tablicy
   *\param[in] s - Srodkowy indeks tablicy
   *\param[in] p - Koncowy indks tablicy
   */
//**************************************************************
  void Msort(Typ * T,int p,int k,Iterable<Typ> *K)
  {
    int sr;
    if(p < k)
      {
	sr = (k+p)/2;
	//Podzial na Lewa i prawa tablice
	Msort(T,p,sr,K);
	Msort(T,sr+1,k,K);
	//Scalanie posortowanych tablic
	Merge(T,p,sr,k,K);
      } 
  }
  //**************************************************************
  /*!
   *\brief Metoda Dzielaca tablice
   *
   * Metoda ma za zadanie przekopiowac zawartosc zbiotu glownego do 
   * tablicy tymczasowej.Nastepnie operujac na kopii ustawia wskazniki
   * na poczatki kolejnych zbiorow i porownywane sa wskaane wartosci.
   * Mniejsze wpisujemy do zbioru glownego i przesuwamy odpowiedni wskaznik
   * Czynnos wykonujemy rekurencyjnie az do momentu gdy jeden ze wskaznikow
   * osiagnie koniec zbioru
   *
   *\param[in] Temp - Wskaznik na tablice pomocnicza
   *\param[in] l - Poczatkowy indeks tablicy
   *\param[in] s - Srodkowy indeks tablicy
   *\param[in] p - Koncowy indks tablicy
   */
//**************************************************************  
  void Merge(Typ *Temp,int l,int s,int p,Iterable<Typ> *K)
  {
    int i,j;
    for(i = s+1; i >l; i--)
      Temp[i-1] = K -> Wartosc(i-1);
    for(j = s; j < p ;j++)
      Temp[p+s-j] = K -> Wartosc(j+1);
    for(int k = l;k <=p; k++)
      if(Temp[j] < Temp[i])
	K-> Adres(k) = Temp[j--];
      else
	K-> Adres(k) = Temp[i++];
  }
//************************************************************** 
 
public:
//****************************************************************
/*!
 *\brief Metoda inicjalizujaca sortowanie przez scalanie
 *
 * Metoda ma za zadanie zainicjalizowac algorytm sortowania 
 * przez scalanie dla wybranej struktury danych
 *
 * \param[in] Kontener - rodzaj kontenera,ktory zostanie 
 * posortowany
 */
//**************************************************************  
  void _Sort(Iterable<Typ> *Kontener)
  {
    Typ * Temp = new Typ[Kontener ->_Rozmiar()];
    Msort(Temp,0,Kontener ->_Rozmiar()-1,Kontener);
    delete [] Temp;
  }
//**************************************************************  
};
/////////////////////KONIEC DEFINICJI//////////////////////////
#endif
