#pragma once
#include "CialoNiebieskie.h"

class Gwiazda :
	public CialoNiebieskie
{
protected:
	int Temperatura;
	
public:
	Gwiazda();
	int getTemperatura();

};

