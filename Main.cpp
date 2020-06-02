#include "UkladPlanetarny.h"
#include "Vec2.h"


#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <fstream>

//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
#include <thread>
#include <chrono>
#include<conio.h>
#include "Main.h"


int main();

//void wyswietlwynik()
//{
//    std::cout << "tu beda wyniki";
//    system("cls");
//    main();
//}
//
//void wyswietlzapis()
//{
//    std::cout << "tu bedzie zapis symulacji";
//    system("cls");
//    main();
//}

//void symulacjastart();
//
//void jeszczeraz()
//{
//    std::cout << "Czy chcesz zasymulowaæ kolejny uk³ad?" << std::endl <<
//        "Kliknij 1 jesli tak i 2 jesli chcesz wrocic do menu glownego";
//
//    int klawisz;
//    klawisz = kbhit();
//
//    if (klawisz == 1)
//    {
//        symulacjastart();
//    }
//    if (klawisz == 2) 
//    {
//        system("cls");
//        main();
//    }
//        
//}

void symulacjastart()
{
    std::vector <CialoNiebieskie*> listaCialNiebieskich;
    unsigned int nPlanetSkalistych;
    unsigned int nPlanetGazowych;
    unsigned int nPlanetoid = 10;
    unsigned int nGwiazdZyjacych = 1;
    int liczbakolizji=0;

    double TempoSymulacji = 1.0;
    unsigned int nObiektow;

    unsigned long long int czas;

    system("cls");
    /*std::cout << "Podaj nazwe ukladu";
    std::cin >> NazwaUkladu;*/

    std::cout << std::endl << "Podaj liczbe symulowanych lat"; // tu trzeba bêdzie dobraæ odpowiedni¹ prêdkoœæ symulacji
    std::cin >> czas;

    std::cout << std::endl << "Podaj poczatkowa liczbe planet skalistych w ukladzie:";
    std::cin >> nPlanetSkalistych;

    std::cout << std::endl << "Podaj poczatkowa liczbe planet gazowych w ukladzie:";
    std::cin >> nPlanetGazowych;

    nObiektow = nGwiazdZyjacych + nPlanetSkalistych + nPlanetGazowych + nPlanetoid;

    UkladPlanetarny uklad;

    uklad.StworzUklad(&listaCialNiebieskich, nGwiazdZyjacych, nPlanetSkalistych, nPlanetGazowych, nPlanetoid);
    std::ofstream zapis;
    std::ofstream wynik;
    zapis.open("zapisprzebiegusymulacji.txt");
    wynik.open("zapisdobrychplanet.txt");
    while (czas< uklad.LiczLata(TempoSymulacji))
    {
        uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
        uklad.AktualizujPredkosc(listaCialNiebieskich, TempoSymulacji);
        uklad.AktualizujPozycje(listaCialNiebieskich, TempoSymulacji);
        uklad.SprawdzKolizje(listaCialNiebieskich, nObiektow, zapis, liczbakolizji);

        if (!(czas % 100)) {
            for (int i = 0; i < nObiektow; i++)
            {
                zapis << "R" << i + 1 << " R " << listaCialNiebieskich[i]->getPromien() << std::endl
                    << " M " << listaCialNiebieskich[i]->getMasa() << std::endl <<
                    " pX " << listaCialNiebieskich[i]->getPozycjaX() << std::endl <<
                    " pY " << listaCialNiebieskich[i]->getPozycjaY() << std::endl <<
                    " vX " << listaCialNiebieskich[i]->getPredkoscX() << std::endl <<
                    " vY " << listaCialNiebieskich[i]->getPredkoscY() << std::endl <<
                    " aX " << listaCialNiebieskich[i]->getPrzyspieszenieX() << std::endl <<
                    " aY" << listaCialNiebieskich[i]->getPrzyspieszenieY() << std::endl;
            }
        }
    }
    zapis.close();
    system("cls");
    std::cout << "Koncowy stan ukladu:" << std::endl;
    uklad.WypiszObiekty();
    uklad.wypiszplanety(wynik);
    wynik.close();

    std::cout << std::endl << "Kliknij 1 jesli chcesz przeprowadzic kolejna symulacje" << std::endl <<
        "Kliknij 2 jesli chcesz zobaczyc planety zdatne do zamieszkania" << std::endl <<
        "Kliknij 3 jesli chcesz zobaczyc zapis przebiegu symulacji" << std::endl <<
        "Kliknij 4 jest chcesz wrocic do menu glownego";

    int wybor;
    wybor = getch();

    switch (wybor)
    {
    case '1':
        system("cls");
        symulacjastart();
        //jeszczeraz();
        break;

    case '2':
        system("cls");
        std::cout << std::ifstream("zapisdobrychplanet.txt").rdbuf();
        break;

    case '3':
        system("cls");
        std::cout << std::ifstream("zapisprzebiegusymulacji.txt").rdbuf();
        break;

    case '4':
        main();
    }



}




