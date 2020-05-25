#include "UkladPlanetarny.h"

#define _STALA_GRAWITACJI 6,6743015E-11
#define _PI        3.14159265358979323846

void PoliczPrzyspieszenie(CialoNiebieskie* Pi, CialoNiebieskie* Pj)
{
	
	double odlegloscX = Pj->getPozycjaX() - Pi->getPozycjaX();
	double odlegloscY = Pj->getPozycjaY() - Pi->getPozycjaY();
	double przyspieszenieGrawX = (_STALA_GRAWITACJI*Pj->getMasa()/(odlegloscX*odlegloscX));
	double przyspieszenieGrawY = (_STALA_GRAWITACJI * Pj->getMasa() / (odlegloscY * odlegloscY));
	double przyspieszenieOdsrodX = (Pi->getPredkoscX() * Pi->getPredkoscX()) / odlegloscX;
	double przyspieszenieOdsrodY = (Pi->getPredkoscY() * Pi->getPredkoscY()) / odlegloscY;
	
	double przyspieszenieX = przyspieszenieGrawX + przyspieszenieOdsrodX;
	double przyspieszenieY = przyspieszenieGrawY + przyspieszenieOdsrodY;

	Pi->setPrzyspieszenieX(Pi->getPrzyspieszenieX() + przyspieszenieX);
	Pi->setPrzyspieszenieY(Pi->getPrzyspieszenieY() + przyspieszenieY);
}

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

	


 void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*> *ciala, unsigned int IloscPlanet, unsigned int IloscPlanetoid) {

	for (int i = 0; i < IloscPlanet; i++) {
		ciala->push_back(new PlanetaSkalista());
	}

}

/*
void AktualizujPredkosc(std::vector <Planeta*> &listaPlanet, float TempoSymulacji) {
	for (int i=0; i<listaPlanet.size();i++)
	{
		double Odleglosc = listaPlanet[i]->getPozycjaX-listaPlanet.;
		Planeta::getPrzyspieszenieX += ;

	}

	}

	*/

 