#include "GwiazdaZdegradowana.h"

GwiazdaZdegradowana::GwiazdaZdegradowana()
{
	Nazwa[2] = { 'Z' };
	Nazwa[3] = { 'D' };
	Nazwa[4] = { '\0' };
	Promieniowanie = 12;
}

double GwiazdaZdegradowana::getPromieniowanie()
{
	
	return Promieniowanie;
}
