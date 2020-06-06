#include "CialoNiebieskie.h"

CialoNiebieskie::CialoNiebieskie() {
	Nazwa[0] = { 'C' };
	Masa = ((long double)rand() + 1E5 / (long double)RAND_MAX * (1E8 - 1E5));
	Promien = 10000;
	PozycjaX = -1E12 + ((long double)rand() / (long double)RAND_MAX * (1E12 - -1E12));
	PozycjaY = -1E12 + ((long double)rand() / (long double)RAND_MAX * (1E12 - -1E12));
	PredkoscX = 0;
	PredkoscY = 0;
	PrzyspieszenieX = 0;
	PrzyspieszenieY = 0;

}
CialoNiebieskie::CialoNiebieskie(long double masa, long double promien)
{
	Nazwa[0] = { 'S' };
	Masa = masa;
	Promien = promien;
	PozycjaX = rand();
	PozycjaY = rand();
	PredkoscX = 0;
	PredkoscY = 0;
	PrzyspieszenieX = 0;
	PrzyspieszenieY = 0;

}
CialoNiebieskie::CialoNiebieskie(long double masa, long double promien, long double pozycjax, long double pozycjay)
{
	Nazwa[0] = { 'S' };
	Masa = masa;
	Promien = promien;
	PozycjaX = pozycjax;
	PozycjaY = pozycjay;
	PredkoscX = 0;
	PredkoscY = 0;
	PrzyspieszenieX = 0;
	PrzyspieszenieY = 0;
}
;


long double CialoNiebieskie::getPozycjaX()
{
	return PozycjaX;
}
long double CialoNiebieskie::getPozycjaY()
{
	return PozycjaY;
}

long double CialoNiebieskie::getMasa()
{
	return Masa;
}

long double CialoNiebieskie::getPromien()
{
	return Promien;
}

void CialoNiebieskie::setPozycjaX(long double x)
{
	PozycjaX = x;
}

void CialoNiebieskie::setPozycjaY(long double y)
{
	PozycjaY = y;
}

long double CialoNiebieskie::getPredkoscX()
{
	return PredkoscX;
}

long double CialoNiebieskie::getPredkoscY()
{
	return PredkoscY;
}
void CialoNiebieskie::setPrzyspieszenieX(long double x)
{
	PrzyspieszenieX = x;
}

void CialoNiebieskie::setPrzyspieszenieY(long double y)
{
	PrzyspieszenieY = y;
}

void CialoNiebieskie::setPredkoscX(long double x)
{
	PredkoscX = x;
}

void CialoNiebieskie::setPredkoscY(long double y)
{
	PredkoscY = y;
}

long double CialoNiebieskie::getPrzyspieszenieX()
{
	return PrzyspieszenieX;
}

long double CialoNiebieskie::getPrzyspieszenieY()
{
	return PrzyspieszenieY;
}

char* CialoNiebieskie::getNazwa()
{
	return Nazwa;
}
