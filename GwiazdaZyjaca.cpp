#include "GwiazdaZyjaca.h"


GwiazdaZyjaca::GwiazdaZyjaca()
{
	PozycjaX = 0;
	PozycjaY = 0;
	Promien = 5E8 + (long double)rand() / RAND_MAX * (1E10 - 5E8);
	Masa = ((long double)rand() * 2500 / (long double)RAND_MAX - 1000) * 4 / 3 * 3.14 * Promien * Promien * Promien;
	Nazwa[2] = { 'Z' };
	Nazwa[3] = { 'Y' };
	Nazwa[4] = { '\0' };
}

char* GwiazdaZyjaca::getTypGwiazdy()
{
	
	
	return TypGwiazdy;
}
