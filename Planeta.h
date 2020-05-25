#pragma once
#include "CialoNiebieskie.h"
class Planeta :
	public CialoNiebieskie
{
private:
	int CzasObieguGwiazdy;

	double Grawitacja;

public:
	double getGrawitacja();
	int getCzasObieguGwiazdy();
	
};

