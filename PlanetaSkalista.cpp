#include "PlanetaSkalista.h"
#include <time.h>


PlanetaSkalista::PlanetaSkalista() :Planeta()
{
	PozycjaX = -1E12 + ((long double)rand() / (long double)RAND_MAX * (1E12 - -1E12));
	PozycjaY = -1E12 + ((long double)rand() / (long double)RAND_MAX * (1E12 - -1E12));

	Nazwa[0] = { 'P' };
	Nazwa[1] = { 'S' };
	Nazwa[2] = { 'a' + rand() % 26 };
	Nazwa[3] = { 'a' + rand() % 26 };
	Nazwa[4] = { 'a' + rand() % 26 };
	Nazwa[5] = { '-'};
	Nazwa[6] = { 'a' + rand() % 26 };
	Nazwa[7] = { 'a' + rand() % 26 };
	Nazwa[8] = { '\0' };

	Promien = 2E5 + ((long double)rand() / (long double)RAND_MAX * (8E7 - 2E5));
	Masa = 3000.0 + ((long double)rand() / (long double)RAND_MAX * (7000.0 - 3000.0)) * 4/3 *3.14* Promien * Promien * Promien;

	WspolczynnikKolonizacji = 0;
	SredniaTemp = rand() % 100;
	int losowe = rand() % 100;
	if (losowe > 30 && losowe < 70) 
	{
		Woda = true;
	}
	if (Woda) 
	{
		WspolczynnikKolonizacji += 1000;
	}
	if (SredniaTemp >= 0 && SredniaTemp <= 100)
	{
		WspolczynnikKolonizacji += SredniaTemp;
	}
	
}


void PlanetaSkalista::wypiszdane(std::ofstream& wynik)
{
	wynik << "Nazwa Planety:" << Nazwa << std::endl << "Masa planety:" << Masa << std::endl <<
		"Promien planety:" << Promien << std::endl << "Srednia temperatura planety:" << SredniaTemp << std::endl <<
		"Wspolczynnik kolonizacji:" << WspolczynnikKolonizacji << std::endl <<std::endl;
		
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
