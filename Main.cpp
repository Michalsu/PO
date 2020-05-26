#include "UkladPlanetarny.h"
#include "Vec2.h"


#include<iostream>
#include<stdlib.h>
#include <time.h>

int main()
{  char a;
srand((unsigned)time(NULL));
 std::cout << "Solar systems" << std::endl;

 unsigned int nObiektow, nPlanetSkalistych=6, nPlanetGazowych=2, nPlanetoid=20;
 nObiektow = nPlanetSkalistych + nPlanetGazowych + nPlanetoid;

 std::vector<CialoNiebieskie*> listaCialNiebieskich;
 UkladPlanetarny uklad;
 uklad.StworzUklad(&listaCialNiebieskich,nPlanetSkalistych,nPlanetGazowych,nPlanetoid);
 
 for (int i = 0; i < 20; i++) {
     uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
     uklad.AktualizujPredkosc(listaCialNiebieskich);
     uklad.AktualizujPozycje(listaCialNiebieskich);
     for (int i = 0; i < nObiektow; i++)
     {
         std::cout << "O" << i + 1 << " pozycjaX " << listaCialNiebieskich[i]->getPozycjaX() << " pozycjaY " << listaCialNiebieskich[i]->getPozycjaY() <<
             " predkoscX " << listaCialNiebieskich[i]->getPredkoscX() << " PredkoscY " << listaCialNiebieskich[i]->getPredkoscY() <<
             "PrzyspieszenieX " << listaCialNiebieskich[i]->getPrzyspieszenieX() << "PrzyspieszenieY" << listaCialNiebieskich[i]->getPrzyspieszenieY() << std::endl;
     }
 }
 std::vector <std::vector<int> > Ciala;

 std::cin >> a;
 
	return 0;
}