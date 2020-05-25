#include "UkladPlanetarny.h"
#include "Vec2.h"


#include<iostream>
#include<stdlib.h>
#include <time.h>

int main()
{  char a;
srand((unsigned)time(NULL));
 std::cout << "Solar systems" << std::endl;

 std::vector<CialoNiebieskie*> Uklad1;
 UkladPlanetarny uklad;
 uklad.StworzUklad(&Uklad1,4,12);
 
 for (int i = 0; i < 20; i++) {
     uklad.AktualizujPrzyspieszenie(Uklad1);
     uklad.AktualizujPredkosc(Uklad1);
     uklad.AktualizujPozycje(Uklad1);
     std::cout << "Planeta 1 predkoscX " << Uklad1[0]->getPredkoscX() << " PredkoscY " << Uklad1[0]->getPredkoscY() <<
         "PrzyspieszenieX "<< Uklad1[0]->getPrzyspieszenieX()<<"PrzyspieszenieY"<< Uklad1[0]->getPrzyspieszenieY()<< std::endl;
     std::cout << "Planeta 2 predkoscX " << Uklad1[1]->getPredkoscX() << " PredkoscY " << Uklad1[1]->getPredkoscY() <<
         "PrzyspieszenieX " << Uklad1[1]->getPrzyspieszenieX() << "PrzyspieszenieY" << Uklad1[1]->getPrzyspieszenieY() << std::endl;
     std::cout << "Planeta 3 predkoscX " << Uklad1[2]->getPredkoscX() << " PredkoscY " << Uklad1[2]->getPredkoscY() <<
         "PrzyspieszenieX " << Uklad1[2]->getPrzyspieszenieX() << "PrzyspieszenieY" << Uklad1[2]->getPrzyspieszenieY() << std::endl;
     std::cout << "Planeta 4 predkoscX " << Uklad1[3]->getPredkoscX() << " PredkoscY " << Uklad1[3]->getPredkoscY() <<
         "PrzyspieszenieX " << Uklad1[3]->getPrzyspieszenieX() << "PrzyspieszenieY" << Uklad1[3]->getPrzyspieszenieY() << std::endl;
}

 std::cin >> a;
 
	return 0;
}