#include "PlanetaGazowa.h"

PlanetaGazowa::PlanetaGazowa()
{
	Nazwa[2] = { 'G' };
	Nazwa[3] = { '\0' };
	Promien = 2E7 + ((double)rand() / (double)RAND_MAX * (1E8 - 2E7));
	Masa = 500.0 + ((double)rand() / (double)RAND_MAX * (2500.0 - 500.0))* 4 / 3 * 3.14 * Promien * Promien * Promien;
	if (rand() % 2) Wodor = true;
	if (rand() % 2) Tlen = true;
	if (rand() % 2) Metan = true;
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
