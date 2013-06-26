/**
* \file aghComplex.h
* \author Filip Pasternak
* \date 11.05.2013
* \version 1.0
* \brief Definicja klasy aghComplex do obsługi liczb zespolonych
*/
// -------------------------------------------------------------------------

#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H

// -------------------------------------------------------------------------
#include "aghInclude.h"
#include <iomanip>
#include <iostream>
using namespace std;

// -------------------------------------------------------------------------

/**
* \class aghComplex
* \author Filip Pasternak
* \date 11.05.2013
* \brief Definicja klasy aghComplex do obsługi liczb zespolonych
*/
class aghComplex{
	private:
		double Re;     ///< przechowuje wartość rzeczywistą liczby zespolonej
		double Im;     ///< przechowuje wartość urojoną liczby zespolonej
	public:
	
	     /// \brief Konstruktor domyślny klasy
		aghComplex();
		
		/// \brief Konstruktor klasy
		///
		/// \param rzeczywista - wartość rzeczywista do przypisania
		/// \param urojona - wartość urojona do przypisania
		aghComplex(double rzeczywista, double urojona);
		
		/// \breif Konstruktor kopiujący
		///
		/// \param &zespolona - referencja do obiektu źródłowego
		aghComplex(const aghComplex &zespolona);
		
		/// \brief Destruktor klasy
		~aghComplex();
		
		/// \brief Funkcja zaprzyjaźniona - przeładowanie operatora wypisania
		///
		/// \param &wyjscie - referencja do obiektu wyjściowego
		/// \param &zespolona - referencja do obiektu klasy do wypisania
		/// \return Zwraca referencję do obiektu wyjściowego
		friend ostream & operator<< (ostream &wyjscie, const aghComplex &zespolona);

          /// \brief Przeładowanie operatora dodawania
          ///
          /// \param skladnik - obiekt będący składnikiem sumy
          /// \return Zwracany obiekt klasy aghComplex
		aghComplex operator +(const aghComplex skladnik);
		
          /// \brief Przeładowanie operatora odejmowania
          ///
          /// \param skladnik - obiekt będący odjemnikiem
          /// \return Zwracany obiekt klasy aghComplex		
		aghComplex operator -(const aghComplex skladnik);
		
          /// \brief Przeładowanie operatora przypisania z sumą
          ///
          /// \param skladnik - obiekt będący składnikiem sumy
          /// \return Żadna wartość nie jest zwracana		
		void operator +=(const aghComplex skladnik);
		
          /// \brief Przeładowanie operatora przypisania z różnicą
          ///
          /// \param skladnik - obiekt będący odjemnikiem
          /// \return Żadna wartość nie jest zwracana	
		void operator -=(const aghComplex skladnik);
		
          /// \brief Przeładowanie operatora mnożenia
          ///
          /// \param skladnik - obiekt będący mnożnikiem
          /// \return Zwracany obiekt klasy aghComplex	
		aghComplex operator *(const aghComplex skladnik);
		
          /// \brief Przeładowanie operatora dzielenia
          ///
          /// \param skladnik - obiekt będący dzielnikiem
          /// \return Zwracany obiekt klasy aghComplex		
		aghComplex operator / (const aghComplex skladnik);
		
          /// \brief Przeładowanie operatora porównania(równoważności)
          ///
          /// \param skladnik - obiekt porównywany z obecnym
          /// \return Jeśli są sobie równe zwracana wartość TRUE. W przeciwnym razie - FALSE
		bool operator == (const aghComplex druga);
		
          /// \brief Przeładowanie operatora porównania(różności)
          ///
          /// \param skladnik - obiekt porównywany z obecnym
          /// \return Jeśli są różne zwracana wartość TRUE. W przeciwnym razie - FALSE
		bool operator != (const aghComplex druga);
		
          /// \brief Metoda ustawiająca wartość rzeczywistą liczby zespolonej
          ///
          /// \param _Re - wartość części rzeczywistej do przypisania
          /// \return Żadna wartość nie jest zwracana
		void setRe(double _Re){Re=_Re;}
		
          /// \brief Metoda ustawiająca wartość urojoną liczby zespolonej
          ///
          /// \param _Im - wartość części urojonej do przypisania
          /// \return Żadna wartość nie jest zwracana
		void setIm(double _Im){Im=_Im;}
		
          /// \brief Metoda do pobierania części rzeczywistej liczby zespolonej
          ///
          /// \return Wartość części rzeczywistej liczby zespolonej
		double getRe(){return Re;}

          /// \brief Metoda do pobierania części urojonej liczby zespolonej
          ///
          /// \return Wartość części urojonej liczby zespolonej
		double getIm(){return Im;}
};
#endif
