#include "UkladPlanetarny.h"


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



#include "Main.h"


int main();

void symulacjastart();

/// Funkcja wyswietla menu po przeprowadzeniu symulacji, inne niz poczatkowe

void menu()
{
    std::cout << std::endl << "Kliknij 1 jesli chcesz przeprowadzic kolejna symulacje" << std::endl <<
        "Kliknij 2 jesli chcesz zobaczyc planety zdatne do zamieszkania" << std::endl <<
        "Kliknij 3 jesli chcesz zobaczyc dane planet gazowych " << std::endl <<
        "Kliknij 4 jesli chcesz zobaczyc zapis przebiegu symulacji" << std::endl <<
        "Kliknij 5 jest chcesz wrocic do menu glownego";

    int wybor;
    wybor = getch();


    switch (wybor)
    {
    case '1':
        system("cls");
        symulacjastart();
        break;

    case '2':
        system("cls");
        std::cout << std::ifstream("zapisdobrychplanet.txt").rdbuf(); 
        std::cout << std::endl << "kliknij zeby wrocic do menu";
        getch();
        main();
        break;

    case '3':
        system("cls");
        std::cout << std::ifstream("zapisgazowychplanet.txt").rdbuf();
        std::cout << std::endl << "kliknij zeby wrocic do menu";
        getch();
        main();
        break;

    case '4':
        system("cls");
        std::cout << std::ifstream("zapisprzebiegusymulacji.txt").rdbuf();
        std::cout << std::endl << "kliknij zeby wrocic do menu";
        getch();
        main();
        break;

    case '5':
        main();
    }
}

/// Funkcja jest odpowiedzialna za wprowadzanie poczatkowych parametrow, stworzenie ukladu i dbanie o uporzadkowany 
/// przebieg calej symulacji.

