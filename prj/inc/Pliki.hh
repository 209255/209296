/*!
 * \file
 * \brief
 * Funkcje obslugi plikow
 *
 * Plik zawiera deklaracje funkcji zwiazanych z obsuga plikow
 */
#ifndef PLIKI_HH
#define PLIKI_HH
#include <iostream>
#include <fstream>
#include <cstdlib>

/*!
 * \brief
 * Otwiera plik do odczytu
 *
 * Otwiera plik i sprawdza czy otwarcie sie powiodlo
 * jezeli nie to koczy program
 *
 * \param[in] nazwaPliku - nazwa pliku ktory chcemy otworzyc
 * \param[in] plik - strumien powiazany z plikiem
 */
void OtworzPlikIn(const char *nazwaPliku, std::fstream &plik);

/*!
 * \brief
 * Otwiera plik do zapisu czysząc jego zawartość
 *
 * Otwiera plik i sprawdza czy otwarcie sie powiodlo
 * jezeli nie to koczy program
 *
 * \param[in] nazwaPliku - nazwa pliku ktory chcemy otworzyc
 * \param[in] plik - strumien powiazany z plikiem
 */
void OtworzPlikOut(const char *nazwaPliku, std::fstream &plik);

/*!
 * \brief
 * Zapisuje n losowych liczb(int) do pliku
 *
 * Losuje n liczb z zakresu od 1 do podonago przez użytwkonika
 * następnie zapisuje wylosowane dane do pliku o nazwe "dane.dat"
 *
 * \param[in] n - ilość liczb do zapisania
 * \param[in] zakres - górny zakres wartości liczb
 */
void LosujIntDoPliku(const unsigned int n, const unsigned int zakres);


#endif
