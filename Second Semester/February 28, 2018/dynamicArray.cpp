#include <iostream>
using namespace std;

const int CAPACITY = 5;

int main()
{
	int *dArray;
	dArray = new int[CAPACITY];

	for (int i = 0; i < CAPACITY; i++)
		dArray[i] = i;

	for (int i = 0; i < CAPACITY; i++)
		cout << dArray[i] << " ";
	cout << endl;

	delete[] dArray;
	dArray = NULL;

	system("PAUSE");
	return 0;
}