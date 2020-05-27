#include "Planetoida.h"




Planetoida::Planetoida()
{
	Nazwa[1] = { 'P' };
	Nazwa[2] = { 'L' };
	Nazwa[3] = { 'D' };
	Nazwa[4] = { '\0' };
	Promien = 5E2  + ((double)rand()/ (double)RAND_MAX * (1E6 - 5E2));
	Masa = 3000.0 + ((double)rand() / (double)RAND_MAX * (7000.0 - 3000.0)) * 4 / 3 * 3.14 * Promien * Promien * Promien;
	if (rand() % 2) RzadkiePierwiastki = true;
}

bool Planetoida::getRzadkiePierwiastki()
{
	return RzadkiePierwiastki;
}

