#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

void Circle::setCircle(string name, int radius) {
	this->name = name;
	this->radius = radius;
}

double Circle::getArea() {
	return this->radius * this->radius * 3.141592;
}

string Circle::getName() {
	return this->name;
}

class CircleManager {
	Circle* p;
	int size;
public:
	CircleManager(int size);
	~CircleManager();
	void searchByName();
	void searchByArea();
};

CircleManager::CircleManager(int size) {
	p = new Circle[size];
	this->size = size;

	string str;
	int blank;
	string str_name;
	string str_radius;


	for (int i = 0; i < size; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		getline(cin, str);

		blank = str.find(' ');
		str_name = str.substr(0, blank);
		str_radius = str.substr(blank + 1, str.size());
		cout << str_radius;
		//p[i].setCircle(str_name, stoi(str_radius));

	}
}

CircleManager::~CircleManager() {
	delete[] p;
}

void CircleManager::searchByName() {

	string find;

	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> find;

	for (int i = 0; i < this->size; i++) {
		if (p[i].getName() == find) cout << p[i].getName() << "의 면적은 " << p[i].getArea();
	}
}

void CircleManager::searchByArea() {

}

int main() {

	int amount;

	cout << "원의 개수 >> ";
	cin >> amount;
	CircleManager circles(amount);

	circles.searchByName();
	circles.searchByArea();

	

}