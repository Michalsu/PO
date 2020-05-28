#include "UkladPlanetarny.h"
#include "Vec2.h"
#include "Main.h"

#include<iostream>
#include<stdlib.h>
#include <time.h>




int main()
{  char a;
srand((unsigned)time(NULL));
 std::cout << "Solar systems" << std::endl;

 double TempoSymulacji = 10.0;
unsigned int nObiektow, nPlanetSkalistych=1, nPlanetGazowych=0, nPlanetoid=0;
 nObiektow = nPlanetSkalistych + nPlanetGazowych + nPlanetoid;

 std::vector<CialoNiebieskie*> listaCialNiebieskich;
 UkladPlanetarny uklad;
 uklad.StworzUklad(&listaCialNiebieskich,nPlanetSkalistych,nPlanetGazowych,nPlanetoid);

 int n=0;
 //for (int i = 0; i < 2000; i++) {
 for (; nObiektow;) {
     uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
     uklad.AktualizujPredkosc(listaCialNiebieskich);
     uklad.AktualizujPozycje(listaCialNiebieskich, TempoSymulacji);
     uklad.SprawdzKolizje(listaCialNiebieskich, nObiektow);
     


     // Test odleglosci X
     /*std::cout << (listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) *
         (listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX())<< std::endl;*/

     // Test odleglosci Y
     
     /*std::cout << n++ <<"      "<<(listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()) *
         (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()) << std::endl;*/


    // Test odleglosci
     std::cout << n++ << "      " << sqrt((listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) *
         (listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) +
         (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()) *
         (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()))<< std::endl;

     //Test parametrow
        /* for (int i = 0; i < nObiektow+1; i++)
         {
            if (i==0) std::cout << "O" << i + 1 << " promien " << listaCialNiebieskich[i]->getPromien() << " masa " << listaCialNiebieskich[i]->getMasa() <<
                 " pozycjaX " << listaCialNiebieskich[i]->getPozycjaX() << " pozycjaY " << listaCialNiebieskich[i]->getPozycjaY() <<
                 " predkoscX " << listaCialNiebieskich[i]->getPredkoscX() << " PredkoscY " << listaCialNiebieskich[i]->getPredkoscY() <<
                 "PrzyspieszenieX " << listaCialNiebieskich[i]->getPrzyspieszenieX() << "PrzyspieszenieY" << listaCialNiebieskich[i]->getPrzyspieszenieY() << std::endl;
         }*/
         
         //std::cout << nObiektow+1 << std::endl;
         
     }
 uklad.WypiszObiekty();
 
 
             

 

 std::cin >> a;
 


	return 0;
}



//Wersja z wyswietlaniem
//Nale¿y recznie do³¹czyæ biblioteki SFML