int main()
{
    char a;
    srand((unsigned)time(NULL));

    std::cout << "Witaj w SOLARIS! Wybierz jedna z opcji" << std::endl << std::endl;

    std::cout << "1. Rozpocznij nowa symulacje" << std::endl <<
        "2. Wyswietl planety zdatne do kolonizacji" << std::endl <<
        "3. Wyswietl przebieg poprzednich symulacji" << std::endl <<
        "4. Wyjdz";

    int znak;
    znak = getch();

    switch (znak)
    {
    case '1':
        symulacjastart();
        //jeszczeraz();
        break;

    case '2':
        system("cls");
        std::cout << std::ifstream("zapisdobrychplanet.txt").rdbuf();
        break;

    case '3':
        system("cls");
        std::cout << std::ifstream("zapisprzebiegusymulacji.txt").rdbuf();
        break;

    case '4':
        return 0;
    }

}




 //std::cout << "Solar systems" << std::endl;

 /*double TempoSymulacji = 2.0;
 unsigned int nObiektow, nGwiazdZyjacych = 1, nPlanetSkalistych =30, nPlanetGazowych = 30,nPlanetoid = 0;
 nObiektow = nGwiazdZyjacych + nPlanetSkalistych + nPlanetGazowych + nPlanetoid;

 std::vector<CialoNiebieskie*> listaCialNiebieskich;
 UkladPlanetarny uklad;
 uklad.StworzUklad(&listaCialNiebieskich,nGwiazdZyjacych,nPlanetSkalistych,nPlanetGazowych,nPlanetoid);*/

 //int n=0;
 //for (int i = 0; i < 100; i++) {
 ////for (; nObiektow;) {
 //    uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
 //    uklad.AktualizujPredkosc(listaCialNiebieskich, TempoSymulacji);
 //    uklad.AktualizujPozycje(listaCialNiebieskich, TempoSymulacji);
 //    uklad.SprawdzKolizje(listaCialNiebieskich, nObiektow);
     


     // Test odleglosci X
     /*std::cout << (listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) *
         (listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX())<< std::endl;*/

     // Test odleglosci Y
     /*std::cout << n++ <<"      "<<(listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()) *
         (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()) << std::endl;*/


    // Test odleglosci
     /*std::cout << n++ << "      " << sqrt((listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) *
         (listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) +
         (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()) *
         (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()))<< std::endl;*/

     //Test parametrow
         /*for (int i = 0; i < nObiektow; i++)
         {
             std::cout << "O" << i + 1 << " promien " << listaCialNiebieskich[i]->getPromien() << " masa " << listaCialNiebieskich[i]->getMasa() <<
                 " pozycjaX " << listaCialNiebieskich[i]->getPozycjaX() << " pozycjaY " << listaCialNiebieskich[i]->getPozycjaY() <<
                 " predkoscX " << listaCialNiebieskich[i]->getPredkoscX() << " PredkoscY " << listaCialNiebieskich[i]->getPredkoscY() <<
                 "PrzyspieszenieX " << listaCialNiebieskich[i]->getPrzyspieszenieX() << "PrzyspieszenieY" << listaCialNiebieskich[i]->getPrzyspieszenieY() << std::endl;
            
         }
         
         
      }
 uklad.WypiszObiekty();*/



 ///////////////////////////////WYSWIETLANIE ////////////////////////////////
 
 //unsigned int height = 800, width = 1200;
 //long double maxH =2E12, maxW = 2E12;
 //int mnoznikwielkosci = 100;
 //        sf::RenderWindow window(sf::VideoMode(width, height), "Solaris!");
 //        float promien = listaCialNiebieskich.at(0)->getPromien() / maxH * height * mnoznikwielkosci;
 //        sf::CircleShape shapeSun(promien);
 //        sf::CircleShape shapePlanet0(listaCialNiebieskich.at(1)->getPromien() / maxH * height * mnoznikwielkosci);
 //        sf::CircleShape shapePlanet1(listaCialNiebieskich.at(2)->getPromien() / maxH * height * mnoznikwielkosci);
 //        sf::CircleShape shapePlanet2(listaCialNiebieskich.at(3)->getPromien() / maxH * height * mnoznikwielkosci);
 //        sf::CircleShape shapePlanet3(listaCialNiebieskich.at(4)->getPromien() / maxH * height * mnoznikwielkosci);
 //        sf::CircleShape shapePlanet4(listaCialNiebieskich.at(5)->getPromien() / maxH * height * mnoznikwielkosci);
 //        sf::CircleShape shapePlanet5(listaCialNiebieskich.at(6)->getPromien() / maxH * height * mnoznikwielkosci);
 //        sf::CircleShape shapePlanet6(listaCialNiebieskich.at(7)->getPromien() / maxH * height * mnoznikwielkosci);
 //        sf::CircleShape shapePlanet7(listaCialNiebieskich.at(8)->getPromien() / maxH * height * mnoznikwielkosci);
 //        sf::CircleShape shapePlanet8(listaCialNiebieskich.at(9)->getPromien() / maxH * height * mnoznikwielkosci);
 //        

 //        if(listaCialNiebieskich.size()>0)
 //    
 //        shapeSun.setFillColor(sf::Color::Red);
 //        shapePlanet0.setFillColor(sf::Color::Green);
 //        shapePlanet1.setFillColor(sf::Color::Green);
 //        shapePlanet2.setFillColor(sf::Color::Green);
 //        shapePlanet3.setFillColor(sf::Color::Green);
 //        shapePlanet4.setFillColor(sf::Color::Green);
 //        shapePlanet5.setFillColor(sf::Color::Green);
 //        shapePlanet6.setFillColor(sf::Color::Green);
 //        shapePlanet7.setFillColor(sf::Color::Green);
 //        shapePlanet8.setFillColor(sf::Color::Green);
 //   
 //        
 //        while (window.isOpen())
 //        {
 //            /*std::cout << n++ << "      " << sqrt((listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) *
 //        (listaCialNiebieskich[0]->getPozycjaX() - listaCialNiebieskich[1]->getPozycjaX()) +
 //        (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()) *
 //        (listaCialNiebieskich[0]->getPozycjaY() - listaCialNiebieskich[1]->getPozycjaY()))<< std::endl;*/


 //            uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
 //            uklad.AktualizujPredkosc(listaCialNiebieskich, TempoSymulacji);
 //            uklad.AktualizujPozycje(listaCialNiebieskich, TempoSymulacji);
 //            uklad.SprawdzKolizje(listaCialNiebieskich, nObiektow);
 //            
 //            if (listaCialNiebieskich.size() > 0) {
 //                shapeSun.setPosition(-listaCialNiebieskich.at(0)->getPozycjaY() / maxW * width + width / 2 - promien, -listaCialNiebieskich.at(0)->getPozycjaX() / maxH * height + height / 2 - promien);
 //               
 //            }
 //            if (listaCialNiebieskich.size() > 1) {
 //                shapePlanet0.setPosition(-listaCialNiebieskich.at(1)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(1)->getPozycjaX() / maxH * height + height / 2);
 //                shapePlanet0.setRadius(listaCialNiebieskich.at(1)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }
 //            if (listaCialNiebieskich.size() > 2) { shapePlanet1.setPosition(-listaCialNiebieskich.at(2)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(2)->getPozycjaX() / maxH * height + height / 2);
 //            shapePlanet1.setRadius(listaCialNiebieskich.at(2)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }
 //            if (listaCialNiebieskich.size() > 3) { shapePlanet2.setPosition(-listaCialNiebieskich.at(3)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(3)->getPozycjaX() / maxH * height + height / 2);
 //            shapePlanet2.setRadius(listaCialNiebieskich.at(3)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }
 //            if (listaCialNiebieskich.size() > 4) {shapePlanet3.setPosition(-listaCialNiebieskich.at(4)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(4)->getPozycjaX() / maxH * height + height / 2);
 //            shapePlanet3.setRadius(listaCialNiebieskich.at(4)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }
 //            if (listaCialNiebieskich.size() > 5) {shapePlanet4.setPosition(-listaCialNiebieskich.at(5)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(5)->getPozycjaX() / maxH * height + height / 2);
 //            shapePlanet4.setRadius(listaCialNiebieskich.at(5)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }
 //            if (listaCialNiebieskich.size() > 6) {shapePlanet5.setPosition(-listaCialNiebieskich.at(6)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(6)->getPozycjaX() / maxH * height + height / 2);
 //            shapePlanet5.setRadius(listaCialNiebieskich.at(6)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }
 //            if (listaCialNiebieskich.size() > 7) {shapePlanet6.setPosition(-listaCialNiebieskich.at(7)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(7)->getPozycjaX() / maxH * height + height / 2);
 //            shapePlanet6.setRadius(listaCialNiebieskich.at(7)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }
 //            if (listaCialNiebieskich.size() > 8){ shapePlanet7.setPosition(-listaCialNiebieskich.at(8)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(8)->getPozycjaX() / maxH * height + height / 2);
 //            shapePlanet7.setRadius(listaCialNiebieskich.at(8)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }
 //            if (listaCialNiebieskich.size() > 9) { shapePlanet8.setPosition(-listaCialNiebieskich.at(9)->getPozycjaY() / maxW * width + width / 2, -listaCialNiebieskich.at(9)->getPozycjaX() / maxH * height + height / 2);
 //            shapePlanet8.setRadius(listaCialNiebieskich.at(9)->getPromien() / maxH * height * mnoznikwielkosci);
 //            }

 //            sf::Event event;
 //            while (window.pollEvent(event))
 //            {
 //                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
 //                {
 //                    TempoSymulacji *= 1.1;
 //                    std::cout << TempoSymulacji<< std::endl;
 //                }
 //                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
 //                {
 //                    TempoSymulacji /= 1.1;
 //                    std::cout << TempoSymulacji << std::endl;
 //                }
 //                
 //                if (event.type == sf::Event::Closed)
 //                    window.close();
 //            }
 //            window.clear();
 //            if (listaCialNiebieskich.size() > 0) window.draw(shapeSun);
 //            if (listaCialNiebieskich.size() > 1)window.draw(shapePlanet0);
 //            if (listaCialNiebieskich.size() > 2) window.draw(shapePlanet1);
 //            if (listaCialNiebieskich.size() > 3) window.draw(shapePlanet2);
 //            if (listaCialNiebieskich.size() > 4) window.draw(shapePlanet3);
 //            if (listaCialNiebieskich.size() > 5) window.draw(shapePlanet4);
 //            if (listaCialNiebieskich.size() > 6) window.draw(shapePlanet5);
 //            if (listaCialNiebieskich.size() > 7) window.draw(shapePlanet6);
 //            if (listaCialNiebieskich.size() > 8) window.draw(shapePlanet7);
 //            if (listaCialNiebieskich.size() > 9) window.draw(shapePlanet8);
 //            
 //            
 //            window.display();
 //        }
 ////            
 ////
 ////std::cin >> a;
 ////


	//return 0;
