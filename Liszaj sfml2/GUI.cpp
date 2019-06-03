#include "GUI.h"



GUI::GUI()
{
	
}


GUI::~GUI()
{
}

void GUI::g_main(sf::RenderWindow & window, int l_zar, int rozmiar, int predkosc, int cz_o, int cz_ch, int moc, int czas_ocz, int x, int l_odp)
{
	sf::Font font;
	sf::Text tekst;
	sf::Texture grafika;
	sf::RectangleShape kwadrat(sf::Vector2f(30.0f, 30.0f));
	
	font.loadFromFile("ALGER.ttf");
	tekst.setPosition(200.0f, 665.0f);
	tekst.setString("Czas jednej klatki: " + std::to_string(czas_ocz)); //czas klatki
	tekst.setFont(font);
	tekst.setCharacterSize(15);
	window.draw(tekst);

	tekst.setPosition(200.0f, 650.0f);
	tekst.setString("Liczba zarazonych komorek: " + std::to_string(l_zar));  // liczba zara¿eñ
	window.draw(tekst);

	tekst.setPosition(200.0f, 635.0f);
	tekst.setString("Liczba odpornych komorek: " + std::to_string(l_odp));  // liczba zara¿eñ
	window.draw(tekst);


	//TEKST TEKST TEKST//
	tekst.setPosition(100.0f, 10.0f);
	tekst.setCharacterSize(50);
	tekst.setString("Symulacja Liszaja");
	window.draw(tekst);

	tekst.setCharacterSize(20);
	tekst.setPosition(10.0f, 130.0f);
	tekst.setString("Rozmiar tablicy");
	window.draw(tekst);

	tekst.setPosition(45.0f, 200.0f);
	tekst.setString("Predkosc");
	window.draw(tekst);

	tekst.setPosition(40.0f, 270.0f);
	tekst.setString("Odpornosc");
	window.draw(tekst);

	tekst.setPosition(30.0f, 340.0f);
	tekst.setString("Czas choroby");
	window.draw(tekst);


	tekst.setPosition(30.0f, 410.0f);
	tekst.setString("Moc razenia");
	window.draw(tekst);
	
	tekst.setPosition(20.0f, 630.0f);
	tekst.setString("R - Reset");
	window.draw(tekst);

	tekst.setPosition(20.0f, 660.0f);
	tekst.setString("G - Gradient");
	window.draw(tekst);


	tekst.setString(std::to_string(rozmiar)); //rozmiar tablicy 
	tekst.setPosition(85.0f, 100.0f);
	window.draw(tekst);

	tekst.setString(std::to_string(predkosc)); //predkosc
	tekst.setPosition(85.0f, 170.0f);
	window.draw(tekst);

	tekst.setString(std::to_string(cz_o)); //czas odpornosci
	tekst.setPosition(85.0f, 240.0f);
	window.draw(tekst);

	tekst.setString(std::to_string(cz_ch)); //czas choroby
	tekst.setPosition(85.0f, 310.0f);
	window.draw(tekst);

	tekst.setString(std::to_string(moc)+"%"); //moc zara¿enia
	tekst.setPosition(85.0f, 380.0f);
	window.draw(tekst);

	//GRAFIKA GRAFIKA GRAFIKA//

	grafika.loadFromFile("Texture/plus.png");
	kwadrat.setSize(sf::Vector2f(30.0f, 30.0f));
	kwadrat.setTexture(&grafika);
	kwadrat.setPosition(140.0f, 100.0f);  // + rozm
	window.draw(kwadrat);

	kwadrat.setPosition(140.0f, 170.0f); // + prêdkoœæ
	window.draw(kwadrat);

	kwadrat.setPosition(140.0f, 240.0f); // + odpornosc
	window.draw(kwadrat);

	kwadrat.setPosition(140.0f, 310.0f); // + czas choroby
	window.draw(kwadrat);

	kwadrat.setPosition(140.0f, 380.0f); // + % mocy
	window.draw(kwadrat);


	grafika.loadFromFile("Texture/minus.png"); // - rozm

	kwadrat.setPosition(20.0f, 100.0f);
	window.draw(kwadrat);

	kwadrat.setPosition(20.0f, 170.0f); // - prêdkoœæ
	window.draw(kwadrat);

	kwadrat.setPosition(20.0f, 240.0f); // - odpornoœæ 
	window.draw(kwadrat);

	kwadrat.setPosition(20.0f, 310.0f); // - czas choroby
	window.draw(kwadrat);
	
	kwadrat.setPosition(20.0f, 380.0f); // - % mocy
	window.draw(kwadrat);

	grafika.loadFromFile("Texture/play.png"); // - play

	kwadrat.setPosition(630.0f, 650.0f);
	window.draw(kwadrat);

	grafika.loadFromFile("Texture/stop.png"); // - stop

	kwadrat.setPosition(670.0f, 650.0f);
	window.draw(kwadrat);


	tekst.setCharacterSize(15);
	tekst.setPosition(20.0f, 555.0f);
	tekst.setString("Zdrowa");
	window.draw(tekst);

	tekst.setPosition(20.0f, 575.0f);
	tekst.setString("Odporna");
	window.draw(tekst);


	tekst.setPosition(20.0f, 595.0f);
	tekst.setString("Chora");
	window.draw(tekst);

	grafika.loadFromFile("Texture/podkreslenie.png");
	kwadrat.setSize(sf::Vector2f(50.0f, 20.0f));
	kwadrat.setPosition(20.0f, 570.0f+x*20);
	window.draw(kwadrat);
	

	sf::RectangleShape kolo(sf::Vector2f(100.0f, 100.0f));
	sf::Image image;
	image.loadFromFile("Texture/kolo.png");
	grafika.loadFromImage(image);

	kolo.setTexture(&grafika);
	kolo.setPosition(50.0f, 450.0f);
	sf::Color kolor = image.getPixel(2, 3);
	
	window.draw(kolo);
		
}

void GUI::kolor(sf::Color &kolor, sf::Vector2i gdzie)
{
	sf::RectangleShape kolo(sf::Vector2f(100.0f, 100.0f));
	sf::Image image;
	image.loadFromFile("Texture/kolo.png");
	float x = (float)gdzie.x / 100 * 250;
	float y = (float)gdzie.y / 100 * 250;
	kolor = image.getPixel((int)x, (int)y);

}

void GUI::tlo(sf::RenderWindow & w)
{
	sf::Texture grafika;
	sf::RectangleShape kwadrat(sf::Vector2f(730.0f, 700.0f));

	grafika.loadFromFile("Texture/tlo.png");
	kwadrat.setTexture(&grafika);
	w.draw(kwadrat);
}