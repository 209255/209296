/*!
 * \file
 * \brief
 * Definicja klasy ListaArr1
 *
 * Plik zawiera definicję klasy ListaArr1 ujętej w szablon typu
 * wraz z jej składowymi metofdami.
 */

#include "InterfejsADT.hh"

/*!
 * \brief
 * Modeluje pojęcie Listy (array) 
 *
 * Modeluje pojęcie Listy opartej na dynamicznej tablicy.
 * Dodając elementy zwiększa tablicę o 1.
 */
template < class typ>
class ListArr1 : public InterfejsADT<typ> {

  /*!
   * \brief
   * Wkaźnik na dynamiczną tablicę
   *
   * Wskaźnik na dynamiczną tablicę tworzącą ListęArr1
   */
  typ *tab;

  /*!
   * \brief
   * Rozmiar tablicy
   *
   * Aktualny rozmiar tablicy.
   */
  unsigned int RozmiarT;

  /*!
   * \brief
   * Rozmiar Listy
   *
   * Aktualny rozmiar ListyArr1
   */
  unsigned int RozmiarL;

 public:

  /*!
   * \brief
   * Konstruktor bezarumentowy
   *
   * Kontruktor alokujący tablicę jednoelementową z której będzie
   * tworzona lista
   */
  ListArr1() {
    RozmiarT = 1;
    tab = new typ[RozmiarT];
    RozmiarL = 0;
  }

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
  void push (typ dana, unsigned int pole) {
    if(pole < 0 || pole > RozmiarL) {
      std::cerr << "Blad dodania elementu na ListArr1. Bledny nr pola. Zakres poprawnych wartosci pola: 0 - " << RozmiarL << std::endl;
    }
    else if(RozmiarL == 0) {
      tab[0] = dana;
      ++RozmiarL;
    }
    else {
      ++RozmiarT;
      typ *tymczasowy = new typ[RozmiarT];
      for (size_t i = 0; i < pole; ++i)
	tymczasowy[i] = tab[i];
      tymczasowy[pole] = dana;
      for (size_t i = (pole+1); i < RozmiarT; ++i)
	tymczasowy[i] = tab[i-1];
      delete[] tab;
      tab = tymczasowy;
      ++RozmiarL; 
    }
  }

  /*!
   * \brief
   * Pobiera element z ListyArr1
   *
   * Pobiera element z Listy Arr1 usuwając go z niej i zmniejszając rozmiar.
   *
   * param[in] - pole - nr pola z którgo chcemy pobrać element
   *
   * retval - zwraca wartosc pobranej danej lub '-1' w przyadku bledu
   */
  typ pop(unsigned int pole) {
    if(RozmiarL == 0) {
      std::cerr << "Blad! Nie mozna pobrac elementu z pustej listy!" << std::endl;
      return -1;
    }
    else if(pole < 0 || pole > (RozmiarL-1)) {
      std::cerr << "Blad pobrania elementu. Blednny nr pola. zakres popranwych wartosci pola: 0 - " << RozmiarL-1 << std::endl;
      return -1;
    }
    else {
      typ wartosc = tab[pole];
      typ *tymczasowy = new typ[RozmiarT-1];
      for (unsigned int i = 0; i < pole; i++) 
	tymczasowy[i] = tab[i];
      for (unsigned int i = (pole+1); i < (RozmiarT-1); i++)
	tymczasowy[i-1] = tab[i];
      delete[] tab;
      tab = tymczasowy;
      RozmiarT--; RozmiarL--;
      return wartosc;
    }
    std::cout << "Blad usuniecia z listy" << std::endl;
    return -1;
  }

  /*!
   * \brief
   * Wielkość listy
   *
   * Informuje o ilości elementów znajdujących się na LiścieArr1
   * 
   * \retval - zwraca liczbę elementów ListyArr1
   */
  unsigned int size() { return RozmiarL; } 

  /*!
   * \brief
   * Metoda testująca czas
   *
   * Metoda testująca czas wczytania n elementów na ListęArr1
   *
   * \param[in] k - ilość elementów do wczytania
   */
  void Start(const unsigned int k) {
    for (unsigned int i = 0; i < k; ++i)
      this -> push(3, this->RozmiarL);
}

  /*!
   * \brief
   * Wczytuje dane z pliku
   * 
   * Wczytuje dane z pliku do ListArr1
   *
   * param[in] nazwaPliku - nazwa pliku z danymi
   * param[in] n - ilość danych do wczytania, 0 oznacza wszystkie dane z pliku
   */
  void WczytajDane(const char *nazwaPliku, unsigned int n) {;}

  /*!
   * \brief
   * Zwalnia pamięć
   * 
   * Zwalnia pamięć zaalokowaną przez ListArr1
   */
  void Zwolnij() { 
    delete[] tab;
    RozmiarT=1;
    tab = new typ[RozmiarT];
    RozmiarL = 0;
  }
  


};

