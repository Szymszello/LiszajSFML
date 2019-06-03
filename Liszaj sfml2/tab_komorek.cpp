#include "tab_komorek.h"
#include <Windows.h>
#include <iostream>


tab_komorek::tab_komorek()
{
	rozmiar = 300;
	for (int i = 0; i < rozmiar; ++i)
	{
		std::vector<komorka> kol;
		for (int j = 0; j < rozmiar; ++j) {		//wpisanie wartosci do tablicy	
			kol.push_back(komorka());
		}
		tabKom.push_back(kol);
	}

	for (int i = 0; i < rozmiar; ++i)
	{
		for (int j = 0; j < rozmiar; ++j) {
			tabKom[i][j].Param(czas_o, czas_ch);
		}
	}

	k_dom = sf::Color(227, 191, 155);
	k_cho = sf::Color(162, 0, 123);
	k_odp = sf::Color(255, 255, 255);
}


tab_komorek::~tab_komorek()
{

}

void tab_komorek::RysujTab(sf::RenderWindow& win)
{
	float bok = (float)500 / (float)rozmiar;
	sf::Vector2f komWymiar(bok, bok);		//obiekt przechowuj¹cy dwie zmienne typu float
	float x = 0.0, y = 0.0;
	int r_R1 = (k_cho.r - k_odp.r) /czas_ch;	//mno¿nik przejscie z chorego na odporny 
	int r_G1 = (k_cho.g - k_odp.g) /czas_ch;			// 
	int r_B1 = (k_cho.b - k_odp.b) /czas_ch;	// 
	int r_R2 = (k_odp.r - k_dom.r) /czas_o; //mno¿nik przejscie z odpornego na zwyk³y 
	int r_G2 = (k_odp.g - k_dom.g) / czas_o; //
	int r_B2 = (k_odp.b - k_dom.b) / czas_o; //
	sf::RectangleShape shape(komWymiar);	//stworzenie obiektu kszta³tu z podanym wymiarem.
	shape.setFillColor(k_dom);			//ustawienie koloru
	shape.setOutlineThickness(1.0f);		//ustawienie obrysu
	shape.setOutlineColor(sf::Color::Black); //ustawienie koloru obrysu 
	
	int lp = 0;
	int stan;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {	
			x =200+ i*komWymiar.x;			//po³o¿enie x
			y =100+ j*komWymiar.y;			//po³o¿enie y 
			shape.setPosition(sf::Vector2f(x, y)); //ustawienie po³o¿enia kwadratu
			shape.setFillColor(k_dom);				
			stan = tabKom[i][j].Stan();
			if (stan > 0 && stan <= czas_ch) { //chory
				//je¿eli w³¹czona jest opcja gradient to kolor ustawiany jest z mno¿nikiem. 
				if(opcja_kolor)shape.setFillColor(sf::Color(k_cho.r-stan*r_R1, k_cho.g-stan*r_G1, k_cho.b-stan*r_B1));  
				else shape.setFillColor(k_cho);
				win.draw(shape);		//rysowanie do bufora 
			}
			if (stan >czas_ch && stan <=czas_ch + czas_o) { //odporny
				int s = stan - czas_ch;
				if (opcja_kolor)shape.setFillColor(sf::Color(k_odp.r-s*r_R2, k_odp.g-s*r_G2, k_odp.b-s*r_B2));
				else shape.setFillColor(k_odp);
				win.draw(shape);
			}		
			if (stan == 0) { //zdrowy
				shape.setFillColor(k_dom);
				win.draw(shape);
			}
			win.draw(shape);
		}
	}
}
void tab_komorek::UtworzTab(int r)
{
	rozmiar = r;
	this->Param(czas_o, czas_ch);
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			if(i>r || j>r) tabKom[i][j].UstawStan(0);
		}
	}
}


void tab_komorek::ZarazKom(int x, int y)
{
	if(tabKom[x][y].Stan()==0) tabKom[x][y].UstawStan(1);	

}

void tab_komorek::SprawdzS¹siada() // 1 = mo¿e byæ zara¿ona , 0 = nie mo¿na zaraziæ
{
	int tablica[3] = {-1, 0, 1};

	for (int i = 0; i < rozmiar; i++) {	 
		for (int j = 0; j < rozmiar; j++) {		
			if (tabKom[i][j].Stan() > 0 && tabKom[i][j].Stan() <= czas_ch) {  //je¿eli komórka chora
					for (int x = 0; x < 3; x++) {
						for (int y = 0; y < 3; y++) {
							int zmx = i + tablica[x];
							int zmy = j + tablica[y];
							if (!(zmx < 0 || zmy < 0 || zmx >= rozmiar || zmy >= rozmiar)) {
								if (!((x == 1) && (y == 1))) {
									if (tabKom[zmx][zmy].Stan() == 0) { // czy zdrowa
										if (rand() % 101 < moc) {
											tabKom[zmx][zmy].UstawStan_t(1);									
										}
									}
								}
							}						
						}
					}
				}
			}
		}
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			tabKom[i][j].AktualizujStan();
			tabKom[i][j].UstawStan_t(0);
		}
	}
}

void tab_komorek::ResetKol()
{
	k_dom = sf::Color(227, 191, 155);
	k_cho = sf::Color(162, 0, 123);
	k_odp = sf::Color(255, 255, 255);
}

int tab_komorek::IleZarazonych()
{
	int x = 0;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (tabKom[i][j].Stan()>0 && tabKom[i][j].Stan() <= czas_ch) x++;
		}
	}
	
	return x;
}

int tab_komorek::IleOdpornych()
{
	int x = 0;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (tabKom[i][j].Stan()>czas_ch) x++;
		}
	}
	return x;
}



sf::Vector2i tab_komorek::PobierzPozycje(int x, int y)
{
	float a = (float)x/500*rozmiar; //pozycja myszy dzielona przez szerokoœæ tablicy komórek w pikselach razy iloœæ komórek 
	a = floor(a);					//zaokr¹glanie w dó³
	float b = (float)y /500*rozmiar;
	b = floor(b);
	return sf::Vector2i((int)a, (int)b); //zwrócenie w postaci wektora, rzutowanie na ca³kowite

}

void tab_komorek::AktualizujKomorki()
{
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			tabKom[j][i].ZwiekszStan();
		}
	}
}

void tab_komorek::ResetujKom()
{
	for (int i = 0; i < 300; i++) {
		for (int j(0); j < 300; j++) {
			tabKom[i][j].UstawStan(0);
		}
	}
}

void tab_komorek::Param(int odpornosc, int choroba)
{
	czas_ch = choroba;
	czas_o = odpornosc;
	for (int i = 0; i < rozmiar; i++) {
		for (int j(0); j < rozmiar; j++) {
			tabKom[i][j].Param(czas_o,czas_ch);
		}
	}
}