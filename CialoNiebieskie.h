
#ifndef CIALONIEBIESKIE_H_
#define CIALONIEBIESKIE_H_
#include<iostream>
#include<stdlib.h>
#include <string>



class CialoNiebieskie
{
private:
	double Masa;
	double Promien;
	std::string Nazwa;
	double PozycjaX;
	double PozycjaY;
	
public:
	CialoNiebieskie();

	double getPozycjaX();
	double getPozycjaY();
	double getMasa();
	double getPromien();
};

#endif /* CIALONIEBIESKIE_H_ */