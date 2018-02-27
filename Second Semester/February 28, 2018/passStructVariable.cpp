#include <iostream>
using namespace std;

struct student
{
	int rollno;
	char type;
	int age;
};

void show(student *);
void display(student);
void changePointer(student *);
void changeVariable(student);

int main()
{
	student Muhamed = { 1234, 'm', 24 };
	cout << "Print as a variable to a function: ";
	display(Muhamed);
	cout << endl;

	cout << "Print as a pointer to a function: ";
	show(&Muhamed);
	cout << endl;

	changeVariable(Muhamed);
	cout << "Print as a variable to a function: ";
	display(Muhamed);
	cout << endl;
	

	changePointer(&Muhamed);
	cout << "Print as a pointer to a function: ";
	show(&Muhamed);
	cout << endl;


	system("PAUSE");
	return 0;
}
void show(student *object)
{

	cout << object->rollno << endl;
	cout << object->type << endl;
	cout << object->age << endl;
}

void display(student object)
{
	cout << object.rollno << endl;
	cout << object.type << endl;
	cout << object.age << endl;
}

void changePointer(student *object)
{
	cout << "TRYED TO CHANGE THE VARIABLE USING A POINTER\n\n";
	object->age = 50;
}

void changeVariable(student object)
{
	cout << "TRYED TO CHANGE THE VARIABLE\n\n";
	object.age = 50;
}