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

shared_ptr<Stest> funct()
{
	shared_ptr<Stest> Sp = make_shared<Stest>();
	//shared_ptr<Stest> Sp(new Stest);
	
	Sp->variable = 100;
	return Sp;
}

int main()
{
	
	shared_ptr<Stest> Spret = funct();
	cout << "Use count = " <<  Spret.use_count() << endl;
	shared_ptr<Stest> Spret2 = Spret;
	cout << "Use count = " << Spret.use_count() << endl;

	cout << "Use count = " << Spret2.use_count() << endl;


	cout << Spret->variable << endl;
	cout << Spret2->variable << endl;


	system("PAUSE");
	return 0;
}