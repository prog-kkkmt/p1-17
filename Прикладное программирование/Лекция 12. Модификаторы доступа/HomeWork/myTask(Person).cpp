#include <iostream>

using namespace std;

class Person {
public:
	void setValues(string name, string role, bool gender, int age);
	void print();

private:
	string name;
	string role;
	bool gender;
	int age;
};

void Person::setValues(string name, string role, bool gender, int age) {
	this->name = name;
	this->role = role;
	this->gender = gender;
	this->age = age;
}

void Person::print() {
	cout << this->role << " " << this->name << " " << ((this->gender) ? "Female" : "Male") << " " << this->age;
}

int main() {
	Person p;
	string name;
	string role;
	bool gender;
	int age;

	cout << "Enter name: ";
	cin >> name;

	cout << "Enter role: ";
	cin >> role;

	cout << "Enter gender(0 - male, 1 - female): ";
	cin >> gender;

	cout << "Enter age: ";
	cin >> age;

	p.setValues(name, role, gender, age);

	p.print();

	return 0;
}