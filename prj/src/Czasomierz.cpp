#include "Czasomierz.hh"
//********************************************************************
Czasomierz::Czasomierz()
{
  _Start = 0;
  _Koniec = 0;
  _Aktualny = 0;
  _Status = false;
}
//********************************************************************
void Czasomierz::_Reset()
{
  _Aktualny = 0;
  _Status = false;
 }
//********************************************************************
void Czasomierz::_RozpocznijPomiar()
{
  _Start = clock();
  _Status = true;
}
//********************************************************************
void Czasomierz::_ZakonczPomiar()
{
  _Koniec = clock();
  _Status = false;
}
//********************************************************************
void Czasomierz::_AktualizujCzas()
{
  _Aktualny += (_Koniec - _Start)/
    (double)(CLOCKS_PER_SEC / 1000);
}
//********************************************************************
long double Czasomierz::_CzasTrwania()const
{
  return _Aktualny;
}
//********************************************************************
bool Czasomierz::_StatusPracy()const
{
  return _Status;
}
//********************************************************************
double Czasomierz::_PojedynczyPomiar()const
{
  return (_Koniec - _Start)/
    (double)(CLOCKS_PER_SEC / 1000);
}
