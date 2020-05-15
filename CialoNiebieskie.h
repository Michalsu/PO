
#ifndef CIALONIEBIESKIE_H_
#define CIALONIEBIESKIE_H_
#include<iostream>
#include<stdlib.h>


class CialoNiebieskie
{
private:
	double Masa;
	double Promien;
	char Nazwa[32];
	double Pozycja[2] = {0, 0};
	
public:
	CialoNiebieskie();

	double* getPozycja();
	double getMasa();
	double getPromien();
};

#endif /* CIALONIEBIESKIE_H_ */