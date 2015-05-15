#ifndef IOBSERWOWANY_HH
#define IOBSERWOWANY_HH
#include <iostream>
#include "IObserwator.hh"

//****************************************************************************************
/*!
 *\file Interfejs dla obserwatora
 *
 * Plik zawiera definicje interfejsu dla klasy bedacej obiektem obserwowanym
 */
//****************************************************************************************

//****************************************************************************************
/*!
 *\brief Interfejs dla Obserwatora
 *
 * Klasa modeluje pojecie abstrakcyjnego interfejsu dla klasy bedacej obiektem
 * obserwowanym
 */
 //****************************************************************************************

/////////////////////////////////DEFINICJA KLASY//////////////////////////////////////////
class IObserwowany
{
protected:
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
  virtual void _DodajObserwator(IObserwator *O) = 0;
//****************************************************************************************
/*!
 *\brief Metoda usuwajaca obserwator
 *
 * Metoda ma za zadanei usunac zadanego poprzez argument obserwatora z listy
 * obserwatorow danego obiektu
 *
 *\param[in] O - wskaznik na obserwator,ktory ma zostac usuniety 
 */
  virtual void _UsunObserwator(IObserwator *O) = 0;
//****************************************************************************************
/*!
 *\brief Metoda informujaca obserwatorow
 *
 * Metoda ma za zadanie poinformowac wszystkich obserwatorow
 * o zmianach, ktore sa istotne dla nich,
 * jakie zostaly wykonane na obiekcie obserwowanym
 */
//****************************************************************************************
  virtual void _PowiadomObserwatorow()  = 0;
//****************************************************************************************
};
/////////////////////////////////KONEIC DEFINICJi//////////////////////////////////////////

#endif
