#pragma once
#include "CialoNiebieskie.h"
class Planetoida :
	public CialoNiebieskie
{
private:
	bool RzadkiePierwiastki;
	double PredkoscX;
	double PredkoscY;
public:
	double getPredkoscX();
	double getPredkoscY();
	bool getRzadkiePierwiastki();
};

