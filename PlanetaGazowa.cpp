#include "PlanetaGazowa.h"

PlanetaGazowa::PlanetaGazowa()
{

	PozycjaX = -1E12 + ((long double)rand() / (long double)RAND_MAX * (1E12 - -1E12));
	PozycjaY = -1E12 + ((long double)rand() / (long double)RAND_MAX * (1E12 - -1E12));
	Nazwa[0] = { 'G' };
	Nazwa[1] = { 'a' + rand() % 26 };
	Nazwa[2] = { 'a' + rand() % 26 };
	Nazwa[3] = { 'a' + rand() % 26 };
	Nazwa[4] = { '-' };
	Nazwa[5] = { 'a' + rand() % 26 };
	Nazwa[6] = { 'a' + rand() % 26 };
	Nazwa[7] = { '\0' };
	Promien = 2E7 + ((long double)rand() / (long double)RAND_MAX * (5E8 - 2E7));
	Masa = 500.0 + ((long double)rand() / (long double)RAND_MAX * (2500.0 - 500.0))* 4 / 3 * 3.14 * Promien * Promien * Promien;
	Wodor = rand() % 2;
	Tlen = rand() % 2;
	Metan = rand() % 2;
}

void PlanetaGazowa::wypiszdane(std::ofstream& gazowe)
{
	gazowe << std::endl << std::endl << "Nazwa Planety: " << Nazwa << std::endl << "Masa planety: " << Masa << std::endl <<
		"Promien planety: " << Promien << std::endl <<
		"Wodor: "; if (Wodor) gazowe << "jest"; else gazowe << "brak"; gazowe << std::endl <<
		"Tlen: ";  if (Tlen) gazowe << "jest"; else gazowe << "brak"; gazowe << std::endl <<
		"Metan: ";  if (Metan) gazowe << "jest"; else gazowe <<"brak", gazowe << std::endl << std::endl;
}

bool PlanetaGazowa::getWodor()
{
	return Wodor;
}

bool PlanetaGazowa::getTlen()
{
	return Tlen;
}

bool PlanetaGazowa::getMetan()
{
	return Metan;
}
