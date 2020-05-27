#pragma once
#include "Gwiazda.h"

class GwiazdaZdegradowana :
	public Gwiazda
{
private:
	double Promieniowanie;
public:
	GwiazdaZdegradowana();
	double getPromieniowanie();

};

