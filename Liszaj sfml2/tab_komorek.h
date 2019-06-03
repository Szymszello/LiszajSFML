#pragma once
#include "komorka.h"
#include <SFML\Graphics.hpp>
#include <vector>
class tab_komorek
{
public:
	tab_komorek();
	~tab_komorek();
	void RysujTab(sf::RenderWindow& win);
	void UtworzTab(int r);
	void ZarazKom(int x, int y);
	int RozmiarTab() { return rozmiar; }
	sf::Vector2i PobierzPozycje(int x, int y);
	void AktualizujKomorki();
	void ResetujKom();
	void Param(int odpornosc, int choroba);
	void Opcja_k() { opcja_kolor = !opcja_kolor; }
	void SprawdzS¹siada();
	void UstawMoc(int m) { moc = m; }
	void UstawKolor_d(sf::Color &kolor) { k_dom = kolor; }
	void UstawKolor_ch(sf::Color &kolor) { k_cho = kolor; }
	void UstawKolor_o(sf::Color &kolor) { k_odp = kolor; }
	void ResetKol();
	int IleZarazonych();
	int IleOdpornych();

private:
	std::vector <std::vector<komorka> > tabKom; 
	int rozmiar, czas_ch, czas_o, moc; 
	bool opcja_kolor;

	sf::Color k_dom; 
	sf::Color k_cho;
	sf::Color k_odp;


};