void symulacjastart()
{
    bool gwiazda = true;
    std::vector <CialoNiebieskie*> listaCialNiebieskich;
    unsigned int nPlanetSkalistych;
    unsigned int nPlanetGazowych;
    unsigned int nPlanetoid = 0;
    unsigned int nGwiazdZyjacych = 1;
    unsigned int nGwiazdZdegradowanych = 0;
    int liczbakolizji = 0;
    int kontrola = 0;

    double TempoSymulacji =1.00;
    unsigned int nObiektow;

    unsigned int lata;

    system("cls");

    std::cout << "Podaj liczbe symulowanych lat: "; // tu trzeba bêdzie dobraæ odpowiedni¹ prêdkoœæ symulacji
    std::cin >> lata;
    if (lata < 1 || lata>50) {
        lata = 2;
        std::cout << "Podano nieprawidlowa wartosc, ustawiono domyslna wartosc 3" << std::endl;
    }

    std::cout << std::endl << "Podaj poczatkowa liczbe planet skalistych w ukladzie: ";
    std::cin >> nPlanetSkalistych;
    if (nPlanetSkalistych < 0 || nPlanetSkalistych>500) {
        nPlanetSkalistych = 20;
        std::cout << "Podano nieprawidlowa wartosc, ustawiono domyslna wartosc 20" << std::endl;
    }

    std::cout << std::endl << "Podaj poczatkowa liczbe planet gazowych w ukladzie: ";
    std::cin >> nPlanetGazowych;
    if (nPlanetGazowych < 0 || nPlanetGazowych>500) {
        nPlanetGazowych = 20;
        std::cout << "Podano nieprawidlowa wartosc, ustawiono domyslna wartosc 20" << std::endl;
    }

    std::cout << std::endl << "Podaj liczbe planetoid w ukladzie (zalecane 300): ";
    std::cin >> nPlanetoid;
    if (nPlanetoid < 0 || nPlanetoid>1000) {
        nPlanetoid = 150;
        std::cout << "Podano nieprawidlowa wartosc, ustawiono domyslna wartosc 150" << std::endl;
    }

    nObiektow = nGwiazdZyjacych + nPlanetSkalistych + nPlanetGazowych + nPlanetoid + nGwiazdZdegradowanych;

    UkladPlanetarny uklad;

    std::cout << std::endl << "Podaj nazwe ukladu: ";

    uklad.nazwij();

    system("cls");
    std::cout << "Tworzymy uklad i przeprowadzamy symulacje..." << std::endl << "Czekaj na wyniki... Ponizej wyswietlamy wazniejsze wydarzenia"
        << std::endl;

    uklad.StworzUklad(&listaCialNiebieskich, nGwiazdZyjacych, nPlanetSkalistych, nPlanetGazowych, nPlanetoid);
    std::ofstream zapis;
    std::ofstream wynik;
    std::ofstream gazowe;
    zapis.open("zapisprzebiegusymulacji.txt");
    wynik.open("zapisdobrychplanet.txt");
    gazowe.open("zapisgazowychplanet.txt");

    //int cykl = 0;




    ///////////////////////////////WYSWIETLANIE ////////////////////////////////


    /////////       STEROWANIE     ///////////

    //KLAWISZ           ->     AKCJA

    //STRZALKA W GORE   ->  ZWIEKSZ Tempo symulacji
    //STRZALKA W DOL    ->  ZMNIEJSZ Tempo symulacji
    //STRZALKA W LEWO   ->  ZMNIEJSZ Powiekszenie obiektow
    //STRZALKA W PRAWO  ->  ZWIEKSZ Powiekszenie obiektow
    // N                ->  WYLACZ Skupienie na gwiezdzie
    // M                ->  WLACZ Skupienie na gwiezdzie

    unsigned int height = 800, width = 800;
    long double maxH = 2E12, maxW = 2E12;
    int mnoznikwielkosci = 1;
    sf::RenderWindow window(sf::VideoMode(width, height), "Solaris!");
    int cykl = 0;
    bool skupienie = false;
    while (lata > uklad.LiczLata(TempoSymulacji))
    {
        uklad.AktualizujPrzyspieszenie(listaCialNiebieskich);
        uklad.AktualizujPredkosc(listaCialNiebieskich, TempoSymulacji);
        uklad.AktualizujPozycje(listaCialNiebieskich, TempoSymulacji);
        uklad.SprawdzKolizje(listaCialNiebieskich, nObiektow, zapis, liczbakolizji);
        uklad.ewolucja(listaCialNiebieskich, kontrola, gwiazda);

        if (cykl % 100) {

            for (int i = 0; i < nObiektow; i++)
            {

                zapis << listaCialNiebieskich.at(i)->getNazwa()<< "R" << i + 1 << " R " << listaCialNiebieskich[i]->getPromien() << std::endl
                    << " M " << listaCialNiebieskich[i]->getMasa() << std::endl <<
                    " pX " << listaCialNiebieskich[i]->getPozycjaX() << std::endl <<
                    " pY " << listaCialNiebieskich[i]->getPozycjaY() << std::endl <<
                    " vX " << listaCialNiebieskich[i]->getPredkoscX() << std::endl <<
                    " vY " << listaCialNiebieskich[i]->getPredkoscY() << std::endl <<
                    " aX " << listaCialNiebieskich[i]->getPrzyspieszenieX() << std::endl <<
                    " aY" << listaCialNiebieskich[i]->getPrzyspieszenieY() << std::endl;
            }
        }

        cykl++;



        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && TempoSymulacji<1000)
            {
                TempoSymulacji *= 1.1;
                std::cout << "Tempo symulacji " << TempoSymulacji << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && TempoSymulacji> 0.01)
            {
                TempoSymulacji /= 1.1;
                std::cout << "Tempo symulacji " << TempoSymulacji << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& mnoznikwielkosci>1)
            {
                mnoznikwielkosci -= 10;
                std::cout << "Powiekszenie obiektow "<<mnoznikwielkosci << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && mnoznikwielkosci<200)
            {
                mnoznikwielkosci += 10;
                std::cout << "Powiekszenie obiektow " << mnoznikwielkosci << std::endl;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
            {
                skupienie = false;
                std::cout << "Skupienie wylaczone " << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            {
                skupienie = true;
                std::cout << "Skupienie wlaczone " << std::endl;
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        std::vector<sf::CircleShape> kuleczki;

        for (int i = 0; i < listaCialNiebieskich.size(); i++)
        {
            int tempPromien;
            tempPromien = listaCialNiebieskich.at(i)->getPromien() / maxH * height * mnoznikwielkosci;
            
            sf::CircleShape shape(tempPromien);
            if (tempPromien < 0.75) shape.setRadius(0.75);
            
            if (skupienie) shape.setPosition((listaCialNiebieskich.at(0)->getPozycjaX() -listaCialNiebieskich.at(i)->getPozycjaX()) / maxW * width + width / 2 - tempPromien,(listaCialNiebieskich.at(0)->getPozycjaY() -listaCialNiebieskich.at(i)->getPozycjaY()) / maxH * height + height / 2 - tempPromien);
            else shape.setPosition(-listaCialNiebieskich.at(i)->getPozycjaX() / maxW * width + width / 2 -tempPromien, -listaCialNiebieskich.at(i)->getPozycjaY() / maxH * height + height / 2 - tempPromien);
            if (listaCialNiebieskich.at(i)->getNazwa()[1] == 'S') shape.setFillColor(sf::Color::Green);
            else if (listaCialNiebieskich.at(i)->getNazwa()[0] == 'G') shape.setFillColor(sf::Color::Blue);
            else if (listaCialNiebieskich.at(i)->getNazwa()[1] == 'Y') shape.setFillColor(sf::Color::Yellow);
            else if (listaCialNiebieskich.at(i)->getNazwa()[2] == 'D') shape.setFillColor(sf::Color::White);
            else shape.setFillColor(sf::Color::Magenta);

            // copy shape to vector
            kuleczki.push_back(shape);
        }
        for (std::vector<sf::CircleShape>::iterator it = kuleczki.begin(); it != kuleczki.end(); ++it)
        {
            // draw all circles
            window.draw(*it);
        }
        window.display();
    }
    window.close();



    zapis.close();
    system("cls");
    std::cout << "Koncowy stan:" << std::endl;
    uklad.WypiszObiekty(gwiazda);
    std::cout << "Liczba kolizji obiektow:" << liczbakolizji;
    uklad.wypiszplanety(wynik, gwiazda);
    wynik.close();
    uklad.wypiszgazowe(gazowe);
    gazowe.close();
    uklad.posprzataj();
    menu();


}




/// W tej funkcji umiescilismy poczatkowe menu aplikacji.


int main()
{
    char a;
    srand((unsigned)time(NULL));

    system("cls");

    std::cout << "Witaj w SOLARIS! Wybierz jedna z opcji" << std::endl << std::endl;

    std::cout << "1. Rozpocznij nowa symulacje" << std::endl <<
        "2. Wyswietl planety zdatne do kolonizacji" << std::endl <<
        "3. Wysiwetl dane gazowych olbrzymow" << std::endl <<
        "4. Wyswietl przebieg poprzednich symulacji" << std::endl <<
        "5. Wyjdz";

    int znak;
    znak = getch();

    switch (znak)
    {
    case '1':
        symulacjastart();
        break;

    case '2':
        system("cls");
        std::cout << std::ifstream("zapisdobrychplanet.txt").rdbuf();
        break;

    case '3':
        system("cls");
        std::cout << std::ifstream("zapisgazowychplanet.txt").rdbuf();
        break;

    case '4':
        system("cls");
        std::cout << std::ifstream("zapisprzebiegusymulacji.txt").rdbuf();
        break;

    case '5':
        return 0;
    }

}


      

