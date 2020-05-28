#include "GwiazdaZdegradowana.h"

GwiazdaZdegradowana::GwiazdaZdegradowana()
{
	Nazwa[2] = { 'Z' };
	Nazwa[3] = { 'D' };
	Nazwa[4] = { '\0' };
	Promieniowanie = 12;
	Promien = 5E8 + (long double)rand() / RAND_MAX * (1E10 - 5E8);
}

double GwiazdaZdegradowana::getPromieniowanie()
{
	
	return Promieniowanie;
}
