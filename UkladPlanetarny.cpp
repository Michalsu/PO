#include "UkladPlanetarny.h"

#define _STALA_GRAWITACJI 6,6743015E-11

std::vector <GwiazdaZyjaca*> listaGwiazdZyjacych;
std::vector <GwiazdaZdegradowana*> listaGwiazdZdegradowanych;
std::vector <PlanetaSkalista*> listaPlanetSkalistych;
std::vector <PlanetaGazowa*> listaPlanetGazowych;
std::vector <Planetoida*> listaPlanetoid;




void PoliczPrzyspieszenie(CialoNiebieskie* Pi, CialoNiebieskie* Pj)
{
	double przyspieszenieGrawX=0, przyspieszenieOdsrodX=0, przyspieszenieGrawY=0, przyspieszenieOdsrodY=0;
	double odlegloscX = Pj->getPozycjaX() - Pi->getPozycjaX();
	if (odlegloscX != 0) {
		przyspieszenieGrawX = (_STALA_GRAWITACJI * Pj->getMasa() / (odlegloscX * odlegloscX));
		przyspieszenieOdsrodX = (Pi->getPredkoscX() * Pi->getPredkoscX()) / odlegloscX;
	}

	double odlegloscY = Pj->getPozycjaY() - Pi->getPozycjaY();
	if (odlegloscY != 0) {
		przyspieszenieGrawY = (_STALA_GRAWITACJI * Pj->getMasa() / (odlegloscY * odlegloscY));
		przyspieszenieOdsrodY = (Pi->getPredkoscY() * Pi->getPredkoscY()) / odlegloscY;
	}
	
	double przyspieszenieX = przyspieszenieGrawX + przyspieszenieOdsrodX;
	double przyspieszenieY = przyspieszenieGrawY + przyspieszenieOdsrodY;

	Pi->setPrzyspieszenieX(Pi->getPrzyspieszenieX() + przyspieszenieX);
	Pi->setPrzyspieszenieY(Pi->getPrzyspieszenieY() + przyspieszenieY);
}

//void UkladPlanetarny::InicjalizujListeCial(std::vector <std::vector<CialoNiebieskie*> > *pCiala)
//{
//	std::vector <GwiazdaZyjaca*> *listaGwiazdZyjacych;
//	std::vector <GwiazdaZdegradowana*> *listaGwiazdZdegradowanych;
//	std::vector <PlanetaSkalista*> *listaPlanetSkalistych;
//	std::vector <PlanetaGazowa*> *listaPlanetGazowych;
//	std::vector <Planetoida*> *listaPlanetoid;
//	for (int i = 0; i < 5; i++) {
//		CialoNiebieskie temp;
//		temp = static_cast<CialoNiebieskie*>(listaGwiazdZyjacych);
//		pCiala->push_back();
//	}
//}

void UkladPlanetarny::AktualizujPrzyspieszenie(std::vector<CialoNiebieskie*> &listaPlanet) {
	double przyspieszenieX = 0, przyspieszenieY = 0;

	for (int i = 0; i < listaPlanet.size(); i++) {
		listaPlanet[i]->setPrzyspieszenieX(0);
		listaPlanet[i]->setPrzyspieszenieY(0);
		for (int j = 0; j < listaPlanet.size(); j++) {
			if (i != j) {
				PoliczPrzyspieszenie(listaPlanet.at(i), listaPlanet.at(j));
			}
		}
		
	}

	
}

void UkladPlanetarny::AktualizujPredkosc(std::vector<CialoNiebieskie*>& listaPlanet) {
	for (int i = 0; i < listaPlanet.size(); i++) {
		listaPlanet.at(i)->setPredkoscX(listaPlanet.at(i)->getPredkoscX() + listaPlanet.at(i)->getPrzyspieszenieX());
		listaPlanet.at(i)->setPredkoscY(listaPlanet.at(i)->getPredkoscY() + listaPlanet.at(i)->getPrzyspieszenieY());
	}
}

void UkladPlanetarny::AktualizujPozycje(std::vector<CialoNiebieskie*>& listaPlanet) {
	for (int i = 0; i < listaPlanet.size(); i++) {
		listaPlanet.at(i)->setPozycjaX(listaPlanet.at(i)->getPozycjaX() + listaPlanet.at(i)->getPredkoscX());
		listaPlanet.at(i)->setPozycjaY(listaPlanet.at(i)->getPozycjaY() + listaPlanet.at(i)->getPredkoscY());
	}
}
////dzia³ajaca prymitywna wersja
// void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*> *ciala, unsigned int IloscPlanet, unsigned int IloscPlanetoid) {
//
//	for (int i = 0; i < IloscPlanet; i++) {
//		ciala->push_back(new Planeta());
//	}
//
//}

 void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*>* ciala, unsigned int IloscPlanetSkalistych, unsigned int IloscPlanetGazowych, unsigned int IloscPlanetoid) {

	 listaGwiazdZyjacych.push_back(new GwiazdaZyjaca());
	 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaGwiazdZyjacych.at(0)));
	 for (int i = 0; i < IloscPlanetSkalistych; i++) {
		 listaPlanetSkalistych.push_back(new PlanetaSkalista());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaPlanetSkalistych.at(i)));
	 }
	 for (int i = 0; i < IloscPlanetGazowych; i++) {
		 listaPlanetSkalistych.push_back(new PlanetaSkalista());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaPlanetSkalistych.at(i)));
	 }
	 for (int i = 0; i < IloscPlanetoid; i++) {
		 listaPlanetoid.push_back(new Planetoida());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaPlanetoid.at(i)));
	 }
		
 }



 