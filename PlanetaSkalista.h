#pragma once
#include "Planeta.h"
class PlanetaSkalista :
	public Planeta
{
private:

	bool Woda = false;
	int SredniaTemp;
	double WspolczynnikKolonizacji;
public:
	PlanetaSkalista();
	void LiczWspolczynnikKolonizacji();
	int getSredniaTemp();
	bool getWoda();
	double getWspolczynnikKolonizacji();
	void wypiszdane(std::ofstream& wynik);
};

