#pragma once
#include "Gwiazda.h"
class GwiazdaZyjaca :
	public Gwiazda
{
private:
	char TypGwiazdy[];
public:
	char* getTypGwiazdy();
};

