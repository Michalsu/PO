#include "UkladPlanetarny.h"
#include "Vec2.h"


#include<iostream>
#include<stdlib.h>
#include <time.h>

//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <thread>
//#include <chrono>

int main()
{  char a;
srand((unsigned)time(NULL));
 std::cout << "Solar systems" << std::endl;

 unsigned int nObiektow, nPlanetSkalistych=1, nPlanetGazowych=1, nPlanetoid=12;
 nObiektow = nPlanetSkalistych + nPlanetGazowych + nPlanetoid;

 std::vector<CialoNiebieskie*> listaCialNiebieskich;
 UkladPlanetarny uklad;
 uklad.StworzUklad(&listaCialNiebieskich,nPlanetSkalistych,nPlanetGazowych,nPlanetoid);

for (int i = 0; i < 20; i++) {
    uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
    uklad.AktualizujPredkosc(listaCialNiebieskich);
    uklad.AktualizujPozycje(listaCialNiebieskich);
    if (i > 0) uklad.SprawdzKolizje(listaCialNiebieskich, nObiektow);
        for (int i = 0; i < nObiektow; i++)
         {
            std::cout << "O" << i + 1 << " promien " << listaCialNiebieskich[i]->getPromien() << " masa " << listaCialNiebieskich[i]->getMasa() <<
                 " pozycjaX " << listaCialNiebieskich[i]->getPozycjaX() << " pozycjaY " << listaCialNiebieskich[i]->getPozycjaY() <<
                 " predkoscX " << listaCialNiebieskich[i]->getPredkoscX() << " PredkoscY " << listaCialNiebieskich[i]->getPredkoscY() <<
                 "PrzyspieszenieX " << listaCialNiebieskich[i]->getPrzyspieszenieX() << "PrzyspieszenieY" << listaCialNiebieskich[i]->getPrzyspieszenieY() << std::endl;
         }
         uklad.WypiszObiekty();
     
 }
 std::vector <std::vector<int> > Ciala;

 std::cin >> a;
 






	return 0;
}