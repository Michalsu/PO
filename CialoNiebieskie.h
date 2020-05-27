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
	double PredkoscX;
	double PredkoscY;
	double PrzyspieszenieX;
	double PrzyspieszenieY;

	
public:
	CialoNiebieskie();
	CialoNiebieskie(char nazwa[32]);
	CialoNiebieskie(double masa, double promien);
	CialoNiebieskie(double masa, double promien, double pozycjax, double pozycjay);

	double getPozycjaX();
	double getPozycjaY();
	double getMasa();
	double getPromien();
	double getPredkoscX();
	double getPredkoscY();
	double getPrzyspieszenieX();
	double getPrzyspieszenieY();
	void setPozycjaX(double x);
	void setPozycjaY(double y);
	void setPrzyspieszenieX(double x);
	void setPrzyspieszenieY(double y);
	void setPredkoscX(double x);
	void setPredkoscY(double y);
	
};
