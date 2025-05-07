#include <iostream>
#include <string>
using namespace std;

class Stack {
	int size = 3, count = 2, i = 0;
	int* pArray = new int[size];
public:
	Stack() {
		for (int i = 0; i < size; i++) pArray[i] = 0;
	}

	~Stack() {
		delete[] pArray;
	}

	Stack& operator << (int x) {
		pArray[i] = x;
		i++;
		return *this;
	}

	void operator >> (int& x) {
		x = pArray[count];
		count--;
		size--;
	}

	bool operator ! () {
		if (size == 0) return true;
		else return false;
	}
};

int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}