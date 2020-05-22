#include "PlanetaSkalista.h"

double PlanetaSkalista::LiczWspolczynnikKolonizacji()
{
	int temp=300;
	if (Woda) temp += 1500;
	if (SredniaTemp >= 240 && SredniaTemp <= 320) temp += 1000;
	return temp;
}

int PlanetaSkalista::getSredniaTemp()
{
	return SredniaTemp;
}

bool PlanetaSkalista::getWoda()
{
	return false;
}

double PlanetaSkalista::getWspolczynnikKolonizacji()
{
	return WspolczynnikKolonizacji;
}
