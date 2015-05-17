#ifndef STRUKTURYBENCHMARK_HH
#define STRUKTURYBENCHMARK_HH

#include "BenchmarkInterfejs.hh"
#include "ISortable.hh"
#include "IObserwowany.hh"
#include "IStruktury.hh"
//****************************************************************************************
/*!
 *\file Definicja Klasy StrukturyBenchmark
 *
 *Plik zawiera definicje klasy wraz z deklaracjami jej metod
 */
//****************************************************************************************

//****************************************************************************************
/*!
 * Klasa modeluje pojecie Benchmarku przeznaczonego dla struktur danych 
 * przechowujace dane
 */
//****************************************************************************************

////////////////////////////////DEFINICJA KLASY//////////////////////////////////////////
template <class Typ>
class StrukturyBenchmark: public BenchmarkInterfejs,public IObserwowany
{

private:
 
//****************************************************************************************
/*!
 *\brief Pole StrulturyBenchmark
 * Pole zawiera wskaźnik na interfejs sortujacy, 
 * za pomoca niego i metod wirtualnych beda wywolywane 
 * odpowiednie dla danej strktury metody
 */
//****************************************************************************************
  ISortable<Typ> *I;
//****************************************************************************************
/*!
 *\brief Pole StrulturyBenchmark
 * Pole zawiera wskaźnik na Struktury, za pomoca niego i metod wirtualnych beda wywolywane 
 * odpowiednie dla danej strktury metody
 */
//****************************************************************************************
  Struktury<Typ> *S;
//****************************************************************************************
/*!
 *\brief Pole StrulturyBenchmark
 * Pole zawiera wskaźnik na Iterable, za pomoca niego i metod wirtualnych beda wywolywane 
 * odpowiednie dla danej strktury metody
 */
//****************************************************************************************
  Iterable<Typ> *T;
//****************************************************************************************
/*!
 *\brief Pole StrkturyBenchmark
 *Pole zawiera wskaznik na typ calkowity, sluzy on do alokowania pamieci dla wczytanych 
 * z pliku danych
 */
//****************************************************************************************
  int * _Wartosci;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 *Pole zawiera liste obserwatorow,ktore obserwuja ten obiekt
 */
//****************************************************************************************
  std::list<IObserwator*> Obserwatorzy;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 * Pole zawiera informacje o ilosci prob jakie zostana wykonane
 */
//****************************************************************************************
  unsigned int _IloscProb;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 * Pole zawiera informacje o ilosci powtorzen jakie maja zosatc wykonane
 * przy tescie 
 */
//****************************************************************************************
  unsigned int _IloscPowt;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 * Pole zawiera wskaznik przechowujacy informcje dla jakiej ilosci danych
 * maja zostac wykonane testy
 */
//****************************************************************************************
  unsigned int *_TablicaRozmiarow;
//****************************************************************************************
/*!
 *\brief Pole StrukturyBenchmark
 *
 * Pole przechowuje informacje o ilosci testyowanych danych
 */
//****************************************************************************************
  unsigned int _IloscDanych;
//****************************************************************************************
/*!
 *\brief Metoda wykonujaca test dla odpowiedniej struktury
 *
 * Metoda ma za zadanie wykonac zapelnienie struktury danymi o zadanej w argumencie
 * ilosci 
 * \param[in] n - ilosc danych ktora zapelnona struktura 
 */
//****************************************************************************************
  void _Test() const
  {
    I -> _Sort(T);
  }
//****************************************************************************************
/*!
 *\brief Metoda wypelniajaca 
 *Metoda ma za zadanie wypelnic dany kontener danymi
 *
 *\param[in] n - ilosc danych 
 */
 //****************************************************************************************
  void _Zaladuj(const unsigned int n) const
  {
    for(unsigned int i = 0; i < n; ++i)
      S -> _Push(_Wartosci[i],S ->_Rozmiar());
  }
//**************************************************************************************** 
/*!
 *\brief Metoda zwalniajaca Pamiec
 *
 * Metoda ma za zadanie zwolnic pamiec przeznaczona na dane
 * przechowywane w kontenerze
 */
//**************************************************************************************** 
  void _Zwolnij(){S -> _Zwolnij();}
//**************************************************************************************** 
/*!
 *\brief Metoda informujaca obserwatorow
 *
 * Metoda ma za zadanie poinformowac wszystkich obserwatorow
 * o zmianach, ktore sa istotne dla nich,
 * jakie zostaly wykonane na obiekcie obserwowanym
 */
//****************************************************************************************
  void _PowiadomObserwatorow()
  {
    std::list<IObserwator *>::iterator it;
    for(it = Obserwatorzy.begin(); it != Obserwatorzy.end(); ++it)
      (*it) -> _Aktualizuj();
  }
//****************************************************************************************

public:
//****************************************************************************************
  StrukturyBenchmark()
  {
    _IloscProb = 0;
    _IloscPowt = 0;
    _TablicaRozmiarow = NULL;
    _IloscDanych = 0;
    _Wartosci = NULL;
    std::list<IObserwator *>::iterator it;
    for(it = Obserwatorzy.begin(); it != Obserwatorzy.end(); ++it)
      (*it) = NULL;
  }
//****************************************************************************************
  virtual ~StrukturyBenchmark()
  {
    delete[] _Wartosci;
    delete [] _TablicaRozmiarow;
    _Wartosci = NULL;
    _TablicaRozmiarow = NULL;

    std::list<IObserwator *>::iterator it;
    for(it = Obserwatorzy.begin(); it != Obserwatorzy.end(); ++it)
      (*it) = NULL;
    }
//****************************************************************************************
/*!
 *\brief Konstruktor obiektu
 *
 */
//****************************************************************************************
  StrukturyBenchmark(const unsigned int Proby,const unsigned int Powt,
		     unsigned int *Rozmiary)
  {
    _IloscProb = Proby;
    _IloscPowt = Powt;
    _TablicaRozmiarow = new unsigned int[_IloscProb];
    _IloscDanych = Rozmiary[_IloscProb-1];
    _Wartosci = new int[_IloscDanych];
    
    
    for(unsigned int i = 0; i < _IloscProb; ++i){
      _TablicaRozmiarow[i] = Rozmiary[i];}
    
    for (unsigned int i = 0; i < _IloscDanych; ++i){
      _Wartosci[i] = 0;
    }
  }
//****************************************************************************************
/*!
 *\brief Metoda inicjalizujaca test
 *
 * Metoda ma za zadanie uruchomic okreslona ilosc
 * razy testowana metode, czas jej wykonania jest zbierany
 * przez klase zewnetrzna
 */
//****************************************************************************************
  void _WykonajTest()
{
  for (unsigned int i = 0; i < _IloscProb; ++i)
    {
      for(unsigned int j = 0; j < _IloscPowt; ++j)
	{
	  this -> _Zaladuj(_TablicaRozmiarow[i]);
	  this -> _PowiadomObserwatorow();
	  this -> _Test();
	  this -> _PowiadomObserwatorow();
	  this -> _Zwolnij();
	}
    }
}
//****************************************************************************************
/*!
 *\brief Metoda Ustawiajaca
 *
 * Metoda ma za zadanie okreslic na jakich obiektach zostanie wykonana praca
 * poprzez przypisanie do wskaznikow abstrakcyjnych interfejsow obiektow, ktore posiadaja
 * dany interfejs
 */
//****************************************************************************************
  void _Ustaw(ISortable<Typ> *A,Struktury<Typ> *B,Iterable<Typ> *C){I = A,S = B,T = C;}
//****************************************************************************************
/*!\brief Metoda Wczytujaca dane
 *
 * Metoda ma za zadanie wczytac dane wejciowe o podanej przez 
 * argument nazwie oraz przypisac wskaznik do zaalokwanych w pamieci danych
 *
 *\param[in] PlikIn - nazwa pliku wejsciowego z danymi
 */
//****************************************************************************************
  void _Wczytaj(string PlikWart)
  {
    ifstream Plik_Wart;
    Typ Temp;
    Plik_Wart.open(PlikWart.c_str(),ios::in);

    if(!Plik_Wart)
      {
      std::cerr << "Blad przy otwieraniu Pliku: " 
		<< std::endl;exit(1);
      }
    else
      {
	for(unsigned int i = 0;i < _IloscDanych ; ++i)
	  {
	    Plik_Wart >> Temp;
	    if(Plik_Wart.eof())
	      {
		std::cout << "Napotkany EOF przed wczytaniem wszytskich danych"
			  << std::endl;
	      }
	    _Wartosci[i] = Temp;
	  }
      }
   }
//****************************************************************************************
/*!
 *\brief Metoda dodajaca obserwator
 *
 * Metoda ma za zadanie dodac nowego  obserwatora do listy
 * obserwatorow danego obiektu
 *
 *\param[in] O - wskaznik na dodawany obserwator
 */
//****************************************************************************************
  void _DodajObserwator(IObserwator *O)
  {
    Obserwatorzy.push_back(O);
  }
//****************************************************************************************
/*!
 *\brief Metoda usuwajaca obserwator
 *
 * Metoda ma za zadanei usunac zadanego poprzez argument obserwatora z listy
 * obserwatorow danego obiektu
 *
 *\param[in] O - wskaznik na obserwator,ktory ma zostac usuniety 
 */
//****************************************************************************************
  void _UsunObserwator(IObserwator *O)
  {
    Obserwatorzy.remove(O);
  }
//****************************************************************************************
/*!
 *\brief Metoda generujaca dane
 *
 * Metoda ma za zadanie wygenerowac pseudolosowe dane 
 * i zapisac je do pliku
 */
//****************************************************************************************
  void _Generator()const
{
  fstream PlikWy;
  srand(time (NULL));
  PlikWy.open("Dane.dat",ios::out);
  if(PlikWy.good())
    {
      for(unsigned int i = 0 ; i < _IloscDanych; ++i)
	PlikWy << rand() % 100 << endl;
    }
  else
    {
      cerr << "Blad utworzenia pliku!" << endl; exit(1);
    }
  PlikWy.close();

}
//****************************************************************************************
};
////////////////////////////////KONIEC DEFINICJI//////////////////////////////////////////
#endif
