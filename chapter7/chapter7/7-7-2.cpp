#include <iostream>
#include <string>
using namespace std;
/*
class Matrix {
	int a, b, c, d;
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	friend Matrix operator >> (Matrix m, int op[]);
	friend Matrix& operator << (Matrix& m, int op[]);

	void show() {
		cout << "Matrix = {" << a << ' ' << b << ' ' << c << ' ' << d << "} \n";
	}
};

Matrix operator >> (Matrix m, int op[]) {
	int* p = op;
	p[0] = m.a;
	p[1] = m.b;
	p[2] = m.c;
	p[3] = m.d;
	return *p;
}

Matrix& operator << (Matrix& m, int op[]) {
	m.a = op[0];
	m.b = op[1];
	m.c = op[2];
	m.d = op[3];
	return m;
}

int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1, 2, 3, 4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}
*/