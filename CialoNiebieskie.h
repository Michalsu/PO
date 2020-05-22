#pragma once
#include<iostream>
#include<stdlib.h>

class CialoNiebieskie
{
private:
	double Masa;
	double Promien;
	char Nazwa[32];
	double PozycjaX;
	double PozycjaY;
	
public:
	CialoNiebieskie();

	double getPozycjaX();
	double getPozycjaY();
	double getMasa();
	double getPromien();
};
