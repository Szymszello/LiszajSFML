#include "komorka.h"



komorka::komorka()
{	
	stan = 0;		// 0 = zdrowa,
	stan_t = 0;
}


komorka::~komorka()
{
}

void komorka::ZwiekszStan()
{
	int max_stan = czas_ch + czas_o; //maksymalny stan jaki mo�e mie� kom�rka
	if (stan != 0) stan++;			//zmienia si� co cykl jesli kom�rka nie jest zdrowa
	if (stan > max_stan) stan = 0;	//je�li minie czas odporno�ci kom�rka wraca do stanu zdrowia (0) 
}


void komorka::Param(int o, int ch)
{
	czas_ch = ch;
	czas_o = o;
}

void komorka::AktualizujStan()
{
	if(stan_t)stan = stan_t;
}