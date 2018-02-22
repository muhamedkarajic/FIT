#include <iostream>
using namespace std;

int najveci_zajednicki_djelitelj(int prvi, int drugi)
{
	int djelitelj;

	if (drugi%prvi==0)
		return drugi;

	for (int i = drugi*prvi; i >= prvi; i--)
		if (i%prvi==0 && i%drugi == 0)
			djelitelj = i;

	return djelitelj;
}

int main()
{
	int prvi, drugi;

	cout << "Unesi prvi broj: ";
	cin >> prvi;
	
	cout << "Unesi drugi broj: ";
	cin >> drugi;

	if (prvi > drugi)
	{
		int temp = prvi;
		prvi = drugi;
		drugi = temp;
	}


	cout << "Najveci djelitelj: " << najveci_zajednicki_djelitelj(prvi, drugi) << endl;

	system("PAUSE");
	return 0;
}