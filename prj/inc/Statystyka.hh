#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>

/*!
 * \file
 * \brief
 * Zawiera definicję klasy Statystyka
 *
 * Zawiera definicję klasy Statystyka
 */

/*!
 * \brief
 * Modeluje pojęcie statystyki
 * 
 * Modeluje pojęcie statystyki, czyli średnich czasów wykonania
 * metody dla różnyuch wielkości prób.
 */

class Statystyka {

  /*!
   * \brief
   * Ilość prób
   *
   * Ilość prób do utworzenia statystyki
   */
  unsigned int IleProb;

  /*!
   * \brief
   * Tablica z rozmiarami prób
   * 
   * Wskaźnik na tablicę zawierającą wielkości danych prób.
   */
  unsigned int *Proba;

  /*!
   * \brief
   * Średni czas wykonania danej próby
   *
   * wskaźnik na tablica ze średnimi czasami wykonania kolejnych prób.
   */
  double *Czas;

public:

  /*!
   * \brief
   * Konstruktor z dwoma pramametrami
   *
   * Konstruktor z dwoma paramatremi tworzy dynamiczne tablice
   * przechowujące statystykę oraz wypełnia rozmiary prób.
   *
   * \param[in] iloscProb - liczbosc prob w ksperymencie
   * \param[in] proby - tablica z licznościami prób.
   */
  Statystyka(const unsigned int iloscProb, unsigned int *proby);

  /*!
   * \brief
   * Destruktor - zwaknia pamięć
   *
   * Zwalnia pamięć zaalokowaną na dynamiczne tablicy przechowujące statystykę.
   */
  ~Statystyka() {delete[] Czas; delete[] Proba;}

  /*!
   * \brief
   * Indeksuje tablicę czasową
   *
   * Zwraca referencję do i-tego indeksu tablicy czasowej.
   *
   * \param[in] i - indeks tablicy czasowej
   *
   * \retval Czas[i] referencja do wybranego indeksu
   */
  double& operator[] (unsigned int i) {return Czas[i];}

  /*!
   * \brief
   * Zapisuje statysykę do pliku
   *
   * Zapisuje statystystykę do pliku o nazwie "statystyka.dat". 
   * Pierwsza linia pliku to wielkości prób
   * druga to średnie czasy wykonania podane w ms;
   */
  void ZapiszStaty(std::string nazwaPliku);

};

#endif
