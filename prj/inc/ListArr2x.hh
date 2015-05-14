/*!
 * \file
 * \brief
 * Definicja klasy ListArr1
 *
 * Plik zawiera definicję klasy ListaArr2x ujętej w szablon typu
 * wraz z jej składowymi metofdami.
 */

#include "IStruktury.hh"
#include "Iterable.hh"
#include <fstream>
#include <cstdlib>
#include <cmath>



/*!
 * \brief
 * Modeluje pojęcie Listy (array) 
 *
 * Modeluje pojęcie Listy opartej na dynamicznej tablicy.
 * Dodając elementy zwiększa tablicę dwukrotnie, jeżeli brakuje miejsca.
 */
template < class Typ>
class ListArr2x : public Struktury<Typ>,public Iterable<Typ> 
{
//**************************************************************
  /*!
   * \brief
   * Wkaźnik na dynamiczną tablicę
   *
   * Wskaźnik na dynamiczną tablicę tworzącą ListęArr2x
   */
//**************************************************************
  Typ *tab;
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
  void _Zamien(unsigned int i,unsigned int j)
  {
    Typ temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
  }
//**************************************************************
  /*!
   * \brief
   * Zwalnia pamięć
   * 
   * Zwalnia pamięć zaalokowaną przez ListArr1
   */
//**************************************************************
  void _Zwolnij() 
  { 
    delete[] tab;
    RozmiarT=1;
    tab = new Typ[RozmiarT];
    RozmiarL = 0;
  }

 

public:

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
    tab = new Typ[RozmiarT];
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
  void _Push (Typ dana, unsigned int pole) {
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
      Typ *tymczasowy = new Typ[RozmiarT];
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
	Typ *tymczasowy = new Typ[RozmiarT];
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
  Typ _Pop(unsigned int pole) {
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
	Typ *tymczasowy = new Typ[RozmiarT];
	Typ wartosc = tab[pole];
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
      Typ *tymczasowy = new Typ[RozmiarT];
      Typ wartosc = tab[pole];
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
  unsigned int _Rozmiar()const { return RozmiarL; } 
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
    Typ k;
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
	    _Push(k,_Rozmiar());
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
 *\brief Metoda wypisujaca elemeny listy
 *
 * Metoda ma za zadanie wypisac wszystkie elementy znajdujace sie 
 * obecnie na liscie danych
 */
//***************************************************************
  void _Pokaz()const
  {
    if(RozmiarL == 0)
      std::cout << "Brak elementow do wyswietlenia" << std::endl;
    else{
      for(unsigned int i = _Rozmiar()-10; i < _Rozmiar(); ++i)
	std::cout << tab[i] << std::endl;
    }
  }
//***************************************************************
const Typ Wartosc(unsigned int i) const
  {
    if(i <0 || i > RozmiarL){
      std::cerr << "Blad! Nie mozna odczytac elementu!" << std::endl;
      exit(1);}
    else
      return tab[i];
  }
//***************************************************************
  Typ & Adres(unsigned int i)
  {
   if(i <0 || i > RozmiarL){
      std::cerr << "Blad! Nie mozna odczytac elementu!" << std::endl;
      exit(1);}
    else
      return tab[i];
  }
    
};

