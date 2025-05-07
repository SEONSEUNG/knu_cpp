#include <iostream>
#include <string>
using namespace std;
/*
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }

	friend Circle& operator++ (Circle& op);
	friend Circle& operator++(Circle& op, int x);

	void show() { cout << "radius = " << radius << " ÀÎ ¿ø" << endl; }
};

Circle& operator++ (Circle& op) {
	++op.radius;
	return op;
}

Circle& operator++ (Circle& op, int x) {
	Circle tmp = op;
	op.radius++;
	return tmp;
}

int main() {
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}
*/