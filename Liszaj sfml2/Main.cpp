#include "Okno.h"

#include <SFML\Graphics.hpp>
int main() {
	

	Okno okno;
	okno.Wywietl();
	return 0; 

}


/*Zasymuluj zara�enie liszajem stosuj�c tablic� n � n (np. n = 11) kom�rek sk�ry.
Rozpocznij od zara�enia �rodkowej kom�rki. Po up�ywie kolejnej jednostki czasu
zara�ona kom�rka ma 50% szans zara�enia ka�dej ze zdrowych s�siednich kom�rek. Po
sze�ciu jednostkach czasu zara�ona kom�rka staje si� na cztery jednostki odporna i
nast�pnie zdrowa. Zasymuluj t� chorob� i wy�wietlaj zawarto�� tablicy po up�ywie
ka�dej jednostki czasu ukazuj�c, kt�re z kom�rek s� zara�one, odporne lub zdrowe.
Mo�liwe jest dodanie dodatkowych parametr�w (za�o�e�) daj�c� rozwiniecie procesu
symulacji (np. mo�liwo�� zmiany czasu odporno�ci itp.).*/