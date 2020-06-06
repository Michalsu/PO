#pragma once
#include "Planeta.h"

/// Planeta gazowa moze posiadac takie pierwiastki jak wodor, tlen czy metan.

class PlanetaGazowa :
	public Planeta
{
private:
	bool Wodor;
	bool Tlen;
	bool Metan;
public:

	/// Wypisuje dane o planecie do pliku tekstowego
	void PlanetaGazowa::wypiszdane(std::ofstream& gazowe);

	/// Konstruktor generujacy losowa nazwe planety i wlasciwe dla planet gazowych parametry.
	PlanetaGazowa();

	/// Funkcja zwraca informacje o tym czy na planecie jest wodor
	bool getWodor();

	/// Funkcja zwraca informacje o tym czy na planecie jest tlen
	bool getTlen();

	/// Funkcja zwraca informacje o tym czy na planecie jest metan
	bool getMetan();
};

