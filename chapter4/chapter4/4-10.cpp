#include <iostream>
#include <string>

using namespace std;

/*
class Person {
	string name;
public:
	Person() {}
	Person(string name) { this->name = name; }
	string getName() { return name; }
};

class Family {
	Person* p;
	int size;
	string name;
public:
	Family(string name, int size);
	void setName(int index, string name);
	void show();
	~Family();
};

Family::Family(string name, int size) {
	this->size = size;
	p = new Person[this->size];
	this->name = name;
}

void Family::setName(int index, string name) {
	p[index] = Person(name);
}

void Family::show() {
	cout << this->name << "가족은 다음과 같이 " << this->size << "명 입니다." << endl;
	cout << p[0].getName()<< '\t' << p[1].getName() << '\t' << p[2].getName() << endl;
}

Family::~Family() {
	delete[] p;
}

int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}
*/