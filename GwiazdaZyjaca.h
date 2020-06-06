#pragma once
#include "Gwiazda.h"

/// Gwiazda zyjaca zawsze powstaje w srodku ukladu.
///
/// Dodatkowo posiada tez swoj typ.

class GwiazdaZyjaca :
	public Gwiazda
{
private:
	char TypGwiazdy[32];
public:

	/// Konstruktor gwiazdy ustala jej pozycje w srodku ukladu, generuje losowa nazwe, typ gwiazdy, oraz wlasciwa dla 
	/// gwiazd zyjacych promien, mase i temeprature. 
	GwiazdaZyjaca();

	/// Funkcja zwraca typ gwiazdy.
	char* getTypGwiazdy();
};

