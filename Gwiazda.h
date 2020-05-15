#pragma once
#include "CialoNiebieskie.h"
#include <iostream>
class Gwiazda :
	public CialoNiebieskie
{
private:
	int Temperatura;
	
public:
	Gwiazda();
	int getTemperatura();

};

