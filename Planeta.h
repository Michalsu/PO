#pragma once
#include "CialoNiebieskie.h"
class Planeta :
	public CialoNiebieskie
{
private:
	int CzasObieguGwiazdy;
	double Grawitacja;

public:
	Planeta();
	double getGrawitacja();
	int getCzasObieguGwiazdy();
	
};

