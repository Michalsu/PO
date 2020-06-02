#include "UkladPlanetarny.h"

#define _STALA_GRAWITACJI 6,6743015E-11
#define _PREDKOSC_SWIATLA 299792458

std::vector <GwiazdaZyjaca*> listaGwiazdZyjacych;
std::vector <GwiazdaZdegradowana*> listaGwiazdZdegradowanych;
std::vector <PlanetaSkalista*> listaPlanetSkalistych;
std::vector <PlanetaGazowa*> listaPlanetGazowych;
std::vector <Planetoida*> listaPlanetoid;
std::vector <CialoNiebieskie*> listaCialNiebieskich;
float tempCzas = 0;

#include <fstream>


//UkladPlanetarny::UkladPlanetarny()
//{
//	std::cout << "Podaj nazwe ukladu";
//	std::cin >> NazwaUkladu;
//
//	std::cout << std::endl << "Podaj liczbe symulowanych lat"; // tu trzeba b�dzie dobra� odpowiedni� pr�dko�� symulacji
//	std::cin >> czas;
//
//	std::cout << std::endl << "Podaj poczatkowa liczbe planet skalistych w ukladzie:";
//	std::cin >> nPlanetSkalistych;
//
//	std::cout << std::endl << "Podaj poczatkowa liczbe planet gazowych w ukladzie:";
//	std::cin >> nPlanetGazowych; 
//
//	nObiektow = nGwiazdZyjacych + nPlanetSkalistych + nPlanetGazowych + nPlanetoid;
//
//	UkladPlanetarny uklad;
//
//	uklad.StworzUklad(&listaCialNiebieskich, nGwiazdZyjacych, nPlanetSkalistych, nPlanetGazowych, nPlanetoid);
//	std::ofstream zapis;
//	zapis.open("zapisprzebiegusymulacji.txt");
//	for (int i = 0; i < czas; i++)
//	{
//		uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
//		uklad.AktualizujPredkosc(listaCialNiebieskich, TempoSymulacji);
//		uklad.AktualizujPozycje(listaCialNiebieskich, TempoSymulacji);
//		uklad.SprawdzKolizje(listaCialNiebieskich, nObiektow);
//
//
//		for (int i = 0; i < nObiektow; i++)
//		{
//			zapis << "O" << i + 1 << " promien " << listaCialNiebieskich[i]->getPromien() << std::endl
//				<< " masa " << listaCialNiebieskich[i]->getMasa() << std::endl <<
//				" pozycjaX " << listaCialNiebieskich[i]->getPozycjaX() << std::endl <<
//				" pozycjaY " << listaCialNiebieskich[i]->getPozycjaY() << std::endl <<
//				" predkoscX " << listaCialNiebieskich[i]->getPredkoscX() << std::endl <<
//				" PredkoscY " << listaCialNiebieskich[i]->getPredkoscY() << std::endl <<
//				"PrzyspieszenieX " << listaCialNiebieskich[i]->getPrzyspieszenieX() << std::endl <<
//				"PrzyspieszenieY" << listaCialNiebieskich[i]->getPrzyspieszenieY() << std::endl;
//		}
//	}
//	zapis.close();
//	system("cls");
//	std::cout << "Wyniki symulacji:" << std::endl;
//	uklad.WypiszObiekty();
//	std::cout << std::endl << "Przebieg symulacji znajdziesz w pliku txt";
//
//}

void UkladPlanetarny::wypiszplanety(std::ofstream &wynik)
{
	int liczbaplanet = 0;
	for (int i = 0; i < listaPlanetSkalistych.size(); i++)
	{
		listaPlanetSkalistych.at(i)->LiczWspolczynnikKolonizacji();
		if((listaPlanetSkalistych.at(i)->getWspolczynnikKolonizacji()) >= 1500)
		{
			liczbaplanet++;
		}
		
	}
	wynik << std::endl
		<< "Oto liczba planet zdatnych do kolonizacji przez czlowieka: (tutaj beda dane tych planet i opcja nazwania)" <<
		std::endl << liczbaplanet;
}

