//U nastavku je prikazan primjer izračunavanja sume kvadrata cijelih brojeva u rasponu od n do m – rekurzijom
int SumaKvadrata(int m, int n)
{
    if(m > n)
        return 0;   
    return m*m + SumaKvadrata(m+1, n);
}

//Jedan od jednostavnih rekurzivnih algoritama jest izračunavanje n! za n >= 0.
int Faktorijel(int n)
{
    if(n<=1)
        return 1;
    return n * Faktorijel(n-1);
}

//Da li je na osnovu datog niza, moguće napisati formulu za bilo koji n. Niz: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ... , ?
int Fibonacci(int n)
{
    if (n <= 1)
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

//Koristeći rekurziju napisati funkciju koja će simulirati rad funkcije pow.
double pow(double vrijednost, int eksponent){
    if (eksponent == 0)
        return 1;
    else if (eksponent == 1)
        return vrijednost;
    else
        return vrijednost * pow (vrijednost, eksponent - 1);
}

//Najveći zajednički djelilac
int nzd (int a, int b) {
    if(b == 0)
        return a;
    return nzd(b, a % b);
}

/*
Prednosti:
• koncizniji opis algoritma
• lakše je dokazati korektnost

Nedostaci:
• uvećano vrijeme izvođenja
• neki jezici ne podržavaju rekurziju
*/