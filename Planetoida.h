#pragma once
#include "CialoNiebieskie.h"
class Planetoida :
	public CialoNiebieskie
{
private:
	bool RzadkiePierwiastki;
	double Predkosc[2];
public:
	double* getPredkosc();
	bool getRzadkiePierwiastki();
};