void PoliczPrzyspieszenie(CialoNiebieskie* Pi, CialoNiebieskie* Pj)
{
	long double przyspieszenieGrawX=0, przyspieszenieGrawY=0;
	long double odlegloscX = Pj->getPozycjaX() - Pi->getPozycjaX();
	long double odlegloscY = Pj->getPozycjaY() - Pi->getPozycjaY();
	long double odleglosc = sqrt(odlegloscX * odlegloscX + odlegloscY * odlegloscY);
	if (odlegloscX < -1E3 || odlegloscX > 1E3) {
		przyspieszenieGrawX = (_STALA_GRAWITACJI * Pj->getMasa() *odlegloscX/ (odleglosc * odleglosc* odleglosc));
	}

	
	if (odlegloscY < -1E3 || odlegloscY > 1E3) {
		przyspieszenieGrawY = (_STALA_GRAWITACJI * Pj->getMasa() * odlegloscY / (odleglosc * odleglosc * odleglosc));
	}
	
	long double przyspieszenieX = przyspieszenieGrawX;
	long double przyspieszenieY = przyspieszenieGrawY;
	Pi->setPrzyspieszenieX(Pi->getPrzyspieszenieX() + przyspieszenieX);
	Pi->setPrzyspieszenieY(Pi->getPrzyspieszenieY() + przyspieszenieY);
	
}



void UkladPlanetarny::UsunZListy(int lp)
{
	if (lp < listaGwiazdZyjacych.size()) {
		listaGwiazdZyjacych.erase(listaGwiazdZyjacych.begin() + lp);
	}
	else lp -= listaGwiazdZyjacych.size();

	if (lp < listaGwiazdZdegradowanych.size()) {
		listaGwiazdZdegradowanych.erase(listaGwiazdZdegradowanych.begin() + lp);
	}
	else lp -= listaGwiazdZdegradowanych.size();

	if (lp < listaPlanetSkalistych.size()) {
		listaPlanetSkalistych.erase(listaPlanetSkalistych.begin() + lp);
	}
	else lp -= listaPlanetSkalistych.size();
	if (lp < listaPlanetGazowych.size()) {
		listaPlanetGazowych.erase(listaPlanetGazowych.begin() + lp);
	}
	else lp -= listaPlanetGazowych.size();

	if (lp < listaPlanetoid.size()) {
		listaPlanetoid.erase(listaPlanetoid.begin() + lp);
	}
}

void UkladPlanetarny::PoliczPredkoscOrbitalna(std::vector<CialoNiebieskie*>& listaCial, CialoNiebieskie* pCialo, int IleGwiazd)
{
	long double SrodekUkladuX=0, SrodekUkladuY=0; //srodek ciezkosci gwiazd
	long double MasaSrodkaUkladu=1; //masa gwiazd
	long double PredkoscOrbitalna, PredkoscOrbitalnaX, PredkoscOrbitalnaY;
	long double odlegloscX, odlegloscY, odleglosc;
	//dla 1 gwiazdy
	if (IleGwiazd == 1) {
		SrodekUkladuX = listaCial.at(0)->getPozycjaX();
		SrodekUkladuY = listaCial.at(0)->getPozycjaY();
		MasaSrodkaUkladu = listaCial.at(0)->getMasa();
	}
	// dla kilku gwiazd 
	else {

	/*
	
	
	*/
	}
	odlegloscX = pCialo->getPozycjaX() - SrodekUkladuX;
	odlegloscY = pCialo->getPozycjaY() - SrodekUkladuY;
	odleglosc = sqrt(odlegloscX* odlegloscX+ odlegloscY * odlegloscY);
	PredkoscOrbitalna = sqrt(( _STALA_GRAWITACJI * MasaSrodkaUkladu / odleglosc));
	PredkoscOrbitalnaX = -PredkoscOrbitalna * odlegloscY / odleglosc;
	PredkoscOrbitalnaY =  PredkoscOrbitalna * odlegloscX / odleglosc;

	pCialo->setPredkoscX(PredkoscOrbitalnaX);
	pCialo->setPredkoscY(PredkoscOrbitalnaY);
}

