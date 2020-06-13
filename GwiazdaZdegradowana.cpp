#include "GwiazdaZdegradowana.h"

GwiazdaZdegradowana::GwiazdaZdegradowana()
{
	PozycjaX = 0;
	PozycjaY = 0;
	Nazwa[0] = { 'Z' };
	Nazwa[1] = { 'D' };
	Nazwa[2] = { '\0' };
	Promieniowanie = rand() % 100;
	Masa = (((long double)rand() * 2500 / (long double)RAND_MAX - 1000) * 4 / 3 * 3.14 * Promien * Promien * Promien)/100;
	Promien = 5E8 + (long double)rand() / RAND_MAX * (1E10 - 5E8);
}

GwiazdaZdegradowana::GwiazdaZdegradowana(long double masa, long double posX, long double posY, long double promien)
{
	Masa = masa;
	PozycjaX = posX;
	PozycjaY = posY;
	Promien = promien;
	Promieniowanie = rand() % 100;
}

double GwiazdaZdegradowana::getPromieniowanie()
{
	
	return Promieniowanie;
}
