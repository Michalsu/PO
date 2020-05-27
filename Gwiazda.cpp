#include "Gwiazda.h"




Gwiazda::Gwiazda()
{
	Nazwa[1] = { 'G' };
	Masa = ((double)rand() * double(1E20) / (double)RAND_MAX - 1E10);

	Temperatura = int(getPromien()*0.000007471428571428); // Przybli¿ona temperatura na podstawie aproksymacji liniowej znanych gwiazd T=R/700000000*5230 w Kelwinach
}

int Gwiazda::getTemperatura()
{
	return int(Temperatura);
}
