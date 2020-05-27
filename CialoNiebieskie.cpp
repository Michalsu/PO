#include "CialoNiebieskie.h"

CialoNiebieskie::CialoNiebieskie() {
	Nazwa[0] = {'S'};
	Masa = ((double)rand() * double(1E30) / (double)RAND_MAX - 1E10);
	Promien = ((double)rand() * double(7000 - 10) / (double)RAND_MAX - 10);
	PozycjaX = rand();
	PozycjaY = rand();
	PredkoscX = 0;
	PredkoscY = 0;
	PrzyspieszenieX = 0;
	PrzyspieszenieY = 0;

}
CialoNiebieskie::CialoNiebieskie(char nazwa[32])
{
	for (int i = 0; i < 31; i++) {
		Nazwa[i] = nazwa[i];

	}
	Nazwa[31] = '\0';
	PozycjaX = rand();
	PozycjaY = rand();
	PredkoscX = 0;
	PredkoscY = 0;
	PrzyspieszenieX = 0;
	PrzyspieszenieY = 0;
}
CialoNiebieskie::CialoNiebieskie(double masa, double promien)
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
CialoNiebieskie::CialoNiebieskie(double masa, double promien, double pozycjax, double pozycjay)
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





double CialoNiebieskie::getPozycjaX()
{
	return PozycjaX;
}
double CialoNiebieskie::getPozycjaY()
{
	return PozycjaY;
}

double CialoNiebieskie::getMasa()
{
	return Masa;
}

double CialoNiebieskie::getPromien()
{
	return Promien;
}

void CialoNiebieskie::setPozycjaX(double x)
{
	PozycjaX = x;
}

void CialoNiebieskie::setPozycjaY(double y)
{
	PozycjaY = y;
}

double CialoNiebieskie::getPredkoscX()
{
	return PredkoscX;
}

double CialoNiebieskie::getPredkoscY()
{
	return PredkoscY;
}
void CialoNiebieskie::setPrzyspieszenieX(double x)
{
	PrzyspieszenieX = x;
}

void CialoNiebieskie::setPrzyspieszenieY(double y)
{
	PrzyspieszenieY = y;
}

void CialoNiebieskie::setPredkoscX(double x)
{
	PredkoscX = x;
}

void CialoNiebieskie::setPredkoscY(double y)
{
	PredkoscY = y;
}

double CialoNiebieskie::getPrzyspieszenieX()
{
	return PrzyspieszenieX;
}

double CialoNiebieskie::getPrzyspieszenieY()
{
	return PrzyspieszenieY;
}
