#ifndef STOS_HH
#define STOS_HH

/*!
 * \file
 * \brief
 * Zawiera definicję Stosu
 *
 * Plik zawiera definicję klasy Stos, oraz definicję jej metod,
 * gdyż klasa ujęta jest w szablonie.
 */

#include "InterfejsADT.hh"

/*!
 * \brief
 * Modeluje pojęcie Stosu
 * 
 * Modeluje pojęcie Stosu.
 */
template < class typ >
class Stos : public InterfejsADT<typ> {
 /*! 
   * \brief
   * Modeluje jeden element Stosu
   *
   * Modeluje jeden nierozłączny element Stosu - przechowywaną 
   * daną oraz wskaźnik na następny element;
   */
  struct Element {

    /*!
     * \brief
     * Wartosc Elementu
     * 
     * Wartość Elementu - przechowywanej wartości przez dany Element Stosu
     */
    typ wartosc;
    /*!
     * \brief
     * Wskaźnik na kolejny Element Stosu
     * 
     * Wskaźnik na kolejny Element Stosu
     */
    Element *nastepny;

    /*!
     * \brief
     * Konstruktor daną przekazywaną w argumencie
     *
     * Konstruktor zapisujący w Elemecie na końcu Listy daną podaną 
     * w argumencie i ustawiający wkaźnik na NULL
     *
     * \param[in] k - dana która ma zostać dodana na koniec Stosu
     */  
    Element(typ k) {
      wartosc = k;
      nastepny = NULL;
    }
  };

    /*!
     * \brief
     * Wskaźnik na pierwszy element Stosu
     *
     * Wskaźnik na pierwszy element Stosu
     */
    Element *Poczatek;

    /*!
     * \brief
     * Aktualny rozmiar Stosu
     *
     * Przechowuje aktualną ilość Elemenetów znajujących się na Stosie
     */
    unsigned int Rozmiar;

public:

    /*!
     * \brief
     * Konstruktor pustego Stosu
     *
     * Konstruktor bezargumentowy pustego Stosu
     * tworzy objekt z wskaźnikiem początek
     * pokazującym na NULL.
     */
  Stos() { Poczatek = NULL; Rozmiar = 0; }

  /*!
   * \brief
   * Destruktor Stosu
   *
   * Zwalnia zaalokowana przez Stos pamiec
   */ /*
  ~Stos() {
   Element *next = Poczatek;
    std::cout << "destroy" << std::endl;
    for (unsigned int i = 0; i<(Rozmiar-1); i++) {
      next = next -> nastepny;
      delete Poczatek;
      Poczatek = next;
    }
    }*/

  /*!
   * \brief
   * Zwalnia pamięć
   *
   * Zwalnia pamięć zajmowaną przez Stos
   */
  void Zwolnij() {
    Element *next = Poczatek;
    for (unsigned int i = 0; i<(Rozmiar-1); i++) {
      next = next -> nastepny;
      delete Poczatek;
      Poczatek = next;
    }
      Rozmiar = 0;
  }
    /*!
     * \brief
     * Dodaje daną do Listy
     * 
     * Dodaje daną podaną jako argument wywołania
     *
     * \param[in] dana - dana którą chcemy dodać do Stosu
     * \param[in] pole - numer elementu Stosu na który chcemy
     *                   dodać daną, domyślnie - 0, zmiana argumentu wywołania
     *                   nie ma wpływu na działanie metody
     */
    void push(typ dana, unsigned int pole = 0) {
      pole = 0;
      if(pole == 0) {
	Element *nowy = new Element(dana);
	nowy->nastepny = Poczatek;
	Poczatek = nowy;
	Rozmiar++;
      }
    }

    /*!
     * \brief
     * Usuwa element ze Stosu
     *
     * Usuwa 'górny' element Stosu
     *
     * \param[in] pole - numer elementu Listy z którego chcemy
     *                   pobrać daną
     */
  void pop(unsigned int pole = 0) {
    if(pole < 0 || pole > Rozmiar) {
	std::cerr << "Nie mozna usunac! Bledny indeks. Mozesz uzyc indeksu z zakresu od 0 (poczatek) do " << Rozmiar-1 << " (koniec)" << std::endl;
      }
    else if(Rozmiar == 0) {
      std::cerr << "Nie mozna usunac elementow z pustej listy!!!!" << std::endl;
    }
    else if(pole == 0) {
      Element *tymczasowy = Poczatek->nastepny;
      delete Poczatek;
      Poczatek = tymczasowy;
      Rozmiar--;
    }
    else {
      std::cerr << "Blad usuniecia ze stosu! Zaleca sie pominiecie drugiego argumentu lub podanie wartosci 0" << std::endl;
    }
}

    /*!
     * \brief
     * Sprawdza rozmiar Stosu
     *
     * Sprawdza ile aktualnie elementów znajduję się na Stosie
     *
     * \retval zwraca ilosć elementów znadjuących się aktualnie na Stosie
     */
  unsigned int size() { return Rozmiar; }

  /*!
   * \brief
   * Wczytuje dane z pliku
   *
   * Wczytuje dane zamieszczone w pliku do Stosu. 
   * Każdą nową daną umieszcza na 'górze' Stosu.
   *
   * \param[in] nazwaPliku - nazwa pliku z danymi
   * \param[in] n - ilość danych do wczytania
   */
  void WczytajDane(const char *nazwaPliku, unsigned int n) {;}

  /*!
   * \brief
   * Proces obliczeniowy 
   *
   * Wykonuje proces oblcizeniowy, którego czas wykonania
   * jest mierzony na potrzeby laboratoriów PAMSI
   * W tym wypakdu tworzy Stos k elementowy wypełniony
   * stałą liczbą '3'.
   *
   * \param[in] k - ilość danych dla których ma zostać
   *                przeprowadzona precedura obnliczeniowa
   */
  void Start(const unsigned int k) {
    for(unsigned int i = 0; i < k; i++) 
      this -> push(3);
  }
};

#endif
