#include "Planeta.h"

Planeta::Planeta():CialoNiebieskie()
{
	Nazwa[1] = { 'P' };
	CzasObieguGwiazdy = 0;
	Grawitacja = 0;
}

double Planeta::getGrawitacja()
{
	return Grawitacja;
}



int Planeta::getCzasObieguGwiazdy()
{
	return CzasObieguGwiazdy;
}

