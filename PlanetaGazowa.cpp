#include "PlanetaGazowa.h"

PlanetaGazowa::PlanetaGazowa()
{
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
