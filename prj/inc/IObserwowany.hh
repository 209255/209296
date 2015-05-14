#ifndef IOBSERWOWANY_HH
#define IOBSERWOWANY_HH
#include <iostream>
#include "IObserwator.hh"
/////////////////////////////////DEFINICJA KLASY//////////////////////////////////////////
class IObserwowany
{
protected:
//****************************************************************************************
  virtual void _DodajObserwator(IObserwator *O) = 0;
//****************************************************************************************
  virtual void _UsunObserwator(IObserwator *O) = 0;
//****************************************************************************************
  virtual void _PowiadomObserwatorow()  = 0;
//****************************************************************************************
};
/////////////////////////////////KONEIC DEFINICJi//////////////////////////////////////////

#endif
