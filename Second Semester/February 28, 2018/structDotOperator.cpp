#include <iostream>
#include <string>
using namespace std;


struct address
{
	int house_number;
	string street_name;
};

struct student
{
	string name;
	int id;
	address street_address;
};

void print(student name)
{
	cout << "Name: " << name.name << endl;
	cout << "ID: " << name.id << endl;
	cout << "Address: " << name.street_address.street_name << " " << name.street_address.house_number << endl;
}

int main()
{
	student Muhamed;
	Muhamed.name = "Muhamed Karajic";
	Muhamed.id = 9799847;
	Muhamed.street_address.house_number = 28;
	Muhamed.street_address.street_name = "Ulica";

	print(Muhamed);

	system("PAUSE");
	return 0;
}

