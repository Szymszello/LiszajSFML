#include "proces.h"


proces::proces()
{
	l_zarazen = 0;
	predkosc = 25;
	licznik = 0;
	rozmiar = 25;
	tab.UtworzTab(rozmiar);
	zaznaczenie = 0;
	cz_o = 4;
	cz_ch = 6;
	io = true;
	moc = 50;
	tab;
	tab.Param(cz_ch, cz_o); //czas choroby , czas odpornosci
	tab.UstawMoc(moc);
	
};

 

proces::~proces()
{
}


void proces::Wykonaj(sf::RenderWindow & win, sf::Clock &clock)
{
	
	GUI gui;
	//OBS£UGA MYSZY 
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))  
	{
		if (mousePos.x > 20 && mousePos.x < 145 && mousePos.y > 555 && mousePos.y < 570) {
			zaznaczenie = 0;
		} 

		if (mousePos.x > 20 && mousePos.x < 150 && mousePos.y > 575 && mousePos.y < 590) {
			zaznaczenie = 1;
		}

		if (mousePos.x > 20 && mousePos.x < 135 && mousePos.y > 595 && mousePos.y < 610) {
			zaznaczenie = 2;
		}

		if (mousePos.x > 50 && mousePos.x < 150 && mousePos.y > 450 && mousePos.y < 550) {
			sf::Color color;
			sf::Vector2i pozycja;
			pozycja.x = mousePos.x - 50;
			pozycja.y = mousePos.y - 450;
			
			gui.kolor(color, pozycja);
			if (color != sf::Color(0, 0, 0, 0)) {
				switch (zaznaczenie)
				{
				case 0:
					tab.UstawKolor_d(color);
					break;
				case 1:
					tab.UstawKolor_o(color);
					break;
				case 2:
					tab.UstawKolor_ch(color);
					break;
						
				default:
					break;
				}
			}
		} //kolorowanie

		if (mousePos.x > 200 && mousePos.x < 700 && mousePos.y > 100 && mousePos.y < 600) {
			sf::Vector2i pozycja = tab.PobierzPozycje(mousePos.x - 200, mousePos.y - 100);
			tab.ZarazKom(pozycja.x, pozycja.y);
		}

		if (mousePos.x > 140 && mousePos.x < 170 && mousePos.y > 100 && mousePos.y < 130) { //plus rozmiar tab
			sf::sleep(sf::milliseconds(20));
			if (rozmiar < 300) {
				rozmiar+=5;
				tab.UtworzTab(rozmiar);
			}
		}

		if (mousePos.x > 20 && mousePos.x < 50 && mousePos.y > 100 && mousePos.y < 130) { //minus rozmiar tab
			sf::sleep(sf::milliseconds(20));
			if (rozmiar > 1) {
				rozmiar-=5;
				tab.UtworzTab(rozmiar);
			}
		}

		if (mousePos.x > 140 && mousePos.x < 170 && mousePos.y > 170 && mousePos.y < 200) { //plus predkosc
			if (predkosc < 500) {
				predkosc += 1;
			}
		}

		if (mousePos.x > 20 && mousePos.x < 50 && mousePos.y > 170 && mousePos.y < 200) { //minus predkosc
			if (predkosc > 1) {
				predkosc -= 1;
			}
		}

		if (mousePos.x > 140 && mousePos.x < 170 && mousePos.y > 240 && mousePos.y < 270) { //plus odpornosc			
			if (cz_o < 100) {
				cz_o++;
				tab.Param(cz_o, cz_ch);
			}
		}

		if (mousePos.x > 20 && mousePos.x < 50 && mousePos.y > 240 && mousePos.y < 270) { //minus odpornosc
			if (cz_o > 1) {
				cz_o--;
				tab.Param(cz_o,cz_ch);
			}
		}

		if (mousePos.x > 140 && mousePos.x < 170 && mousePos.y > 310 && mousePos.y < 340) { //plus czas choroby			
			if (cz_ch < 100) {
				cz_ch++;
				tab.Param(cz_o, cz_ch);
			}
		}

		if (mousePos.x > 20 && mousePos.x < 50 && mousePos.y > 310 && mousePos.y < 340) { //minus czas choroby 
			if (cz_ch > 1) {
				cz_ch--;
				tab.Param(cz_o, cz_ch);
			}
		}

		if (mousePos.x > 140 && mousePos.x < 170 && mousePos.y > 380 && mousePos.y < 410) { //plus czas choroby			
			if (moc < 100) {
				moc++;
				tab.UstawMoc(moc);
			}
		}

		if (mousePos.x > 20 && mousePos.x < 50 && mousePos.y > 380 && mousePos.y < 410) { //minus czas choroby 
			if (moc > 1) {
				moc--;
				tab.UstawMoc(moc);
			}
		}

		if (mousePos.x > 630 && mousePos.x < 660 && mousePos.y > 650 && mousePos.y < 680) { //start 
			io = true;
		}

		if (mousePos.x > 670 && mousePos.x < 700 && mousePos.y > 650 && mousePos.y < 680) { //stop
			io = false;
			czas_ocz = 0;
		}

	}

	//OBS£UGA KLAWIATURY 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
		tab.ResetujKom();
		tab.ResetKol();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1)) {
		tab.ResetKol();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2)) {
		tab.ResetujKom();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) {
		sf::sleep(sf::milliseconds(50));
		tab.Opcja_k();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		sf::sleep(sf::milliseconds(100));
		io = !io;
	}

	dzialaj(clock);
	l_zarazen = tab.IleZarazonych();
	l_odpornych = tab.IleOdpornych();
	gui.tlo(win);
	gui.g_main(win, l_zarazen, rozmiar, predkosc, cz_o, cz_ch, moc, czas_ocz, zaznaczenie, l_odpornych);

	tab.RysujTab(win);

	win.display();
	win.clear();
}


void proces::dzialaj(sf::Clock &clock)
{
	if (io) {
		float czas_oczekiwania = 1.0f / (float)predkosc;
		elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() > czas_oczekiwania) {
			tab.SprawdzS¹siada();
			tab.AktualizujKomorki();
			czas_ocz = (int)elapsed.asMilliseconds();
			clock.restart();
		}
	}
}