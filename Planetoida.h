#pragma once
#include "CialoNiebieskie.h"

/// Planetoida moze posiadac rzadkie pierwiastki

class Planetoida :
	public CialoNiebieskie
{
private:
	bool RzadkiePierwiastki;

public:

	/// Konstruktor nadajacy planetoidzie losowa nazwe i wlasciwe dla tego typu ciala parametry
	Planetoida();

	/// Funkcja zwraca informacje o wystepowaniu rzadkich pierwiastkow
	bool getRzadkiePierwiastki();
};

