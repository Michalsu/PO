#pragma once
#include "CialoNiebieskie.h"

/// Kazda gwiazda ma swoja temperature

class Gwiazda :
	public CialoNiebieskie
{
protected:
	int Temperatura;
	
public:

	/// Zwraca temperature gwiazdy
	int getTemperatura();

};

