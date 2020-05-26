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

void UkladPlanetarny::AktualizujPrzyspieszenie(std::vector<CialoNiebieskie*> &listaCial) {
	double przyspieszenieX = 0, przyspieszenieY = 0;

	for (int i = 0; i < listaCial.size(); i++) {
		listaCial[i]->setPrzyspieszenieX(0);
		listaCial[i]->setPrzyspieszenieY(0);
		for (int j = 0; j < listaCial.size(); j++) {
			if (i != j) {
				PoliczPrzyspieszenie(listaCial.at(i), listaCial.at(j));
			}
		}
		
	}

	
}

void UkladPlanetarny::AktualizujPredkosc(std::vector<CialoNiebieskie*>& listaCial) {
	for (int i = 0; i < listaCial.size(); i++) {
		listaCial.at(i)->setPredkoscX(listaCial.at(i)->getPredkoscX() + listaCial.at(i)->getPrzyspieszenieX());
		listaCial.at(i)->setPredkoscY(listaCial.at(i)->getPredkoscY() + listaCial.at(i)->getPrzyspieszenieY());
	}
}

void UkladPlanetarny::AktualizujPozycje(std::vector<CialoNiebieskie*>& listaCial) {
	for (int i = 0; i < listaCial.size(); i++) {
		listaCial.at(i)->setPozycjaX(listaCial.at(i)->getPozycjaX() + listaCial.at(i)->getPredkoscX());
		listaCial.at(i)->setPozycjaY(listaCial.at(i)->getPozycjaY() + listaCial.at(i)->getPredkoscY());
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
		 listaPlanetGazowych.push_back(new PlanetaGazowa());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaPlanetSkalistych.at(i)));
	 }
	 for (int i = 0; i < IloscPlanetoid; i++) {
		 listaPlanetoid.push_back(new Planetoida());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaPlanetoid.at(i)));
	 }
		
 }

 void UkladPlanetarny::SprawdzKolizje(std::vector<CialoNiebieskie*>& listaCial,unsigned int& nObiektow)
 {
	 for (int i = 0; i < nObiektow; i++) {
		 for (int j = 0; j < nObiektow; j++) {
			 if (i != j) {

				 double odleglosc = sqrt((listaCial.at(i)->getPozycjaX() - listaCial.at(j)->getPozycjaX())* (listaCial.at(i)->getPozycjaX() - listaCial.at(j)->getPozycjaX()) + 
					 ( listaCial.at(i)->getPozycjaY() - listaCial.at(j)->getPozycjaY())* (listaCial.at(i)->getPozycjaY() - listaCial.at(j)->getPozycjaY()));
				
				 if (odleglosc < (listaCial.at(i)->getPromien() + listaCial.at(j)->getPromien())) {

					 std::cout << "Kolizja 2 cial" << std::endl;

					 if (listaCial.at(i)->getMasa() <= (listaCial.at(j)->getMasa() / 10)) {
						 delete listaCial[i];
						 listaCial.erase(listaCial.begin() + i);
						 std::cout << "cialo "<<i<<" zniszczone" << std::endl;
						 nObiektow-= 1;
						 if (i > 0) i--;
					 }
					 else if (listaCial.at(i)->getMasa() >= (listaCial.at(j)->getMasa() * 10)) {
						 delete listaCial[j];
						 listaCial.erase(listaCial.begin() + j);
						 std::cout << "cialo " << j << " zniszczone" << std::endl;
						 nObiektow -= 1;
						 if (j > 0) j--;
					 }
					 else {
						 delete listaCial[i];
						 delete listaCial[j];
						 listaCial.erase(listaCial.begin() + i);
						 listaCial.erase(listaCial.begin() + j);
						 std::cout << "cialo " << i << " i " << j << " zniszczone"<< std::endl;
						 nObiektow -= 2;
						 if (i > 0) i--;
						 if (i > 0) j--;
					 }
				 }
			 }
		 }

	 }
	 
 }

 void UkladPlanetarny::WypiszObiekty() {
	 std::cout << "Gwiazdy zyjace:" << listaGwiazdZyjacych.size() << std::endl;
	 std::cout << "Gwiazdy zdegradowane:" << listaGwiazdZdegradowanych.size() << std::endl;
	 std::cout << "Planety skaliste:" << listaPlanetSkalistych.size() << std::endl;
	 std::cout << "Planety gazowe:" << listaPlanetGazowych.size() << std::endl;
	 std::cout << "Planetoidy:" << listaPlanetoid.size() << std::endl;
	
 }



 