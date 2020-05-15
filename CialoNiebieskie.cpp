#include "CialoNiebieskie.h"

CialoNiebieskie::CialoNiebieskie() {
	Nazwa[12] = {'S'};
	Masa = rand();
	Promien = rand();


};


double* CialoNiebieskie::getPozycja()
{
	return nullptr;
}

double CialoNiebieskie::getMasa()
{
	return Masa;
}

double CialoNiebieskie::getPromien()
{
	return Promien;
}
