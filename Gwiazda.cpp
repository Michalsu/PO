#include "Gwiazda.h"




Gwiazda::Gwiazda()
{
	Temperatura = 12; //// Temperatura obliczana na podstawie promienia i masy gwiazdy
}

int Gwiazda::getTemperatura()
{
	return int(Temperatura);
}
