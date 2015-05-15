#ifndef BENCHMARKINTERFEJS_HH
#define BENCHMARKINTERFEJS_HH
#define DLUGOSC_SLOWA 5
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <list>
#include "IObserwowany.hh"

using namespace std;
//****************************************************************************************
/*!
 *\file Definicja klasy BenchmarkInterfejs
 *
 * Plik zawiera definicje interfejsu klasy Benchmarkujacej algorytmy,
 * jest to klasa abstrakcyjna bedaca bazowa dla klasy StrukturyBenchmark.
 * Zawierda deklaracje metod czysto wirtualnych oraz metod sluzaych do generowania 
 * i odczytywania pliku z danymi wejsciowymi
 */

//****************************************************************************************
/*!
 *\brief Modeluje pojecie Interfejsu Benchmark'u
 *
 *Klasa bazowa dla implementowania benchmarku dla kolejnych struktur danych
 */
//****************************************************************************************

////////////////////////////////DEFINICJA KLASY//////////////////////////////////////////

class BenchmarkInterfejs
{
protected:
//****************************************************************************************
/*!
 *\brief Metoda Wykonujaca pojedyncza operacje
 *
 * Metoda ma za zadanie wykonan pojedyncza operacja, ktorej czas jest rejestrowany
 *\param[in] Ilosc - Liczba danych poddana testowi
 */
//****************************************************************************************
  virtual void _Test()const  = 0;
//****************************************************************************************
/*!
 *\brief Metoda wczytujaca dane z pliku
 * Metoda ma za zadanie wczytac dane z pliku wejsciowego
 *\param[in] PlikIn - Nazwa pliku wejsciowego
 *\param[in] n - liczba wczytywanych danych 
 */
//****************************************************************************************
  virtual void _Wczytaj(string PlikWart) = 0;
//****************************************************************************************
/*!
 *\brief Metoda wypelniajaca 
 *Metoda ma za zadanie wypelnic dany kontener danymi
 *
 *\param[in] n - ilosc danych 
 */
//****************************************************************************************
  virtual void _Zaladuj(const unsigned int n)const = 0;
//****************************************************************************************
/*!
 *\brief Metoda zwalniajaca Pamiec
 *
 * Metoda ma za zadanie zwolnic pamiec przeznaczona na dane
 * przechowywane w kontenerze
 */
//****************************************************************************************
  virtual void _Zwolnij() = 0;
//****************************************************************************************
/*!
 *\brief Metoda generujaca dane
 *
 * Metoda ma za zadanie wygenerowac pseudolosowe dane 
 * i zapisac je do pliku
 */
//****************************************************************************************
  virtual void _Generator()const = 0;
//****************************************************************************************
};
////////////////////////////////KONIEC DEFINICJi/////////////////////////////////////////
#endif
