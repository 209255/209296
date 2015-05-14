#include "Wyniki.hh"

using namespace std;
//**************************************************************************
Wyniki::Wyniki(const unsigned int Powtorzen,const unsigned int Proby,
	       unsigned int *Rozmiary)
{
  _IloscProb = Proby;
  _IloscPowtorzen = Powtorzen;
  _TablicaWynikow = new long double[_IloscProb];
  _TablicaRozmiarow = new unsigned int[_IloscProb];
  
  for(unsigned int i = 0; i < _IloscProb; i++){
      _TablicaRozmiarow[i] = Rozmiary[i];}
}
//**************************************************************************
Wyniki::~Wyniki()
{
  delete [] _TablicaRozmiarow;
  delete [] _TablicaWynikow;
}
//**************************************************************************
void Wyniki::_ZapiszWyniki(std::string NazwaPlikWy)const
{
  fstream PlikWy;
  PlikWy.open(NazwaPlikWy.c_str(), ios::out|ios::trunc);
    {
      if(PlikWy.good())
	{
	  for(unsigned int i = 0; i < _IloscProb; ++i)
	    {
	      PlikWy << _TablicaRozmiarow[i] << " ";
	      PlikWy << _TablicaWynikow[i];
	      PlikWy << endl;
	    }
	  PlikWy.close();
	}
      else
	{
	  cerr << "Blad! Nie udalo sie utowrzyc pliku!" << endl;
	  exit(1);
	}
    }
}
//**************************************************************************
  void Wyniki::_Aktualizuj()
{
  static unsigned int LicznikPowt;
  static unsigned int LicznikProb;
  
  if(Stoper._StatusPracy() == false)
    {
      Stoper._RozpocznijPomiar();
      LicznikPowt++;
    }
  else
    {
      Stoper._ZakonczPomiar();
      Stoper._AktualizujCzas();
      if(LicznikPowt ==  _IloscPowtorzen)
	{
	  _TablicaWynikow[LicznikProb] =  (Stoper._CzasTrwania()
					   /_IloscPowtorzen);
	  LicznikProb++;
	  LicznikPowt = 0;
	  Stoper._Reset();
	}
     }
}
//**************************************************************************

