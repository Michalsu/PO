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
	void UkladPlanetarny::InicjalizujListeCial(std::vector <std::vector<CialoNiebieskie*> > *pCiala);
	void UkladPlanetarny::AktualizujPrzyspieszenie(std::vector<CialoNiebieskie*>& listaCial);
	void UkladPlanetarny::AktualizujPredkosc(std::vector<CialoNiebieskie*>& listaCial);
	void UkladPlanetarny::AktualizujPozycje(std::vector<CialoNiebieskie*>& listaCial);
	void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*>* ciala, unsigned int IloscPlanetSkalistych, unsigned int IloscPlanetGazowych, unsigned int IloscPlanetoid);
	void UkladPlanetarny::SprawdzKolizje(std::vector<CialoNiebieskie*>& listaCial, unsigned int& nObiektow);
	void UkladPlanetarny::WypiszObiekty();
};

