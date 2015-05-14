#ifndef ITERABLE_HH
#define ITERABLE_HH
template<class Typ>
class Iterable
{
public:
  virtual const Typ Wartosc(unsigned int i)const = 0;
  virtual Typ & Adres(unsigned int i) = 0;
  virtual void _Zamien(unsigned int i,unsigned int j) = 0;
  virtual unsigned int _Rozmiar()const = 0;
};

#endif
