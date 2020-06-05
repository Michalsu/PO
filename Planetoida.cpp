#include "Planetoida.h"




Planetoida::Planetoida()
{
	Nazwa[0] = { 'P' };
	Nazwa[1] = { 'L' };
	Nazwa[2] = { 'D' };
	Nazwa[3] = { 'a' + rand() % 26 };
	Nazwa[4] = { 'a' + rand() % 26 };
	Nazwa[5] = { 'a' + rand() % 26 };
	Nazwa[6] = { '-'};
	Nazwa[7] = { 'a' + rand() % 26 };
	Nazwa[8] = { 'a' + rand() % 26 };
	Nazwa[9] = { '\0' };
	Promien = 5E2  + ((long double)rand()/ (long double)RAND_MAX * (1E5 - 5E2));
	Masa = 3000.0 + ((long double)rand() / (long double)RAND_MAX * (7000.0 - 3000.0)) * 4 / 3 * 3.14 * Promien * Promien * Promien;
	if (rand() % 2) RzadkiePierwiastki = true;
}

bool Planetoida::getRzadkiePierwiastki()
{
	return RzadkiePierwiastki;
}

