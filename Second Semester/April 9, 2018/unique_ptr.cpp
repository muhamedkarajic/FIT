#include <iostream>
#include <memory>
using namespace std;


struct Stest
{
	int variable;
	Stest()
	{
		cout << "Constructon" << endl;
	}
	~Stest()
	{
		cout << "Destructon" << endl;
	}
};

unique_ptr<Stest> funct()
{
	unique_ptr<Stest> Up(new Stest);
	return Up;
}

int main()
{

	cout << "Enter main" << endl;
	//unique_ptr<Stest> Up(new Stest);
	//unique_ptr<Stest> Up2 = Up; - nije moguce
	//unique_ptr<Stest> Up2 = move(Up); ovo je moguce

	unique_ptr<Stest> Up3 = funct();//ovo radi zbog move semantic
	cout << "exit main" << endl;

	system("PAUSE");
	return 0;
}