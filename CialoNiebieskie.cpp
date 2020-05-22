#include "CialoNiebieskie.h"

CialoNiebieskie::CialoNiebieskie() {
	Nazwa[12] = {'S'};
	Masa = rand();
	Promien = 5000*rand() % 700000000;
	PozycjaX = rand();
	PozycjaY = rand();
};




double CialoNiebieskie::getPozycjaX()
{
	return PozycjaX;
}
double CialoNiebieskie::getPozycjaY()
{
	return PozycjaY;
}

double CialoNiebieskie::getMasa()
{
	return Masa;
}

double CialoNiebieskie::getPromien()
{
	return Promien;
}
