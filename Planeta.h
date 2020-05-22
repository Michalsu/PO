#pragma once
#include "CialoNiebieskie.h"
class Planeta :
	public CialoNiebieskie
{
private:
	int CzasObieguGwiazdy;
	double PredkoscX;
	double PredkoscY;
	double Grawitacja;
public:
	double getGrawitacja();
	double getPredkoscX();
	double getPredkoscY();
	int getCzasObieguGwiazdy();
};

