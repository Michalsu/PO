#include "Gwiazda.h"




Gwiazda::Gwiazda()
{
	Nazwa[1] = { 'G' };
	
	


	Temperatura = int(getPromien()*0.000007471428571428); // Przybli¿ona temperatura na podstawie aproksymacji liniowej znanych gwiazd T=R/700000000*5230 w Kelwinach
}

int Gwiazda::getTemperatura()
{
	return int(Temperatura);
}
