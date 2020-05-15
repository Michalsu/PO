#include "CialoNiebieskie.h"

CialoNiebieskie::CialoNiebieskie() {
	Nazwa[12] = {'S'};
	Masa = rand();
	Promien = rand();
	Pozycja.x = rand();
	Pozycja.y = rand();


};




Vec2 CialoNiebieskie::getPozycja()
{
	return Vec2();
}

double CialoNiebieskie::getMasa()
{
	return Masa;
}

double CialoNiebieskie::getPromien()
{
	return Promien;
}
