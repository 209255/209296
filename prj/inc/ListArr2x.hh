/*!
 * \file
 * \brief
 * Definicja klasy ListArr1
 *
 * Plik zawiera definicję klasy ListaArr2x ujętej w szablon typu
 * wraz z jej składowymi metofdami.
 */

#include "InterfejsADT.hh"
#include <fstream>
#include <cstdlib>
#include <cmath>
#define ILE 3
#define PROG 13

/*!
 * \brief
 * Modeluje pojęcie Listy (array) 
 *
 * Modeluje pojęcie Listy opartej na dynamicznej tablicy.
 * Dodając elementy zwiększa tablicę dwukrotnie, jeżeli brakuje miejsca.
 */
template < class typ>
class ListArr2x : public InterfejsADT<typ> {
//**************************************************************
  /*!
   * \brief
   * Wkaźnik na dynamiczną tablicę
   *
   * Wskaźnik na dynamiczną tablicę tworzącą ListęArr2x
   */
//**************************************************************
  typ *tab;
//**************************************************************
  /*!
   * \brief
   * Rozmiar tablicy
   *
   * Aktualny rozmiar tablicy.
   */
//**************************************************************
  unsigned int RozmiarT;
//**************************************************************
  /*!
   * \brief
   * Rozmiar Listy
   *
   * Aktualny rozmiar ListyArr2x
   */
//**************************************************************
  unsigned int RozmiarL;
//**********************************************************************
  /*!
   *\brief Mediana
   * Metoda wyznaczajaca mediana dla tablicy 3 elementowej.
   * Jest to metoda pomocnicza, wykorzystywana  przy optymalizacji
   * doboru pivotu w sortowaniu szybkim
   * \return Zwraca indeks na ktorym znajduje sie mediana w tablicy wejsciowej
   */
//**********************************************************************
  int Mediana(typ *W)
  {
    int j = 0;
    typ Temp[ILE];
    for(int i = 0; i < ILE; i++)
      Temp[i] = W[i];
    Wstaw_Sort(Temp,0,ILE);
    while(Temp[1]!=W[j]) j++;
    return j;
  }
//**********************************************************************
  /*!
   *\brief
   * Metoda testująca czas
   *
   * Metoda testująca czas wczytania n elementów na ListęArr1
   *
   * \param[in] k - ilość elementów do wczytania
   */
//**************************************************************
  void StartMsort(unsigned int k)
  {
    typ * Temp = new typ[size()];
    MSort(Temp,0,(k-1));
    delete [] Temp;
  }
//**************************************************************
  /*!
   *\brief
   * Metoda testująca czas
   *
   * Metoda testująca czas wczytania n elementów na ListęArr1
   */
//**************************************************************
  void Start()
  {
    Sortowanie_Hybrydowe(0,size());
  }
//**************************************************************
  /*!
   *\brief Metoda zamieniajaca 
   * Metoda ma za zadanie zamienic miejscami elementy wybrane przez 
   * argumenty wywolania
   *
   *\param[in] i - Adres elementu podlegajacy zamianie
   *\param[in] j - Adres elementu podlegajacy zamianie
   */
//**************************************************************
  void Zamien(typ & i,typ & j)
  {
    typ temp = i;
    i = j;
    j = temp;
  }
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
  int Partycjowanie(int p,int k)
  {
    int Index[] = {p, (p+k)/2,k}; 
    int m = Mediana(Index);
    typ Pivot = tab[Index[m]];
    int i = p; 
    int j = k;
    while(1)
      {
	while(tab[j] > Pivot) j--;
	while(tab[i] < Pivot) i++;
	if( i < j ){
	  Zamien(tab[i],tab[j]);
	  i++; j--;}
      
	else return j;
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
  void Merge(typ *Temp,int l,int s,int p)
  {
    int i,j;
    for(i = s+1; i >l; i--)
      Temp[i-1] = tab[i-1];
    for(j = s; j < p ;j++)
      Temp[p+s-j] = tab[j+1];
    for(int k = l;k <=p; k++)
      if(Temp[j] < Temp[i])
	tab[k] = Temp[j--];
      else
	tab[k] = Temp[i++];
  }
//**************************************************************
  /*!
   * \brief
   * Zwalnia pamięć
   * 
   * Zwalnia pamięć zaalokowaną przez ListArr1
   */
//**************************************************************
  void Zwolnij() 
  { 
    delete[] tab;
    RozmiarT=1;
    tab = new typ[RozmiarT];
    RozmiarL = 0;
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
  void Kopiec(int Rozmiar,const int i)
  {
    int Duzy;
    int lewy = 2*i+1;
    int prawy = (2*i)+2;
    if(lewy <= Rozmiar && tab[lewy] > tab[i])
      Duzy = lewy;
    else Duzy = i;
    if(prawy <= Rozmiar && tab[prawy] > tab[Duzy])
      Duzy = prawy;
    if(Duzy!= i)
      {
	Zamien(tab[Duzy],tab[i]);
	Kopiec(Rozmiar,Duzy);
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
//**************************************************************
  void BudujKopiec(int Rozmiar)
  {
    for(int i = Rozmiar/2 -1; i >= 0; --i)
      Kopiec(Rozmiar,i);
  }
//**************************************************************

public:

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
  void Wstaw_Sort(typ * W,int l,int p)
  {
    typ temp;
    int j;
    for(int i = l ; i < p; ++i)
      {
	temp = W[i];
	for(j = i -1; j >= 0 && tab[j] > temp; --j)
	  W[j+1] = W[j];
	W[j+1] = temp;
      }
  }
 //**************************************************************
  /*!
   * \brief
   * Konstruktor bezarumentowy
   *
   * Kontruktor alokujący tablicę jednoelementową z której będzie
   * tworzona lista
   */
//**************************************************************
  ListArr2x() {
    RozmiarT = 1;
    tab = new typ[RozmiarT];
    RozmiarL = 0;
  }
//**************************************************************
  /*!
   * \brief
   * Dodaje element do ListyArr1
   *
   * Dodaje nowy element do ListyArr1
   *
   * \param[in] dana - element który chcemy umieścić na liście
   * \param[in] pole - nr pola na którym chcemy umieścić element
   *                   jeżeli chcesz umieścić na początku listy podaj
   *                   wartość 0, na końcu warość size()
   */
//**************************************************************
  void push (typ dana, unsigned int pole) {
    if(pole < 0 || pole > RozmiarL) {
      std::cerr << "Blad dodania elementu na ListArr2x."
		<<" Bledny nr pola. Zakres poprawnych wartosci pola: 0 - " 
		<< RozmiarL << std::endl;
    }
    else if(RozmiarL == 0) {
      tab[0] = dana;
      ++RozmiarL;
    }
    else if(RozmiarL == RozmiarT) {
      ++RozmiarL; 
      RozmiarT = 2*RozmiarT;
      typ *tymczasowy = new typ[RozmiarT];
      for (unsigned int i = 0; i < pole; ++i)
	tymczasowy[i] = tab[i];
      tymczasowy[pole] = dana;
      for (unsigned int i = (pole+1); i < RozmiarL; ++i)
	tymczasowy[i] = tab[i-1];
      delete[] tab;
      tab = tymczasowy;
    }
    else {
      if(pole == RozmiarL) {
	tab[RozmiarL] = dana;
	++RozmiarL;
      }
      else {
	++RozmiarL;
	typ *tymczasowy = new typ[RozmiarT];
	for(size_t i = 0; i < pole; ++i)
	  tymczasowy[i] = tab[i];
	tymczasowy[pole] = tab[pole];
	for(size_t i = (pole+1); i < RozmiarL; ++i)
	  tymczasowy[i] = tab[i-1];
	delete[] tab;
	tab = tymczasowy;
      }
    }
  }
//**************************************************************
  /*!
   * \brief
   * Pobiera element z ListyArr1
   *
   * Pobiera element z ListyArr2x usuwając go z niej i zmniejszając rozmiar
   * o połowę w przypadku przekroczenia stosunku 1:4 (RozmiarL:RozmiarT)
   *
   * param[in] - pole - nr pola z którgo chcemy pobrać element (indeksowane od 0)
   *
   * retval - zwraca wartosc pobranej danej lub '-1' w przyadku bledu
   */
//**************************************************************
  typ pop(unsigned int pole) {
    if(RozmiarL == 0) {
      std::cerr << "Blad! Nie mozna pobrac elementu z pustej listy!" 
		<< std::endl; return -1;
    }
    else if(pole < 0 || pole > (RozmiarL-1)) {
      std::cerr << "Blad pobrania elementu. "
		<< "Blednny nr pola. zakres popranwych wartosci pola: 0 - " 
		<< RozmiarL-1 << std::endl; return -1;
    }
    else if(4*RozmiarL >= RozmiarT ) {
      if(pole == (RozmiarL-1)) {
	--RozmiarL;
	return tab[RozmiarL];
      }
      else {
	--RozmiarL;
	typ *tymczasowy = new typ[RozmiarT];
	typ wartosc = tab[pole];
	for(size_t i = 0; i < pole; ++i)
	  tymczasowy[i] = tab[i];
	for(size_t i = (pole+1); i < RozmiarL; ++i)
	  tymczasowy[i-1] = tab[i];
	delete[] tab;
	tab = tymczasowy;
	return wartosc;
      }
    }
    else {           // stosunek < 1:4
      --RozmiarL;
      RozmiarT = RozmiarT/2;
      typ *tymczasowy = new typ[RozmiarT];
      typ wartosc = tab[pole];
      for(size_t i = 0; i < pole; ++i)
	tymczasowy[i] = tab[i];
      for(size_t i = pole; i < RozmiarL; ++i)
	tymczasowy[i] = tab[i+1];
      return wartosc;
    }
    std::cout << "Blad usuniecia z listy" << std::endl;
    return -1;
  }
//**************************************************************
  /*!
   * \brief
   * Wielkość listy
   *
   * Informuje o ilości elementów znajdujących się na LiścieArr1
   * 
   * \retval - zwraca liczbę elementów ListyArr1
   */
//**************************************************************
  unsigned int size() { return RozmiarL; } 
//**************************************************************
  /*!
   * \brief
   * Wczytuje dane z pliku
   * 
   * Wczytuje dane z pliku do ListArr1
   *
   * param[in] nazwaPliku - nazwa pliku z danymi
   * param[in] n - ilość danych do wczytania, 
   * 0 oznacza wszystkie dane z pliku
   */
//**************************************************************
  void WczytajDane(const std::string PlikIn, unsigned int n) 
  {
    //std:: cout << "Wczytuje" << std::endl;
    typ k;
    std::ifstream Plik_in;
    Plik_in.open(PlikIn.c_str(),std::ios::in);
    if(!Plik_in)
      {
      std::cerr << "Blad przy otwieraniu Pliku: " << PlikIn << std::endl;
      }
    else
      {
	for(unsigned int i = 0; i< n; ++i)
	  {
	    Plik_in >> k;
	    push(k,size());
	    if(Plik_in.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych" 
			  << std::endl;
	      }
	  }
      }
    Plik_in.close();
  }
//************************************************************** 	 
/*!
 *\brief Metoda wykorzystujaca sortowanei szybkie
 *\param[in] l - poczatkowy indeks tablicy 
 *\param[in] h - koncowy indeks tablicy
 */
//**************************************************************	  
  void Qsort(int l,int h)
  {
    int p;
    if( l < h)
      {
	p = Partycjowanie(l,h);
	Qsort(l,p);
	Qsort(p+1,h);
      }
  }
//**************************************************************
  /*!
   *\brief Zotymalizowane Sortowanie Szybkie
   *
   * Metoda modeluje algorytm sorotwanie szybkiego z zaimplementowanym
   * algorytmem doboru pivotu, tak aby nie zostal wybrany najmniejszy 
   * element w danym podzbiorze.
   *\parma[in] lewy - poczatkowy indeks pozbioru
   *\param[in] prawy - koncowy indeks podzbioru
   */
//**************************************************************
  void QsortOpt(int lewy, int prawy1)
  {
    int Index[] = {lewy, (lewy+prawy1)/2,prawy1}; 
    int m = Mediana(Index);
    typ Pivot = tab[Index[m]];
    int i = lewy;
    int j = prawy1;
    do
      {
	while(tab[i] < Pivot) ++i;
	while(tab[j] > Pivot) --j;
	if( i <= j )
	{
	  Zamien(tab[i],tab[j]);
	  ++i;--j;
	}
      }
    while( i <= j );
    if(j > lewy) QsortOpt(lewy,j);
    if(i < prawy1) QsortOpt(i,prawy1);
  }
//**************************************************************
/*!
 *\brief Metoda wypisujaca elemeny listy
 *
 * Metoda ma za zadanie wypisac wszystkie elementy znajdujace sie 
 * obecnie na liscie danych
 */
//***************************************************************
  void Pokaz()
  {
    if(RozmiarL == 0)
      std::cout << "Brak elementow do wyswietlenia" << std::endl;
    else{
      for(unsigned int i = 0; i < size(); ++i)
	std::cout << tab[i] << std::endl;
    }
  }
//**************************************************************  
  void MSort(typ * T,int p,int k)
  {
    int sr;
    if(p < k)
      {
	sr = (k+p)/2;
	//Podzial na Lewa i prawa tablice
	MSort(T,p,sr);
	MSort(T,sr+1,k);
	//Scalanie posortowanych tablic
	Merge(T,p,sr,k);
      } 
  }
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
  void SortowanieKopiec(int Rozmiar)
  {
    BudujKopiec(Rozmiar);
    for(unsigned int i = Rozmiar; i > 0; --i)
      {
	Zamien(tab[0],tab[i]);
	--Rozmiar;
	Kopiec(Rozmiar,0);
      }
  }
//**************************************************************
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
  void Sortowanie_Hybrydowe(int l, int h)
  {
    int p;
    if(l-h)
      {
	p = Partycjowanie(l,h);
	if(p  - l > PROG)
	  Sortowanie_Hybrydowe(l,p);
	else
	  Wstaw_Sort(tab,l,p);
	if(h - p  > PROG)
	  Sortowanie_Hybrydowe(p+1,h);
	else
	  Wstaw_Sort(tab,p+1,h);
      }
  }
//**************************************************************
  
};

