#pragma once
#include "CialoNiebieskie.h"
#include "Gwiazda.h"
#include "GwiazdaZdegradowana.h"
#include "GwiazdaZyjaca.h"
#include "Planeta.h"
#include "PlanetaGazowa.h"
#include "PlanetaSkalista.h"
#include "Planetoida.h"


/// Uklad planetarny to najwieksza klasa ktora zarzadza wszystkimi obiektami i ich interakcjami.
///
/// Tworzy obiekty, rozmieszcza je w przestrzeni, oblicza ich predkosc i przyspieszenie. Posiada swoja nazwe 
/// ktora wybiera uzytkownik.

class UkladPlanetarny
{
private:

	std::string NazwaUkladu;
	unsigned long long int czas = 0;
	void UkladPlanetarny::UsunZListy(int lp);
	void PoliczPredkoscOrbitalna(std::vector<CialoNiebieskie*>& listaCial, CialoNiebieskie* pCialo, int IleGwiazd);
	

	

public:

	/// Funkcja wypisuje dane gazowych olbrzymow do pliku tekstowego
	void UkladPlanetarny::wypiszgazowe(std::ofstream& gazowe);

	/// Funkcja nazywa uklad planetarny
	void UkladPlanetarny::nazwij();

	/// Funkcja wypisuje planety zdatne do kolonizacji do pliku tekstowego
	void wypiszplanety(std::ofstream &wynik, bool gwiazda);

    /// Funkcja wylicza i aktualizuje przyspieszenie dla wszystkich cial
	void UkladPlanetarny::AktualizujPrzyspieszenie(std::vector<CialoNiebieskie*>& listaCial);

	/// Funkcja wylicza i aktualizuje predkosc dla wszystkich cial
	void UkladPlanetarny::AktualizujPredkosc(std::vector<CialoNiebieskie*>& listaCial, double Tempo);

	/// Funkcja wylicza i aktualizuje pozcyje dla wszystkich cial
	void UkladPlanetarny::AktualizujPozycje(std::vector<CialoNiebieskie*>& listaCial, double Tempo);

	/// Funkcja inicjalizuje wszystkie obiekty
	void UkladPlanetarny::StworzUklad(std::vector<CialoNiebieskie*>* ciala, unsigned int IloscGwiazdZyjacych, unsigned int IloscPlanetSkalistych, unsigned int IloscPlanetGazowych, unsigned int IloscPlanetoid);

	/// Funkcja przelicza czas ktory uplynal niezaleznie od tempa symulacji
	int UkladPlanetarny::LiczLata(double Tempo);

	/// Funkcje przed stworzeniem nowego ukladu czysci vectory z cialami
	void UkladPlanetarny::posprzataj();

	/// Funkcja sprawdza kolizje poszczegolnych cial
	void UkladPlanetarny::SprawdzKolizje(std::vector<CialoNiebieskie*>& listaCial, unsigned int& nObiektow, std::ofstream &zapis, int &liczbakolizji);

	/// Funkcja wypisuje ilosc obiektow koncowych
	void UkladPlanetarny::WypiszObiekty(bool gwiazda);

	/// Funkcja zarzadza ewolucja gwiazdy zyjacej i jej przemiana w gwiazde zdegradowana
	void UkladPlanetarny::ewolucja(std::vector<CialoNiebieskie*>& ciala, int& kontrola, bool &gwiazda);
};

