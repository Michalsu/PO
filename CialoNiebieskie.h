#pragma once
#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <string.h>

class CialoNiebieskie
{
protected:
	long double Masa;
	long double Promien;
	char Nazwa[32];
	long double PozycjaX;
	long double PozycjaY;
private:
	
	long double PredkoscX;
	long double PredkoscY;
	long double PrzyspieszenieX;
	long double PrzyspieszenieY;

	
public:
	CialoNiebieskie();
	CialoNiebieskie(long double masa, long double promien);
	CialoNiebieskie(long double masa, long double promien, long double pozycjax, long double pozycjay);

	long double getPozycjaX();
	long double getPozycjaY();
	long double getMasa();
	long double getPromien();
	long double getPredkoscX();
	long double getPredkoscY();
	long double getPrzyspieszenieX();
	long double getPrzyspieszenieY();
	char* getNazwa();
	void setPozycjaX(long double x);
	void setPozycjaY(long double y);
	void setPrzyspieszenieX(long double x);
	void setPrzyspieszenieY(long double y);
	void setPredkoscX(long double x);
	void setPredkoscY(long double y);
	
};
