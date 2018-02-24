#include <iostream>
using namespace std;

int main()
{
	const int var = 17;

	int niz[var] = { 1,65,2,25,6,17,2,64,7,75,2,549,6,7,52,47,7 };

	

	bool zastava = true;
	int brojac = 0;
	for (int i = 0; i < var && zastava == true; i++)
	{
		zastava = false;
		for (int j = 0; j < var-1-i; j++)
		{
			if (niz[j] > niz[j + 1])
			{
				int temp = niz[j + 1];
				niz[j + 1] = niz[j];
				niz[j] = temp;
				zastava = true;
			}
			brojac++;
		for (int x = 0; x < var; x++)
		{
			cout << niz[x] << " ";
		}
		cout << endl;
		}
		
		cout << endl;
	}

	cout << "BROJAC: " << brojac << endl;


	system("PAUSE");
	return 0;
}