#include "PlanetaSkalista.h"

PlanetaSkalista::PlanetaSkalista() :Planeta()
{
	Nazwa[2] = { 'S' };
	Nazwa[3] = { '\0' };
	Promien = ((double)rand() + 2E6 / (double)RAND_MAX * (1E7 - 2E6));
	Masa = 3000.0 + ((double)rand() / (double)RAND_MAX * (7000.0 - 3000.0)) * 4/3 *3.14* Promien * Promien * Promien;
	
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
