#pragma once
#include<iostream>
#include<stdlib.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <conio.h>
#include <vector>


/// Klasa z ktorej dziedzicza niemal wszystkie pozostale.
///
/// Kazde cialo posiada mase, promien, nazwe, pozycje X i Y, predkosc X i Y oraz przyspieszenie X i Y. 

class CialoNiebieskie
{
protected:
	long double Masa;
	long double Promien;
	char Nazwa[32];
	long double PozycjaX;
	long double PozycjaY;
private:
	
	long double PredkoscX;
	long double PredkoscY;
	long double PrzyspieszenieX;
	long double PrzyspieszenieY;

	
public:

	// czemu bez tych konstruktorow aplikacja nie dziala?

	CialoNiebieskie();
	CialoNiebieskie(long double masa, long double promien);
	CialoNiebieskie(long double masa, long double promien, long double pozycjax, long double pozycjay);

	/// Funkcja zwraca pozycje X
	long double getPozycjaX();

	/// Funkcja zwraca pozycje Y
	long double getPozycjaY();

	/// Funkcja zwraca mase cia³a
	long double getMasa();

	/// Funkcja zwraca promien cia³a
	long double getPromien();

	/// Funkcja zwraca predkosc X
	long double getPredkoscX();

	/// Funkcja zwraca prêdkoœæ Y
	long double getPredkoscY();

	/// Funkcja zwraca przyspieszenie X
	long double getPrzyspieszenieX();

	/// Funkcja zwraca przyspieszenie Y
	long double getPrzyspieszenieY();

	/// Funkcja zwraca nazwe
	char* getNazwa();

	/// Przyjmuje wartosc i ustawia ja jako pozycje X dla ciala
	void setPozycjaX(long double x);

	/// Przyjmuje wartosc i ustawia ja jako pozycjê Y dla ciala
	void setPozycjaY(long double y);

	/// Przyjmuje wartosc i ustawia ja jako przyspieszenie X dla ciala
	void setPrzyspieszenieX(long double x);

	/// Przyjmuje wartosc i ustawia ja jako przyspieszenie y dla ciala
	void setPrzyspieszenieY(long double y);

	/// Przyjmuje wartosc i ustawia ja jako predkosc X dla ciala
	void setPredkoscX(long double x);

	/// Przyjmuje wartosc i ustawia ja jako predkosc Y dla ciala
	void setPredkoscY(long double y);
	
};
