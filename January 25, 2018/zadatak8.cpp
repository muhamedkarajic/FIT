#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
Uz pomoć matrice realnih brojeva dimenzija 5x7 izraditi program za evidenciju i kalkulaciju uspješnosti vremenskih 
prognoza (prosječnih dnevnih temperatura) određenog grada. 

Redovi matrice predstavljaju meteorologe čije se prognoze unose, dok se kolone odnose na vremenski period od 7 dana. 

Uz matricu je neophodno krerati globalni jednodimenzionalni niz od 7 elemenata koji će čuvati stvarna mjerenja 
temperatura za isti vremenski period, a na osnovu kojeg će se procijeniti uspješnost prognoza pojedinih meteorologa. 

Vrijednosti elemenata ovog niza prilikom deklaracije postaviti na: 25.5, 26.8, 21, 32, 35.6, 36, 33.5.
25.5 27.8 2 32 5.6 36 33.5 
25.5 6.8 21 32 5.6 36 23.5 
2.5 28 21 32 40 3 3.5 
5.5 26.8 1 2 3.6 36 3.5 
25.5 26.8 21 32 35.6 36 33.5
Implementaciju programa uraditi pomoću sljedećih funkcija:
•	UnesiPrognoze – funkcija za unos prognoza određenog meteorologa za kompletan period od 7 dana. 
Vrijednosti prosječnih temperatura moraju biti unutar intervala [-20, 50] °C. 
(Pojasnjenje: unose se podaci za samo jedan izabrani red. Tako ce se korisniku omoguciti da unese 
prognoze za jednog po jednog meteorologa.)
•	IzracunajUspjesnost – funkciju koja vraća procentualnu vrijednost uspješnosti prognoza za željenog meteorologa. 
Prognoza, odnosno prosječna temperatura na određeni dan, smatra se uspješnom ako od stvarnog mjerenja 
ne odstupa više od 5 °C.
*/

const int r = 5, k = 7;

void UnesiPrognoze(double niz[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> niz[i];
		if (niz[i]>50 || niz[i] <-20)
			i--;
	}
	cout << endl;
}

double IzracunajUspjesnost(double niz[], int n, double vrijeme[])
{
	double brojacUspjesnosti = 0;
	for (int i = 0; i < n; i++)
		//if ((vrijeme[i] < niz[i] + 10) && (vrijeme[i] > niz[i] - 10))
			brojacUspjesnosti += abs(vrijeme[i] - niz[i]);
		//else brojacUspjesnosti++;

	return brojacUspjesnosti;
}

char PronadjiDanSaNajnizimPrognozama(double niz[][k], double vrijeme[])
{
	double max = IzracunajUspjesnost(niz[0], k, vrijeme);
	int meterolog = 'A';
	cout << IzracunajUspjesnost(niz[0], k, vrijeme) << endl;
	for (int i = 1; i < r; i++)
	{
		cout << IzracunajUspjesnost(niz[i], k, vrijeme) << endl;
		if (IzracunajUspjesnost(niz[i], k, vrijeme) > max)
		{
			max = IzracunajUspjesnost(niz[i], k, vrijeme);
			meterolog = char('A' + i);
		}
	}
	return char(meterolog);

}


int main()
{
	double niz[r][k];
	double vrijeme[7] = { 25.5, 26.8, 21, 32, 35.6, 36, 33.5 };
	char ime = 'A';

	cout << "Vrijednosti moraju biti od [-20, 50] °C" << endl;
	for (int i = 0; i < r; i++)
	{
		cout << "Unos za meteorologa: " << char(ime + i) << ": ";
		UnesiPrognoze(niz[i], k);
	}
	cout << endl;

	double max = IzracunajUspjesnost(niz[0], k, vrijeme);
	int meterolog = 'A';
	cout << IzracunajUspjesnost(niz[0], k, vrijeme) << endl;
	for (int i = 1; i < r; i++)
	{
		cout << IzracunajUspjesnost(niz[i], k, vrijeme) << endl;
		if (IzracunajUspjesnost(niz[i], k, vrijeme) < max)
		{
			max = IzracunajUspjesnost(niz[i], k, vrijeme);
			meterolog = char('A' + i);
		}
	}


	cout << "Meterolog koji je bio najblizi je: " << char(meterolog) << endl;

	cout << "Meterolog koji je bio najdalje je: " << PronadjiDanSaNajnizimPrognozama(niz,vrijeme) << endl;


	system("PAUSE");
	return 0;
}