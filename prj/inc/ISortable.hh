#ifndef ISORTABLE_HH
#define ISORTABLE_HH
#include "Iterable.hh"
template<class Typ>
class ISortable
{
public:
  virtual void _Sort(Iterable<Typ> *Kontener) = 0;
};
#endif
