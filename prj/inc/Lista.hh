#ifndef LISTA_HH
#define LISTA_HH

/*!
 * \file
 * \brief
 * Eefinicja klasy Lista
 *
 * Plik zawiera definicję klasy lista ujętej w szablon typu 
 * przchowywanych zmiennych więc zawiera też definicję metod klasy.
 */

#include "InterfejsADT.hh"
#include "Pliki.hh"

/*!
 * \brief
 * Modeluje pojęcie listy
 *
 * Modeluje pojęcie listy zadeklarowanego w szablonie typu
 * Uwaga! Listę indeksujemy od 0.
 */
template< class typ > 
class Lista : public InterfejsADT<typ> {

  /*! 
   * \brief
   * Modeluje jeden element Listy
   *
   * Modeluje jeden nierozłączny element listy - przechowywaną 
   * daną oraz wskaźnik na następny element;
   */
  struct Element {

    /*!
     * \brief
     * Wartosc Elementu
     * 
     * Wartość Elementu - przechowywanej wartości przez dany Element listy
     */
    typ wartosc;
    /*!
     * \brief
     * Wskaźnik na kolejny Element Listy
     * 
     * Wskaźnik na kolejny Element Listy
     */
    Element *nastepny;

    /*!
     * \brief
     * Konstruktor daną przekazywaną w argumencie
     *
     * Konstruktor zapisujący w Elemecie na końcu Listy daną podaną 
     * w argumencie i ustawiający wkaźnik na NULL
     *
     * \param[in] k - dana która ma zostać dodana na koniec Listy
     */  
    Element(typ k) {
      wartosc = k;
      nastepny = NULL;
    }
  };

    /*!
     * \brief
     * Wskaźnik na pierwszy element Listy
     *
     * Wskaźnik na pierwszy element Listy
     */
    Element *Poczatek;

    /*!
     * \brief
     * Wzkaźnik na ostatni element listy
     *
     * Wskaźnik na ostatni element listy
     */
    Element *Koniec;
    /*!
     * \brief
     * Aktualny rozmiar Listy
     *
     * Przechowuje aktualną ilość Elemenetów znajujących się na Liście
     */
    unsigned int Rozmiar;

public:

    /*!
     * \brief
     * Konstruktor puste listy
     *
     * Konstruktor bezargumentowy pustej listy
     * tworzy objekt z wskaźnikiem początek
     * pokazującym na NULL.
     */
  Lista() { Poczatek = NULL; Koniec = NULL; Rozmiar = 0; }

  /*!
   * \brief
   * Destruktor listy
   *
   * Zwalnia zaalokowana przez liste pamiec
   */ /*
  ~Lista() {
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
   * Zwalnia pamięć zajmowaną przez listę
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
     * Dodaje daną podaną jako pierwszy argument wywołania
     * na określone drugim argumentem miejsce w Liście
     *
     * \param[in] dana - dana którą chcemy dodać do listy
     * \param[in] pole - numer elementu listy na który chcemy
     *                   dodać daną (sieze() jeżeli na koniec)
     */
    void push(typ dana, unsigned int pole) {
      if(pole < 0 || pole > Rozmiar) {
	std::cerr << "Nie mozna dodac elementu! Bledny indeks. Mozesz uzyc indeksu z zakresu od 0 (poczatek) do " << Rozmiar << " (koniec)" << std::endl;
      }
      else if (Poczatek == NULL) { 
	Element *nowy = new Element(dana);
	Poczatek = nowy; Koniec = nowy;
	++Rozmiar;
      }
      else if(pole == 0) {
	Element *nowy = new Element(dana);
	nowy->nastepny = Poczatek;
	Poczatek = nowy;
	++Rozmiar;
      }
      else if(pole == (Rozmiar)) {
	Element *nowy = new Element(dana);
	nowy->nastepny = NULL;
	Koniec->nastepny = nowy;
	Koniec = nowy;
	++Rozmiar;
      }
      else {
	Element *nowy = new Element(dana);
	Element *indeksator = Poczatek;
	Element *tymczasowy;
	for(unsigned int i = 0; i<(pole-1); i++) 
	  indeksator = indeksator->nastepny;
	tymczasowy = indeksator->nastepny;
	indeksator->nastepny = nowy;
	nowy->nastepny = tymczasowy;
	++Rozmiar;
      }
    }

