#include "Planetoida.h"




Planetoida::Planetoida()
{
	Nazwa[1] = { 'P' };
	Nazwa[2] = { 'L' };
	Nazwa[3] = { 'D' };
	Nazwa[4] = { '\0' };
	if (rand() % 2) RzadkiePierwiastki = true;
}

bool Planetoida::getRzadkiePierwiastki()
{
	return RzadkiePierwiastki;
}

