#pragma once
#include <SFML\Graphics.hpp>
#include "Okno.h"
#include <iostream>
class GUI
{
public:
	GUI();
	~GUI();

	void g_main(sf::RenderWindow & window, int l_zar, int rozmiar, int predkosc, int cz_o, int cz_ch, int moc, int czas_ocz, int x, int l_odp);
	void kolor(sf::Color &kolor, sf::Vector2i gdzie);
	void tlo(sf::RenderWindow &w);
};

 
