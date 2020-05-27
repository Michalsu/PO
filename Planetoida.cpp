#include "Planetoida.h"




Planetoida::Planetoida()
{
	if (rand() % 2) RzadkiePierwiastki = true;
}

bool Planetoida::getRzadkiePierwiastki()
{
	return RzadkiePierwiastki;
}

