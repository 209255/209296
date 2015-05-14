#ifndef STOSTAB_HH
#define STOSTAB_HH
#include <cstdlib>
#include <iostream>
#include "IStruktury.hh"
#include "Iterable.hh"
//****************************************************************************************
/*!
 *\file Definicja Klasy ListaTab
 *
 * Plik zawiera definicje klasy StosTab,zaimplementowana w sposob tablicowy,realizujacy 
 * realokacje dynamicznej tablicy do 200% poprzedniego rozmiaru w momencie dodawania 
 * elementu od niej.
 * Jest to klasa klasa pochodna od Struktury, naglowke zawiera deklaracje metod 
 */
//****************************************************************************************

//////////////////////////////////DEFINICJA KLASY/////////////////////////////////////////
template<class Typ>
class StosTab : public Struktury<Typ>,public Iterable<Typ>
{
//****************************************************************************************
/*!
 *\brief Pole klasy StosTab
 *
 *Pole zawiera wskaznik na typ calkowity, sluzy do alokacji pamieci na dynamiczna tablice
 */
//****************************************************************************************
  Typ * _L;
//****************************************************************************************
/*!
 *\brief Pole Klasy StosTab
 *
 *Pole przechowuje informacje o ilosci obecnie znajdujacych sie elementow na liscie danych
 */
//****************************************************************************************
  unsigned int _RozmiarL;
//****************************************************************************************
/*!
 *\brief Pole Klasy StosTab
 *
 *Pole przechowuje informacje o obecnycm rozmiarze tablicy danych
 */
//****************************************************************************************
  unsigned int _RozmiarT;	
//****************************************************************************************


public:

//****************************************************************************************
/*!
 *\brie Metoda zwalniajaca pamiec
 *
 *Metoda ma za zadanie zwolnij pamiec zajmowana przez dane, dopoki ilosc elementow 
 * listy nie wynosi 0 wykonywana jest metoda _Pop, aby oproznic stos i zwolnic pamiec
 */
//****************************************************************************************
  void _Zwolnij()
  {
     delete[] _L;
     _RozmiarT = 1;
     _L = new Typ[_RozmiarT];
     _RozmiarL = 0;
  }
//****************************************************************************************
/*!
 *\brief Konstruktor
 *Podczas tworzenia obiektu tej klasy automatycznie alokowana jest tablica o rozmiarze 1
 * oraz ustawienie obecnej liczby elementow listy na 0
 */
//***************************************************************************************
  StosTab()
  {
    _L = new Typ[1];
    _RozmiarL = 0;
    _RozmiarT = 1;
  }
//****************************************************************************************   
/*!
 *\brief Konstruktor Kopiujacy
 */
//****************************************************************************************
  StosTab(const StosTab & K)
  {
    _L = new Typ[K._RozmiarL];
    for(unsigned int i = 0;i < K._RozmiarL; ++i)
      _L[i] = K._L[i];
  }    
//****************************************************************************************    
/*!
 *\brief Destruktor obiektu
 */
//****************************************************************************************
  virtual~ StosTab(){delete [] _L;};
//****************************************************************************************	
/*!
 *\brief Metoda wypisujaca elemeny Stosu
 *
 *Metoda ma za zadanie wypisac wszystkie elementy znajdujace sie obecnie 
 * na liscie danych
 */
//****************************************************************************************
  void _Pokaz() const
  {
    if(_Rozmiar() == 0)
      std::cout << "Brak elementow do wyswietlenia" << std::endl;
    else{
      for(unsigned int i = _Rozmiar()-10; i < _Rozmiar(); ++i)
		std::cout << _L[i] << std::endl;
    }
  }
//****************************************************************************************    
/*!
 *\brief Metoda sciagajaca element ze stosu
 *
 * Metoda ma za zadanie sciagnac ostatni element stosu, w przypadku gdy tablica jest
 * do połowy pusta nastepuje utworzenie nowej tablicy o dwa razy mniejszym rozmiarze
 *\param[in] Pozycja - numer elementy kotry zostanie usuniety z listy i zostanie zwrocona jego 
 * wartosc
 *
 *\return
 * Zwraca wybrany przez uzytkownika element
 */
//****************************************************************************************
  Typ _Pop(unsigned int Pozycja = 0)
  {
    Pozycja = _Rozmiar();//usuwanie z konca
    if(_Rozmiar() == 0)
      { 
	std::cerr << "Blad! Lista jest pusta!" << std::endl; 
	exit(1);
    }
    else
      {
	Typ Wartosc = _L[Pozycja -1];
	if(_RozmiarT >= 2*_RozmiarL)
	  {
	    Typ *Temp = new Typ[ _RozmiarT =_RozmiarT/2];
	    for(unsigned int i = 0;i <_Rozmiar()-1; ++i)
	      {
		Temp[i] = _L[i];
	      }
	    delete [] _L;
	    _L = Temp;
	    --_RozmiarL;
	    return Wartosc;
	  }
	else{ --_RozmiarL; return _L[_Rozmiar()];}
      }
    std::cerr << "Blad podczas usuwania wartosci ze stosu!"
	      << std::endl; exit(1);
  }
//****************************************************************************************
/*!
 *\brief Metoda dodajaca elemet do tablicy
 *
 * Metoda ma za zadanie dodac nowy element na koncu stosu, w przypadku zapelnienia tablicy
 * nastepuje utworzenie nowej tablicy i przepisanie elementow
 *
 *\param[in] k - wartosc jaka chcemy dodac do listy
 *\param[in] Pozycja - Pozycja na ktorej chcemy dodac wartosc
 */
//****************************************************************************************
  void _Push(Typ k,unsigned  int Pozycja = 0)
  {
    Pozycja = _Rozmiar() + 1; //dodawanie zawsze na koniec
    if(_RozmiarL == 0){ _L[0] = k;}
    else 
      {
	if(_RozmiarT == _RozmiarL)
	  {
	    Typ *Temp = new Typ[_RozmiarT = 2*_RozmiarT];
	    Temp[Pozycja-1] = k;
	    for(unsigned int i = 0;i <_Rozmiar(); ++i)
	      {
		Temp[i] = _L[i];
	      }
	    delete [] _L;
	    _L = Temp;
	  }
	else{ _L[_Rozmiar()] = k; }
      }
    ++_RozmiarL;
  }
//****************************************************************************************
/*!
 *\brief Metoda zwracajaca rozmiar listy
 * 
 * Metoda zwraca informacje o obecnej ilosci danych w strukturze 
 *
 *\return 
 * Zwraca ilosc elementow listy
 */
//****************************************************************************************
  unsigned int _Rozmiar() const{return _RozmiarL;}
//****************************************************************************************
  const Typ Wartosc(unsigned int Index)const {return _L[Index];}
//****************************************************************************************
  Typ & Adres(unsigned int Index) {return _L[Index];}
//****************************************************************************************
  /*!
   *\brief Metoda zamieniajaca 
   * Metoda ma za zadanie zamienic miejscami elementy wybrane przez 
   * argumenty wywolania
   *
   *\param[in] i - Adres elementu podlegajacy zamianie
   *\param[in] j - Adres elementu podlegajacy zamianie
   */
//****************************************************************************************
  void _Zamien(unsigned int i,unsigned int j)
  {
    Typ temp = _L[i];
    _L[i] = _L[j];
    _L[j] = temp;
  }
//****************************************************************************************
};
#endif
