#include "Okno.h"

#pragma once

using namespace sf;
using namespace std; 
Okno::Okno()
{

}




Okno::~Okno()
{
}

void Okno::Wywietl()
{
	proces proces;	//obiekt klasy proces

	RenderWindow window(VideoMode(730, 700), "Symulacja Liszaja", Style::Close);	//utworzenie okna
																					//Style::Close ustawia styl okna (okno b�dzie posiada� przyciski zamknij i minimalizuj)
	sf::Clock clock;

	window.setVerticalSyncEnabled(true);	//ustawienie synchronizacji pionowej, podobno optymalizuje wydajno�� aplikacji.

	while (window.isOpen())				//p�tla wykonuj�ca si� gdy okno jest otwarte
	{
		Event evnt;					
		while (window.pollEvent(evnt))  
		{
			if (evnt.type == Event::Closed)  //zamyka okna w mom�cie klikni�cia X 
				window.close();
		}
		proces.Wykonaj(window, clock);  //wywo�anie funkcji na obiekcie klasy proces.
	}
}
