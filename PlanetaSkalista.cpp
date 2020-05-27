#include "PlanetaSkalista.h"

PlanetaSkalista::PlanetaSkalista() :Planeta()
{
	Nazwa[2] = { 'S' };
	Nazwa[3] = { '\0' };
	Masa = ((double)rand() * double(1E8) / (double)RAND_MAX - 1E4);
	if (rand() % 2) Woda = true;
	SredniaTemp = 100;
	WspolczynnikKolonizacji = 300;
		if (Woda) WspolczynnikKolonizacji += 1500;

}


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
	return Woda;
}

double PlanetaSkalista::getWspolczynnikKolonizacji()
{
	return WspolczynnikKolonizacji;
}
