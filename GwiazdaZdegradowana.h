#pragma once
#include "Gwiazda.h"

/// Gwiazda zdegradowana powstaje w wyniku ewolucji gwiazdy zyjacej. 
///
/// Dodatkowo posiada tez promieniowanie.

class GwiazdaZdegradowana :
	public Gwiazda
{
private:
	double Promieniowanie;
public:

	/// Konstruktor gwiazdy ustala jej pozycje, zawsze w srodku ukladu na miejsce gwiazdy zyjacej, losuje jej promieniowanie,
	/// mase i promien.
	GwiazdaZdegradowana();
	GwiazdaZdegradowana(long double masa, long double posX, long double posY, long double promien);

	/// Zwraca wartosc promieniowania
	double getPromieniowanie();

};

