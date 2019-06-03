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
	int max_stan = czas_ch + czas_o; //maksymalny stan jaki mo¿e mieæ komórka
	if (stan != 0) stan++;			//zmienia siê co cykl jesli komórka nie jest zdrowa
	if (stan > max_stan) stan = 0;	//jeœli minie czas odpornoœci komórka wraca do stanu zdrowia (0) 
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