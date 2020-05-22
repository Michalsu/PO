#include "UkladPlanetarny.h"
#include "Vec2.h"


#include<iostream>
#include<stdlib.h>
#include <time.h>

int main()
{  char a;

 std::cout << "Solar systems" << std::endl;
 GwiazdaZyjaca Slonce;
 std::cout << Slonce.getMasa() << std::endl << Slonce.getPromien() << std::endl << Slonce.getTemperatura() << std::endl;

 std::cin >> a;
 
	return 0;
}