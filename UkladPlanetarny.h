#pragma once
#include "CialoNiebieskie.h"
#include "Gwiazda.h"
#include "GwiazdaZdegradowana.h"
#include "GwiazdaZyjaca.h"
#include "Planeta.h"
#include "PlanetaGazowa.h"
#include "PlanetaSkalista.h"
#include "Planetoida.h"

#include<iostream>
#include<stdlib.h>
#include <vector>
#include <cmath>

class UkladPlanetarny
{
private:

	char NazwaUkladu[32];
	unsigned long long int czas;
	std::vector <CialoNiebieskie*> listaCial;

	

public:
	void UkladPlanetarny::AktualizujPrzyspieszenie(std::vector<CialoNiebieskie*>& listaPlanet);
	void UkladPlanetarny::AktualizujPredkosc(std::vector<CialoNiebieskie*>& listaPlanet);
	void UkladPlanetarny::AktualizujPozycje(std::vector<CialoNiebieskie*>& listaPlanet);
	void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*>* ciala, unsigned int IloscPlanet, unsigned int IloscPlanetoid);
};

