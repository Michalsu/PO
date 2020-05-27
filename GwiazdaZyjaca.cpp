#include "GwiazdaZyjaca.h"


GwiazdaZyjaca::GwiazdaZyjaca()
{
	
	Masa = ((double)rand() * 2500 / (double)RAND_MAX - 1000) * 4 / 3 * 3.14 * Promien * Promien * Promien;
	Nazwa[2] = { 'Z' };
	Nazwa[3] = { 'Y' };
	Nazwa[4] = { '\0' };
}

char* GwiazdaZyjaca::getTypGwiazdy()
{
	
	
	return TypGwiazdy;
}
