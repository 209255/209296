#ifndef CZASOMIERZ_HH
#define CZASOMIERZ_HH
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
//*******************************************************************************
/*!
 *\file Definicja Klasy Czasomierz
 *
 *Plik zawiera definicje klasy Czasomierz wraz z deklaracjami metod
 */
//*******************************************************************************

//*******************************************************************************
/*!
 *\brief Modeluje pojecie Czasomierza
 *
 * Klasa ma za zadanie mierzyc czas wykonywania danego algorytmu
 * oraz przechowywac informacje o srednich czasach pomiarow dla wybranej 
 * ilosci danych przy okreslonej liczbie powtorzen testu
 */
//*******************************************************************************

////////////////////////////////DEFINICJA KLASY///////////////////////////////////
class Czasomierz
{
private:
//*******************************************************************************
/*!
 *\brief Pole klasy Czasomierz
 *
 * Pole przechowuje informacje, ktora jest czas systemu w chwili uruchomienia 
 * Stopera
 */
//*******************************************************************************
  clock_t _Start;
//*******************************************************************************
/*!
 *\brief Pole klasy Czasomierz
 *
 * Pole przechowuje informacje, ktora jest czas systemu w chwili zakonczenia 
 * pomiaru
 */
//*******************************************************************************
  clock_t _Koniec;
//*******************************************************************************
/*!
 *\brief Pole klasy Czasomierz
 *
 * Pole przechowuje czas w ms, odpowiadajacy czasowi aktualnego pomiaru 
 * dla danej ilosci danych
 */
//*******************************************************************************
  long double _Aktualny;
//*******************************************************************************
/*!
 *\brief Pole klasy Czasomierz
 *
 * Pole przechowuje informacje o stanie Czasomierza,tzn czy obecnie odmierza czas 
 * czy nie 
 */
//*******************************************************************************
  bool _Status;
//*******************************************************************************

public:
//*******************************************************************************
/*!
 *\brief Konstruktor obiektu
 *
 *Konstruktor klasy Czasomierz, zerujacy wszystkie pola tej klasy
 */
//*******************************************************************************
  Czasomierz();
//*******************************************************************************
/*!
 *\brief Metoda zaczynajaca pomiar
 *
 * Metoda ma za zadanie odczytac czas systemowy w momencie jej wywolania
 * i zapisania tej informacji w odpowiednim polu klasy.
 * Zmienia rowniez status pracy czasomierza na zajety.
 */
//*******************************************************************************
  void _RozpocznijPomiar();
//*******************************************************************************
/*!
 *\brief Metoda konczaca pomiar
 *
 * Metoda ma za zadanie odczytac czas systemowy w momencie jej wywolania
 * i zapisania tej informacji w odpowiednim polu klasy.
 * Zmienia status pracy czasomierza na wolny
 */
//*******************************************************************************
  void _ZakonczPomiar();
//*******************************************************************************
/*!
 *\brief Metoda Aktualizujaca czas danej proby
 *
 * Metoda ma za zadanie zaktualizowac czas danej proby,
 * za sprawa dodadania do poprzedniej sumy pomiarow,
 * czas ktory przypada na najnowszy pomiar
 */
//*******************************************************************************
  void  _AktualizujCzas();
//*******************************************************************************
/*!
 *\brief Metoda zwracajaca calkowity czas Proby
 *
 * Metoda ma za zadanie zwrocic calkowity czas przypadajacy na 
 * dana probe
 */
  long double _CzasTrwania()const;
//*******************************************************************************
/*!
 *\brief Metoda resetujaca Czasomierz
 * 
 * Metoda ma za zadanie wyzerowac pola przechowujace informacje o
 * czasie systemowym zapisanym na poczatku i na koncu pomiaru.
 * Zmienia status czasomierza na wolny
 */
//*******************************************************************************
  void _Reset();
//*******************************************************************************
/*!
 *\Metoda informujaca o stanie czasomierza
 *
 * Metoda ma za zadanie poinformowanie w jakim stanie znajduje sie obecnie
 * czasomierz
 */
//*******************************************************************************
  bool _StatusPracy()const;
//*******************************************************************************
/*!
 *\brief Metoda zwracajaca czas pojedynczego pomiaru
 *
 * Metoda ma za zadanie zwrocic czas trwania pojedynczego testu
 */
//*******************************************************************************
  double _PojedynczyPomiar()const;
//*******************************************************************************
};
///////////////////////////////KONIEC DEFINICJI///////////////////////////////////
#endif
