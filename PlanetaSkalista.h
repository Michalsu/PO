#pragma once
#include "Planeta.h"

/// Planeta Skalista moze posiadac wode, ma swoja srednia temperature i wspolczynnik kolonizacji.

class PlanetaSkalista :
	public Planeta
{
private:

	bool Woda = false;
	int SredniaTemp;
	double WspolczynnikKolonizacji;
public:

	/// Konstruktor generujacy losowa nazwe planety i wlasciwe dla planet skalistych parametry.
	PlanetaSkalista();

	/// Funkca zwraca srednia temperature
	int getSredniaTemp();

	/// Funkcja zwraca informacje o tym czy na planecie jest woda
	bool getWoda();

	/// Funkcja zwraca wartosc wspolczynnika kolonizacji
	double getWspolczynnikKolonizacji();

	/// Funkcja wypisuje planety zdatne do kolonizacji do pliku tekstowego
	void wypiszdane(std::ofstream& wynik);
};

