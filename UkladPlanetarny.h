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
#include <list>
#include <vector>

class UkladPlanetarny
{
private:

	char NazwaUkladu[32];
	unsigned long long int czas;
	std::list <Gwiazda*> listaGwiazd;
	std::list <Planeta*> listaPlanet;
	std::list <Planetoida*> listaPlanetoid;


public:

};

