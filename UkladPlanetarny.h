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

	void UkladPlanetarny::UsunZListy(int lp);
	void PoliczPredkoscOrbitalna(std::vector<CialoNiebieskie*>& listaCial, CialoNiebieskie* pCialo, int IleGwiazd);
	

	

public:
	//UkladPlanetarny();
	void UkladPlanetarny::wypiszplanety(std::ofstream& wynik);
	void UkladPlanetarny::InicjalizujListeCial(std::vector <std::vector<CialoNiebieskie*> > *pCiala);
	void UkladPlanetarny::AktualizujPrzyspieszenie(std::vector<CialoNiebieskie*>& listaCial);
	void UkladPlanetarny::AktualizujPredkosc(std::vector<CialoNiebieskie*>& listaCial, double Tempo);
	void UkladPlanetarny::AktualizujPozycje(std::vector<CialoNiebieskie*>& listaCial, double Tempo);
	void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*>* ciala, unsigned int IloscGwiazdZyjacych, unsigned int IloscPlanetSkalistych, unsigned int IloscPlanetGazowych, unsigned int IloscPlanetoid);
	
	void UkladPlanetarny::SprawdzKolizje(std::vector<CialoNiebieskie*>& listaCial, unsigned int& nObiektow, std::ofstream &zapis, int &liczbakolizji);
	void UkladPlanetarny::WypiszObiekty();
};

