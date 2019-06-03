#pragma once
#include "tab_komorek.h"
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "GUI.h"

using namespace std;

class proces
{
public:
	proces();
	~proces();

	void Wykonaj(sf::RenderWindow & win, sf::Clock &clock);
	int rozmiar;

private:
	int l_zarazen, moc, predkosc, licznik, cz_o, cz_ch;
	int czas_ocz, zaznaczenie, l_odpornych;
	tab_komorek tab;
	bool io;
	void dzialaj(sf::Clock &clock);
	sf::Time elapsed;
	
};

