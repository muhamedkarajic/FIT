/*
Napisati program koji će korisniku omogućiti unos pozitivnih neparnih cijelih brojeva za koje će se ispitivati 
da li im je prva cifra parna (npr. 4993 ili 4999). Ukoliko je zadovoljen uslov broj se smješta u niz od 10 elemenata. 
Unos se ponavlja dok se ne popuni niz od 10 elemenata koji zadovoljavaju uslov unosa. 
Unos se prekida ukoliko korisnik unese vrijednost 0 te se i izvršenje program završava uz poruku 
„Forsirani prekid“. Zatim se za sve elementi niza ispituje da li je broj prost i da li ima samo jednu parnu cifru. 

Ako  broj nije prost i ako ima više od jedne parne cifre, broj se izbacuje iz niza tako što se njegova 
vrijednost mijenja sa 0. Na kraju niz sortirati od najvećeg ka najmanjem broju te ga ispisati. 

Koristiti odvojene funkcije za provjeru da li je broj prost, za sortiranje i ispis niza.
Deklarisati kvadratnu matricu cijelih brojeva proizvoljnih dimenzija, te implementirati sljedeće funkcije:
•	Funkciju za unos i formiranje elemenata matrice prema sljedećem obrascu: elemente neparnih redova matrice 
(1., 3., 5. itd.) čine minimalno trocifreni brojevi koje unosi korisnik programa 
(u slučaju unosa bilo kojeg broja koji ne zadovoljava postavljeni uslov, ponoviti unos); 

elementi parnih redova matrice se formiraju na osnovu elemenata iz prethodnog reda u istoj koloni
*/

#include <iostream>
using namespace std;

const int var = 10;


int main()
{
	int niz[var];



	system("PASUE");
	return 0;
}