#pragma once
#include "Gwiazda.h"
class GwiazdaZyjaca :
	public Gwiazda
{
private:
	std::string TypGwiazdy;
public:
	std::string getTypGwiazdy();
};

