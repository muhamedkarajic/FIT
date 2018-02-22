/*
Neka je data matrica kompetencija studenata dimenzija 10x5, 
gdje svaki red matrice predstavlja studenta, a svaka kolona matrice kompetenciju 
koju je potrebno evaluirati. 

Matrica sadrži podatke o studentima sa dva studijska programa, 
prvih 5 redova za jedan i drugih 5 redova za drugi program. 

Kompetencije se definišu putem sljedeće skale: 
-A (ekspert), 
-B (stručnjak), 
-C (zadovoljava), 
-D (djelimično zadovoljava) i 
-E (ne zadovoljava). 


Napisati program koji će implementirati i testirati sljedeće funkcije:
•	evaluiraj – funkcija omogućava unos evaluacije za određenog (odabranog u glavnom programu) 
studenta (unosi se samo jedan red matrice), na način da su dozvoljene samo vrijednosti usvojene prethodnom skalom 
(A, B, C, D i E). U slučaju unosa bilo kojeg karaktera izvan ovog opsega, potrebno je ponoviti unos. 

Prilikom unosa ispisati poruku za svaku kompetenciju na sljedeći način: 
„Unesite evaluaciju za kompetenciju C1“, i tako redom za svaku kolonu.
•	najuspjesnija_kompetencija 
– funkcija pronalazi kompetenciju (u oba studijska programa) 
koja je najuspješnija, odnosno na kojoj su studenti ostvarili najbolji rezultat, 
te vraća i prosječnu ocjenu za tu kompetenciju.

Napomena: Pridružiti svakoj oznaci numeričku vrijednost, radi jednostavnosti kalkulacije i poređenja uspjeha pojedinih 
kompetencija. Koristiti prosljeđivanje najmanje jednog parametra po referenci, te ispis rezultata ne vršiti u funkciji.
•	najuspjesniji_student – funkcija pronalazi najuspješnijeg studenta u odabranom studijskom programu 
(studijski program se bira u glavnom programu putem vrijednost 1 (prvih 5 redova) ili 
2 (drugih 5 redova), te vraća i prosječnu ocjenu tog studenta. Vrijede iste napomene kao i za prethodnu funkciju.



*/
#include <iostream>
using namespace std;

const int s = 10, k = 5;

int main()
{
	int niz[s][k];
	int odabir;

	do
	{
		cout << "Unesi odabir: ";
		cin >> odabir;
	} while (odabir>9 || odabir<0);
	

	system("PAUSE");
	return 0;
}