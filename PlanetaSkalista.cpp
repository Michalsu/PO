#include "PlanetaSkalista.h"

double PlanetaSkalista::LiczWspolczynnikKolonizacji()
{
	int temp;
	if (Woda) temp += 1500;
	if (SredniaTemp >= 240 && SredniaTemp <= 320) temp += 1000;
	return temp;
}

int PlanetaSkalista::getSredniaTemp()
{
	return SredniaTemp;
}

double PlanetaSkalista::getWspolczynnikKolonizacji()
{
	return WspolczynnikKolonizacji;
}
