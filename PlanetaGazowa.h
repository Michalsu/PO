#pragma once
#include "Planeta.h"
class PlanetaGazowa :
	public Planeta
{
private:
	bool Wodor;
	bool Tlen;
	bool Metan;
public:
	bool getWodor();
	bool getTlen();
	bool getMetan();
};

