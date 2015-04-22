#ifndef KOLEJKA_HH
#define KOLEJKA_HH

/*!
 * \file
 * \brief
 * Definicja klasy Kolejka
 *
 * Plik zawiera definicję klasy Kolejka ujętej w szablon typu 
 * przchowywanych zmiennych więc zawiera też definicję metod klasy.
 */

#include "InterfejsADT.hh"
#include "Pliki.hh"
#include <ctime>

/*!
 * \brief
 * Modeluje pojęcie Kolejki
 *
 * Modeluje pojęcie Kolejki zadeklarowanego w szablonie typu
 * Uwaga! Kolejkę indeksujemy od 0.
 */
template< class typ > 
class Kolejka : public InterfejsADT<typ> {

  /*! 
   * \brief
   * Modeluje jeden element Kolejki
   *
   * Modeluje jeden nierozłączny element Kolejki - przechowywaną 
   * daną oraz wskaźnik na następny element;
   */
  struct Element {

    /*!
     * \brief
     * Wartosc Elementu
     * 
     * Wartość Elementu - przechowywanej wartości przez dany Element Kolejki
     */
    typ wartosc;
    /*!
     * \brief
     * Wskaźnik na kolejny Element Kolejki
     * 
     * Wskaźnik na kolejny Element Kolejki
     */
    Element *nastepny;

    /*!
     * \brief
     * Konstruktor daną przekazywaną w argumencie
     *
     * Konstruktor zapisujący w Elemecie na końcu Kolejki daną podaną 
     * w argumencie i ustawiający wkaźnik na NULL
     *
     * \param[in] k - dana która ma zostać dodana na koniec Kolejki
     */  
    Element(typ k) {
      wartosc = k;
      nastepny = NULL;
    }
  };

    /*!
     * \brief
     * Wskaźnik na pierwszy element Kolejki
     *
     * Wskaźnik na pierwszy element Kolejki
     */
    Element *Poczatek;

  /*!
   * \brief
   * Wskaźnik na ostatni element Kolejki
   *
   * Wskaźnik na ostatni element kolejki zwiększający szybkowść
   * dodawania danych na końcu
   */
  Element *Koniec;
    /*!
     * \brief
     * Aktualny rozmiar Kolejki
     *
     * Przechowuje aktualną ilość Elemenetów znajujących się w Kolejce
     */
    unsigned int Rozmiar;

public:

    /*!
     * \brief
     * Konstruktor pustej Kolejki
     *
     * Konstruktor bezargumentowy pustej Kolejki
     * tworzy objekt z wskaźnikiem początek
     * pokazującym na NULL.
     */
  Kolejka() { Poczatek = NULL; Koniec = NULL; Rozmiar = 0; }

  /*!
   * \brief
   * Destruktor Kolejki
   *
   * Zwalnia zaalokowana przez Kolejke pamiec
   */ /*
  ~Kolejka() {
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
   * Zwalnia pamięć zajmowaną przez Kolejkę
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
     * Dodaje daną do Kolejki
     * 
     * Dodaje daną podaną jako pierwszy argument wywołania
     * na koniec Kolejki
     * Uwaga! nie zmieniać drugiego argumentu wywołania!
     *
     * \param[in] dana - dana którą chcemy dodać do Kolejki
     * \param[in] pole - numer miejsca gdzie zostanie dodany element - 
     * domyślnie koniec koelejki, zmiana arumentu podczas wywowłania
     * nie wpływa na działanie metody.
     */
  void push(typ dana, unsigned int pole = 0) {
    pole = Rozmiar;
      if (Poczatek == NULL) { 
	Element *nowy = new Element(dana);
	Poczatek = nowy;
	Koniec = nowy;
	Rozmiar++;
      }
      else if(pole == (Rozmiar)) {
	Element *nowy = new Element(dana);
	Koniec -> nastepny = nowy;
	nowy->nastepny = NULL;
	Koniec = nowy;
	Rozmiar++;
      }
    }

    /*!
     * \brief
     * Usuwa element z Kolejki
     *
     * Usuwa pierwszy element z Kolejki
     * UWAGA! Nie zmieniać drugiego argumentu wywołania, bądź ustawoć 0!
     *
     * \param[in] pole - numer elementu w Kolejce którzy wyrzucimy,
     * domyślnie 0, zmiana podczas wywołania nie ma wpływu na działanie metody;
     */
  void pop(unsigned int pole = 0) {
    pole = 0;
    if(Rozmiar == 0) {
      std::cerr << "Nie mozna usunac elementow z pustej listy!!!!" << std::endl;
    }
    else if(pole == 0) {
      Element *tymczasowy = Poczatek->nastepny;
      delete Poczatek;
      Poczatek = tymczasowy;
      Rozmiar--;
    }
}

    /*!
     * \brief
     * Sprawdza rozmiar Kolejki
     *
     * Sprawdza ile aktualnie elementów znajduję się w Kolejce
     *
     * \retval zwraca ilosć elementów znadjuących się aktualnie w Kolejce
     */
  unsigned int size() { return Rozmiar; }

  /*!
   * \brief
   * Wczytuje dane z pliku
   *
   * Wczytuje dane zamieszczone w pliku do Kolejki. 
   * Każdą nową daną umieszcza na końcu Kolejki.
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
   * W tym wypakdu tworzy Kolejkę k elementową wypełnioną
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
