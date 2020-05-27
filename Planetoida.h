#pragma once
#include "CialoNiebieskie.h"
class Planetoida :
	public CialoNiebieskie
{
private:
	bool RzadkiePierwiastki;

public:
	Planetoida();
	bool getRzadkiePierwiastki();
};

