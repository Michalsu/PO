#pragma once
#include "CialoNiebieskie.h"

class Gwiazda :
	public CialoNiebieskie
{
private:
	int Temperatura;
	
public:
	Gwiazda();
	int getTemperatura();

};

