#ifndef ISORTABLE_HH
#define ISORTABLE_HH
#include "Iterable.hh"
//******************************************************************
/*!
 *\file Interfejs ISortable
 *Plik zawiera definicje abstrakcyjnego interfejsu ISortable
 */
//******************************************************************

//******************************************************************
/*!
 *\brief Definicja klasy ISortable
 *
 * Klasa modeluje pojecie abstrakcyjnego interfejsu ISortable,
 * dzieki ktoremu uzytkownik moze wykorzystac dowolny algorytm 
 * sortowania dla wybranego konteneru
 */
//******************************************************************

///////////////////DEFINICJA KLASY/////////////////////////////////
template<class Typ>
class ISortable
{
public:
//******************************************************************
/*!
 *\brief Metoda inicjalizujaca sortowanie
 *
 * Metoda ma za zadanie uruchomic dowolny zaimplementowany 
 * algorytm sortowania dla struktury danych okreslonej 
 * poprzez argument jaki przyjmuje ta metoda
 *
 *\param[in] Kontener - wskaznik na obiekt ktory ma ulec 
 * posortowaniu
 */
//******************************************************************
  virtual void _Sort(Iterable<Typ> *Kontener) = 0;
//******************************************************************
};
///////////////////////KONIEC DEFINICJI////////////////////////////
#endif
