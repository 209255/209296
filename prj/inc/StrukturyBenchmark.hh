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
 * Pole zawiera wskaźnik na Struktury, za pomoca niego i metod wirtualnych beda wywolywane 
 * odpowiednie dla danej strktury metody
 */
//****************************************************************************************
  ISortable<Typ> *I;
//****************************************************************************************
  Struktury<Typ> *S;
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
  std::list<IObserwator*> Obserwatorzy;
//****************************************************************************************
  unsigned int _IloscProb;
//****************************************************************************************
  unsigned int _IloscPowt;
//****************************************************************************************
  unsigned int *_TablicaRozmiarow;
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
  void _Zaladuj(const unsigned int n) const
  {
    for(unsigned int i = 0; i < n; ++i)
      S -> _Push(_Wartosci[i],S ->_Rozmiar());
  }
//**************************************************************************************** 
  void _Zwolnij(){S -> _Zwolnij();}
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
  void _Ustaw(ISortable<Typ> *A,Struktury<Typ> *B,Iterable<Typ> *C){I = A,S = B,T = C;}
//****************************************************************************************
/*!\brief Metoda Wczytujaca dane
 *
 * Metoda ma za zadanie wczytac dane wejciowe o podanej przez 
 * argument nazwie oraz przypisac wskaznik do zaalokwanych w pamieci danych
 *
 *\param[in] PlikIn - nazwa pliku wejsciowego z danymi
 *\param[in] Ilosc - Ilosc danych jaka bedzie wczytywana
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
  void _DodajObserwator(IObserwator *O)
  {
    Obserwatorzy.push_back(O);
  }
//****************************************************************************************
  void _UsunObserwator(IObserwator *O)
  {
    Obserwatorzy.remove(O);
  }
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