    /*!
     * \brief
     * Usuwa element z Listy
     *
     * Usuwa interesujący nas element z Listy.
     * Jeżeli chcesz usunąć pierwszy element wywołaj pole nr '0'.
     * Dla ostatniego elementu wywołaj pole nr 'Lista.size()-1'.
     *
     * \param[in] pole - numer elementu Listy z którego chcemy
     *                   pobrać daną
     *
     * \retval zwraca wartość danego elementu listy lub '-1' w przypadku błędu
     */
  typ pop(unsigned int pole) {
    if(pole < 0 || pole > Rozmiar) {
	std::cerr << "Nie mozna usunac! Bledny indeks. Mozesz uzyc indeksu z zakresu od 0 (poczatek) do " << Rozmiar-1 << " (koniec)" << std::endl;
	return -1;
      }
    else if(Rozmiar == 0) {
      std::cerr << "Nie mozna usunac elementow z pustej listy!!!!" << std::endl;
      return -1;
    }
    else if(pole == 0) {
      Element *tymczasowy = Poczatek->nastepny;
      typ wart = Poczatek -> wartosc;
      delete Poczatek;
      Poczatek = tymczasowy;
      Rozmiar--;
      return wart;
    }
    else if(pole == (Rozmiar-1)) {
      Element *indeksator = Poczatek; 
      typ wart = Koniec -> wartosc;
      for(unsigned int i = 0; i<(pole-1); i++)
	indeksator = indeksator -> nastepny;
      delete Koniec;
      Koniec = indeksator;
      Rozmiar--;
      return wart;
    }
    else {
      Element *indeksator = Poczatek;
      Element *tymczasowy;
      typ wart;
      for(unsigned int i = 0; i<(pole-1); i++)
	indeksator = indeksator -> nastepny;
      tymczasowy = indeksator -> nastepny;
      indeksator -> nastepny = tymczasowy -> nastepny;
      wart = tymczasowy -> wartosc;
      delete tymczasowy;
      Rozmiar--;
      return wart;
    }
}

    /*!
     * \brief
     * Sprawdza rozmiar Listy
     *
     * Sprawdza ile aktualnie elementów znajduję się na Liście
     *
     * \retval zwraca ilosć elementów znadjuących się aktualnie na liście
     */
  unsigned int size() { return Rozmiar; }

  /*!
   * \brief
   * Wczytuje dane z pliku
   *
   * Wczytuje dane zamieszczone w pliku do Listy. 
   * Każdą nową daną umieszcza na końcu listy.
   *
   * \param[in] nazwaPliku - nazwa pliku z danymi
   * \param[in] n - ilość danych do wczytania (domyślnie 0 - wysztkie 
   *                dane z pliku, zmiana wartości nie ma wpływu na działanie
   *                metody w aktualnej wersji
   */
  void WczytajDane(const char *nazwaPliku, unsigned int n=0) {
    std::fstream plik;
    typ wartosc;
    size_t i = 0;

    OtworzPlikIn(nazwaPliku, plik);
    while (!plik.eof()) {
      plik >> wartosc;
      if(plik.fail()) {
	std::cerr << "Blad wartosci pliku z danymi" << std::endl;
	exit (-4);
      }
      this -> push(wartosc, Rozmiar);
      ++i;
    }
    std::cout << "Wczytano " << i << " danych" << std::endl;
    plik.close();
  }

  /*!
   * \brief
   * Wyciąga wartość elementu Listy
   *
   * Wyłuskuje wartość danego elementu z Listy
   *
   * \param[in] pole - "indeks" z którego chcemy pobrać wartość
   *                    indeksujemy od 0!
   *
   * \retval - zwraca wartość elementu z danego pola lub '-1' w przypadku błedu
   */
  typ operator[] (size_t pole) const {
    if(pole < Rozmiar && pole >= 0) {
      Element *indeksator = Poczatek;
      for (size_t i = 0; i < pole; ++i)
	indeksator = indeksator -> nastepny;
      return indeksator -> wartosc;
    }
    return -1;
  }

  /*!
   * \brief
   * Proces obliczeniowy 
   *
   * Wykonuje proces oblcizeniowy, którego czas wykonania
   * jest mierzony na potrzeby laboratoriów PAMSI
   * W tym wypakdu tworzy Listę k elementową wypełnioną
   * stałą liczbą '3'.
   *
   * \param[in] k - ilość danych dla których ma zostać
   *                przeprowadzona precedura obnliczeniowa
   */
  void Start(const unsigned int k) {
    for(unsigned int i = 0; i < k; i++)
      this -> push(3, 0);
  }

};

#endif