void UkladPlanetarny::AktualizujPrzyspieszenie(std::vector<CialoNiebieskie*> &listaCial) {
	long double przyspieszenieX = 0, przyspieszenieY = 0;

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

void UkladPlanetarny::AktualizujPredkosc(std::vector<CialoNiebieskie*>& listaCial, double Tempo) {
	for (int i = 0; i < listaCial.size(); i++) {
		listaCial.at(i)->setPredkoscX(listaCial.at(i)->getPredkoscX() + listaCial.at(i)->getPrzyspieszenieX() * Tempo);
		listaCial.at(i)->setPredkoscY(listaCial.at(i)->getPredkoscY() + listaCial.at(i)->getPrzyspieszenieY() * Tempo);
	}
}

void UkladPlanetarny::AktualizujPozycje(std::vector<CialoNiebieskie*>& listaCial, double Tempo) {
	for (int i = 0; i < listaCial.size(); i++) {
		listaCial.at(i)->setPozycjaX(listaCial.at(i)->getPozycjaX() + listaCial.at(i)->getPredkoscX() * Tempo);
		listaCial.at(i)->setPozycjaY(listaCial.at(i)->getPozycjaY() + listaCial.at(i)->getPredkoscY() * Tempo);
	}
}
////dzia�ajaca prymitywna wersja
// void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*> *ciala, unsigned int IloscPlanet, unsigned int IloscPlanetoid) {
//
//	for (int i = 0; i < IloscPlanet; i++) {
//		ciala->push_back(new Planeta());
//	}
//
//}

 void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*>* ciala, unsigned int IloscGwiazdZyjacych, unsigned int IloscPlanetSkalistych, unsigned int IloscPlanetGazowych, unsigned int IloscPlanetoid) {
	 for (int i = 0; i < IloscGwiazdZyjacych; i++) {
		 listaGwiazdZyjacych.push_back(new GwiazdaZyjaca());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaGwiazdZyjacych.at(i)));
	 }
	 for (int i = 0; i < IloscPlanetSkalistych; i++) {
		 listaPlanetSkalistych.push_back(new PlanetaSkalista());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaPlanetSkalistych.at(i)));
		 PoliczPredkoscOrbitalna(*ciala, listaPlanetSkalistych.at(i), listaGwiazdZyjacych.size() + listaGwiazdZdegradowanych.size());
	 }
	 for (int i = 0; i < IloscPlanetGazowych; i++) {
		 listaPlanetGazowych.push_back(new PlanetaGazowa());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaPlanetGazowych.at(i)));
		 PoliczPredkoscOrbitalna(*ciala, listaPlanetGazowych.at(i), listaGwiazdZyjacych.size() + listaGwiazdZdegradowanych.size());
	 }
	 for (int i = 0; i < IloscPlanetoid; i++) {
		 listaPlanetoid.push_back(new Planetoida());
		 ciala->push_back(dynamic_cast<CialoNiebieskie*>(listaPlanetoid.at(i)));
		 PoliczPredkoscOrbitalna(*ciala, listaPlanetoid.at(i), listaGwiazdZyjacych.size() + listaGwiazdZdegradowanych.size());
	 }
	 
		 
	
	 
 }

 int UkladPlanetarny::LiczLata(double Tempo)
 {
	 //Przeliczanie czasu kt�ry up�yn�� niezale�nie od tempa
	czas += int(Tempo);
	tempCzas += (Tempo - int(Tempo));
	if (tempCzas >= 1.0) {
		czas += int(tempCzas);
		tempCzas -= int(tempCzas);
	}

	return czas / 525600;
 }





 void UkladPlanetarny::SprawdzKolizje(std::vector<CialoNiebieskie*>& listaCial,unsigned int& nObiektow, std::ofstream &zapis, int &liczbakolizji)
 {
	 for (int i = 0; i < nObiektow; i++) {
		 for (int j = 0; j < nObiektow; j++) {
			 if (i != j) {
				 double odleglosc = sqrt((listaCial.at(i)->getPozycjaX() - listaCial.at(j)->getPozycjaX())* (listaCial.at(i)->getPozycjaX() - listaCial.at(j)->getPozycjaX()) + 
					 ( listaCial.at(i)->getPozycjaY() - listaCial.at(j)->getPozycjaY())* (listaCial.at(i)->getPozycjaY() - listaCial.at(j)->getPozycjaY()));
				
				 if (odleglosc <= (listaCial.at(i)->getPromien() + listaCial.at(j)->getPromien())) {

					 std::cout << "Kolizja 2 cial" << std::endl;

					 if (listaCial.at(i)->getMasa() <= (listaCial.at(j)->getMasa() / 10.0)) {
						 //delete listaCial[i];
						 listaCial.erase(listaCial.begin() + i);
						 UsunZListy(i);
						 zapis << "cialo "<<listaCial.at(i)->getNazwa() <<" zniszczone" << std::endl;
						 nObiektow-= 1;
						 liczbakolizji++;
						 if (i > 0) i--;
					 }
					 else if (listaCial.at(i)->getMasa() >= (listaCial.at(j)->getMasa() * 10.0)) {
						 //delete listaCial[j];
						 listaCial.erase(listaCial.begin() + j);
						 UsunZListy(j);
						 zapis << "cialo " << listaCial.at(j)->getNazwa() << " zniszczone" << std::endl;
						 nObiektow -= 1;
						 liczbakolizji++;
						 if (j > 0) j--;
					 }
					 else {
						 //delete listaCial[i];
						 //delete listaCial[j];
						 listaCial.erase(listaCial.begin() + i);
						 listaCial.erase(listaCial.begin() + j);
						 UsunZListy(i);
						 UsunZListy(j);
						 zapis << "cialo " << listaCial.at(i)->getNazwa() << " i " << listaCial.at(j)->getNazwa() << " zniszczone"<< std::endl;
						 nObiektow -= 2;
						 liczbakolizji++;
						 if (i > 0) i--;
						 if (i > 0) j--;
					 }
				 }
			 }
		 }
		 if (listaCial.at(i)->getPozycjaX() > 1E13 || listaCial.at(i)->getPozycjaX() < -1E13 || listaCial.at(i)->getPozycjaY() > 1E13 || listaCial.at(i)->getPozycjaY() < -1E13) {
			 listaCial.erase(listaCial.begin() + i);
			 UsunZListy(i);
			 std::cout << "cialo " << listaCial.at(i)->getNazwa() << " opuscilo ten uklad gwiezdny" << std::endl;
			 nObiektow -= 1;
			 if (i > 0) i--;
		 }

	 }
	 
 }

 void UkladPlanetarny::WypiszObiekty() {
	 std::cout << "Gwiazdy zyjace:" << listaGwiazdZyjacych.size() << std::endl;
	 std::cout << "Gwiazdy zdegradowane:" << listaGwiazdZdegradowanych.size() << std::endl;
	 std::cout << "Planety skaliste:" << listaPlanetSkalistych.size() << std::endl;
	 std::cout << "Planety gazowe:" << listaPlanetGazowych.size() << std::endl;
	 std::cout << "Planetoidy:" << listaPlanetoid.size() << std::endl;
	 std::cout << "Temperatura gwiazdy:" << listaGwiazdZyjacych.at(0)->getTemperatura() << std::endl;
	
 }



 