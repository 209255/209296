#ifndef ITERABLE_HH
#define ITERABLE_HH
//***************************************************************************
/*!
 *\file interfejs Iterable
 *
 * Plik zawiera definicja abstrakcyjnego interfejsu Iterable wraz z 
 * deklaracjami metod
 */
//***************************************************************************

//***************************************************************************
/*!
 *\brief Interfejs Iterable
 *
 * Klasa modeluje pojecie abstrakcyjnego interfejsu iterable, dzieki
 * ktoremu algorytmu sortujace maja dostep do kontenera z danymi
 * poprzez odczyt danego pola i mozliwosci zamiany elementow miejscami
 */
//***************************************************************************

////////////////////////DEFINICJA KLASY//////////////////////////////////////
template<class Typ>
class Iterable
{
public:
//**************************************************************************
/*!
 *\brief Metoda zwracajaca wartosc
 * 
 * Metoda ma za zadanei zwrocic wartosc,kryjaca sie pod danym indeksem
 * dla dowolnego kontenera posiadajacego interfejs.
 *
 *\param[in] i -Indeks z ktorego zostanie odczytana wartosc
 *
 *\return Zwraca wartosc, kryjaca sie pod danym indeksem konteneru
 */
//***************************************************************************
  virtual const Typ Wartosc(unsigned int i)const = 0;
//***************************************************************************
/*!
 *\brief Metoda zwracajaca referencje
 *
 * Metoda ma za zadanie zwrocic referencje do pola kontenera zadanego 
 * poprzez argument metody
 */
//***************************************************************************
  virtual Typ & Adres(unsigned int i) = 0;
//***************************************************************************
/*!
 * \brief Metoda zamieniajaca 
 *
 * Metoda ma za zadanie zamienic elementy miejscami
 * \param[in] i - indeks,pod ktorym wartosc z konteneru zostanie 
 *                zamieniona miejscem
 *\param[in] j - indeks,pod ktorym wartosc z konteneru zostanie 
 *                zamieniona miejscem
 */
//***************************************************************************
  virtual void _Zamien(unsigned int i,unsigned int j) = 0;
//***************************************************************************
/*!
 *\brief Metoda informujaca o rozmiarze
 *
 * Metoda ma za zadanie zwrocic informajce o rozmiarze 
 * kontenera
 */
//***************************************************************************
  virtual unsigned int _Rozmiar()const = 0;
//***************************************************************************
};
///////////////////////KONIEC DEFINICJ///////////////////////////////////////
#endif
