#pragma once
#include "CialoNiebieskie.h"
class Planeta :
	public CialoNiebieskie
{
private:
	int CzasObieguGwiazdy;
	double Predkosc[2];
	double Grawitacja;
public:
	double getGrawitacja();
	double* getPredkosc();
	int getCzasObieguGwiazdy();
};

