#ifndef IOBSERWATOR_HH
#define IOBSERWATOR_HH

//********************************************************************************
/*!
 *\file Definicja interfejsu obserwatora
 * Plik zawiera definicje interfejsu dla klasy bedacej obserwatorem wraz z 
 * deklaracjami metod
 */
//********************************************************************************

//********************************************************************************
/*!
 *\brief Modeluje pojecie interfejsu dla obserwatora
 *
 * Klasa ta modeluje interfejs dla obiektu ktory bedzie 
 * obserwatorem
 */
////////////////////////////////DEFINICJA KLASY///////////////////////////////////
class IObserwator
{
public:
//********************************************************************************
/*!
 *\brief Metoda Aktualizujaca stan
 *
 * Metoda ma za zadanie poinformowac o zmianach w obiekcie ktory jest
 * obserwowany
 */
//********************************************************************************
  virtual void _Aktualizuj() = 0;
//********************************************************************************
};
////////////////////////////////KONIEC DEFINICJI///////////////////////////////////
#endif
