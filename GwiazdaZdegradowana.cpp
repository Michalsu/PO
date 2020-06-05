#include "GwiazdaZdegradowana.h"

GwiazdaZdegradowana::GwiazdaZdegradowana()
{
	PozycjaX = 0;
	PozycjaY = 0;
	Nazwa[2] = { 'Z' };
	Nazwa[3] = { 'D' };
	Nazwa[4] = { '\0' };
	Promieniowanie = rand() % 1 + 100;
	Masa = (((long double)rand() * 2500 / (long double)RAND_MAX - 1000) * 4 / 3 * 3.14 * Promien * Promien * Promien)/100;
	Promien = 5E8 + (long double)rand() / RAND_MAX * (1E10 - 5E8);
}

double GwiazdaZdegradowana::getPromieniowanie()
{
	
	return Promieniowanie;
}
