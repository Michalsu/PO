#include "CialoNiebieskie.h"
#include "Gwiazda.h"
#include "GwiazdaZdegradowana.h"
#include "GwiazdaZyjaca.h"
#include "Planeta.h"
#include "PlanetaGazowa.h"
#include "PlanetaSkalista.h"
#include "Planetoida.h"
#include "Vec2.h"


#include<iostream>
#include<stdlib.h>
#include <time.h>

int main()
{  char a;

 std::cout << "Solar systems" << std::endl;
 Gwiazda Slonce;
 std::cout << Slonce.getMasa() << std::endl << Slonce.getPromien() << std::endl << Slonce.getTemperatura() << std::endl;

 std::cin >> a;
 
	return 0;
}