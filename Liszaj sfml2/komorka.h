#pragma once
#include <SFML\Graphics.hpp>
class komorka
{
public:
	komorka();
	~komorka();
	
	void ZwiekszStan();
	void UstawStan(int zdrowie) { stan = zdrowie; }
	void UstawStan_t(int t) { stan_t = t; }
 	int Stan() { return stan; }
	int Stan_t() { return stan_t; }
	void Param(int o, int ch);
	void AktualizujStan();

private:
	int stan, czas_o, czas_ch;	
	int stan_t;

};

