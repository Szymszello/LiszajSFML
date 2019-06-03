#include "Okno.h"

#include <SFML\Graphics.hpp>
int main() {
	

	Okno okno;
	okno.Wywietl();
	return 0; 

}


/*Zasymuluj zara¿enie liszajem stosuj¹c tablicê n ´ n (np. n = 11) komórek skóry.
Rozpocznij od zara¿enia œrodkowej komórki. Po up³ywie kolejnej jednostki czasu
zara¿ona komórka ma 50% szans zara¿enia ka¿dej ze zdrowych s¹siednich komórek. Po
szeœciu jednostkach czasu zara¿ona komórka staje siê na cztery jednostki odporna i
nastêpnie zdrowa. Zasymuluj tê chorobê i wyœwietlaj zawartoœæ tablicy po up³ywie
ka¿dej jednostki czasu ukazuj¹c, które z komórek s¹ zara¿one, odporne lub zdrowe.
Mo¿liwe jest dodanie dodatkowych parametrów (za³o¿eñ) daj¹c¹ rozwiniecie procesu
symulacji (np. mo¿liwoœæ zmiany czasu odpornoœci itp.).*/