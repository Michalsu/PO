#pragma once
#include "CialoNiebieskie.h"

/// Planeta posiada swoj czas obiegu gwiazdy i grawitacje.

class Planeta :
	public CialoNiebieskie
{
private:
	int CzasObieguGwiazdy;
	double Grawitacja;

public:

    /// Funkcja zwraca grawitacje planety
	double getGrawitacja();

	/// Funkcja zwraca czas obiegu gwiazdy planety
	int getCzasObieguGwiazdy();
	
};