//
//
//
//#include "UkladPlanetarny.h"
//#include "Vec2.h"
//#include "Main.h"
//
//#include<iostream>
//#include<stdlib.h>
//#include <time.h>
//
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <thread>
//#include <chrono>
//
//
//
//int main()
//{
//    char a;
//    srand((unsigned)time(NULL));
//    std::cout << "Solar systems" << std::endl;
//
//    double TempoSymulacji = 1.0;
//    unsigned int nObiektow, nPlanetSkalistych = 20, nPlanetGazowych = 12, nPlanetoid = 400;
//    nObiektow = nPlanetSkalistych + nPlanetGazowych + nPlanetoid;
//
//    std::vector<CialoNiebieskie*> listaCialNiebieskich;
//    UkladPlanetarny uklad;
//    uklad.StworzUklad(&listaCialNiebieskich, nPlanetSkalistych, nPlanetGazowych, nPlanetoid);
//
//
//    unsigned int height = 800, width = 1200;
//    long double maxH = 2E10, maxW = 2E10;
//    sf::RenderWindow window(sf::VideoMode(width, height), "Solaris!");
//    float promien = listaCialNiebieskich.at(0)->getPromien() / maxH * height;
//    sf::CircleShape shapeSun(promien);
//    sf::CircleShape shapePlanet0(25.f);
//    sf::CircleShape shapePlanet1(25.f);
//    sf::CircleShape shapePlanet2(25.f);
//    sf::CircleShape shapePlanet3(25.f);
//    sf::CircleShape shapePlanet4(25.f);
//    sf::CircleShape shapePlanet5(25.f);
//    sf::CircleShape shapePlanet6(25.f);
//    sf::CircleShape shapePlanet7(25.f);
//    sf::CircleShape shapePlanet8(25.f);
//
//
//
//    shapeSun.setFillColor(sf::Color::Red);
//    shapePlanet0.setFillColor(sf::Color::Green);
//    shapePlanet1.setFillColor(sf::Color::Green);
//    shapePlanet2.setFillColor(sf::Color::Green);
//    shapePlanet3.setFillColor(sf::Color::Green);
//    shapePlanet4.setFillColor(sf::Color::Green);
//    shapePlanet5.setFillColor(sf::Color::Green);
//    shapePlanet6.setFillColor(sf::Color::Green);
//    shapePlanet7.setFillColor(sf::Color::Green);
//    shapePlanet8.setFillColor(sf::Color::Green);
//
//
//    while (window.isOpen())
//    {
//        /*std::cout << n++ << "      " << sqrt((listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) *
//    (listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) +
//    (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()) *
//    (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()))<< std::endl;*/
//        uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
//        uklad.AktualizujPredkosc(listaCialNiebieskich);
//        uklad.AktualizujPozycje(listaCialNiebieskich, TempoSymulacji);
//        uklad.SprawdzKolizje(listaCialNiebieskich, nObiektow);
//
//        shapeSun.setPosition(-listaCialNiebieskich.at(0)->getPozycjaY() / maxW * width + width / 2 - promien, -listaCialNiebieskich.at(0)->getPozycjaX() / maxH * height + height / 2 - promien);
//        shapePlanet0.setPosition(-listaCialNiebieskich.at(1)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(1)->getPozycjaX() / maxH * height + height / 2);
//        shapePlanet1.setPosition(-listaCialNiebieskich.at(2)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(2)->getPozycjaX() / maxH * height + height / 2);
//        shapePlanet2.setPosition(-listaCialNiebieskich.at(3)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(3)->getPozycjaX() / maxH * height + height / 2);
//        shapePlanet3.setPosition(-listaCialNiebieskich.at(4)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(4)->getPozycjaX() / maxH * height + height / 2);
//        shapePlanet4.setPosition(-listaCialNiebieskich.at(5)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(5)->getPozycjaX() / maxH * height + height / 2);
//        shapePlanet5.setPosition(-listaCialNiebieskich.at(6)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(6)->getPozycjaX() / maxH * height + height / 2);
//        shapePlanet6.setPosition(-listaCialNiebieskich.at(7)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(7)->getPozycjaX() / maxH * height + height / 2);
//        shapePlanet7.setPosition(-listaCialNiebieskich.at(8)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(8)->getPozycjaX() / maxH * height + height / 2);
//        shapePlanet8.setPosition(-listaCialNiebieskich.at(9)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(9)->getPozycjaX() / maxH * height + height / 2);
//
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//            {
//                TempoSymulacji *= 1.1;
//                std::cout << TempoSymulacji << std::endl;
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//            {
//                TempoSymulacji /= 1.1;
//                std::cout << TempoSymulacji << std::endl;
//            }
//
//
//
//
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shapeSun);
//        window.draw(shapePlanet0);
//        window.draw(shapePlanet1);
//        window.draw(shapePlanet2);
//        window.draw(shapePlanet3);
//        window.draw(shapePlanet4);
//        window.draw(shapePlanet5);
//        window.draw(shapePlanet6);
//        window.draw(shapePlanet7);
//        window.draw(shapePlanet8);
//
//
//        window.display();
//    }
//}
//
