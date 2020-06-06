#include "GwiazdaZyjaca.h"


GwiazdaZyjaca::GwiazdaZyjaca()
{
	TypGwiazdy[0] = { 'K' };
	PozycjaX = 0;
	PozycjaY = 0;
	Promien = 5E8 + (long double)rand() / RAND_MAX * (4E9 - 5E8);
	Masa = ((long double)rand() * 2500 / (long double)RAND_MAX - 1000) * 4 / 3 * 3.14 * Promien * Promien * Promien;
	if (Masa < 0) Masa = -Masa;
	Nazwa[0] = { 'Z' };
	Nazwa[1] = { 'Y' };
	Nazwa[2] = { 'a' + rand() % 26 };
	Nazwa[3] = { 'a' + rand() % 26 };
	Nazwa[4] = { 'a' + rand() % 26 };
	Nazwa[5] = { '-'};
	Nazwa[6] = { rand() % 9 };
	Nazwa[7] = { rand() % 9 };
	Nazwa[8] = { '\0' };
	Temperatura = int(getPromien() * 0.000007471428571428); // Przybli¿ona temperatura na podstawie aproksymacji liniowej znanych gwiazd T=R/700000000*5230 w Kelwinach
}

char* GwiazdaZyjaca::getTypGwiazdy()
{
	return TypGwiazdy;
}
