
#ifndef CIALONIEBIESKIE_H_
#define CIALONIEBIESKIE_H_
#include<iostream>
#include<stdlib.h>
#include "Vec2.h"


class CialoNiebieskie
{
private:
	double Masa;
	double Promien;
	char Nazwa[32];
	Vec2 Pozycja;
	
public:
	CialoNiebieskie();

	Vec2 getPozycja();
	double getMasa();
	double getPromien();
};

#endif /* CIALONIEBIESKIE_H_ */