#include "Gwiazda.h"




Gwiazda::Gwiazda()
{
	Nazwa[1] = { 'G' };
	Masa = ((double)rand() * double(1E22) / (double)RAND_MAX - 1E18);
	Promien = 5E8 + (double)rand() / RAND_MAX * (1E10 - 5E8);


	Temperatura = int(getPromien()*0.000007471428571428); // Przybli¿ona temperatura na podstawie aproksymacji liniowej znanych gwiazd T=R/700000000*5230 w Kelwinach
}

int Gwiazda::getTemperatura()
{
	return int(Temperatura);
}
