#pragma once
#include "Planeta.h"
class PlanetaSkalista :
	public Planeta
{
private:
	bool Woda;
	int SredniaTemp;
	double WspolczynnikKolonizacji;
public:
	double LiczWspolczynnikKolonizacji();
	int getSredniaTemp();
	bool getWoda();
	double getWspolczynnikKolonizacji();
};

