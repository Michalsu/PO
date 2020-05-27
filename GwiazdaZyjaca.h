#pragma once
#include "Gwiazda.h"
class GwiazdaZyjaca :
	public Gwiazda
{
private:
	char TypGwiazdy[32];
public:
	GwiazdaZyjaca();
	char* getTypGwiazdy();
};

