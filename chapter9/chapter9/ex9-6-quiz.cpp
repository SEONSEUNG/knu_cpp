#include <iostream>
using namespace std;

/*
class Calculator {
public:
	virtual int add(int a, int b) = 0;
	virtual int subtract(int a, int b) = 0;
	virtual int multiply(int a, int b) = 0;
	virtual float divide(int a, int b) = 0;
};

class OfficeCalc :public Calculator {
public:
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }
	int multiply(int a, int b) { return a * b; }
	float divide(int a, int b) { return float(a) / float(b); }
};

class ScientificCalc : public Calculator {
public:
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }
	int multiply(int a, int b) { return a * b; }
	float divide(int a, int b) { return float(a) / float(b); }
	int power(int a, int b) {
		int result = a; //1번 제곱 (a와 동일)
		for (int i = 2; i <= b; i++) { //2번 제곱부터 b번 거듭제곱
			result *= a;
		}
		return result;
	}
	int log(int a, int b) { //loga(b)형태
		int result = a, temp = 1;
		if (b == 1) { //loga(1) = 0
			result = 0;
		}
		else {
			while (temp <= 30) { //30제곱까지만 계산
				if (result == b) { //result가 거듭제곱해져서 b와 같다면
					result = temp; //result를 제곱한 횟수로 변경
					break; //while문 종료
				}
				else temp += 1; //b와 같지 않다면, 제곱한 횟수 +1
				result *= a; //result에 a를 곱하기
			}
			if (temp == 30) result = -1; //30제곱안에 없으면 -1출력
		}
		return result;

	}
};

int main() {
	Calculator* p = new OfficeCalc();
	ScientificCalc SC;

	int menuSelect;
	int n1, n2;
	cout << "***** Office & Scientific Calculator *****";
	while (1) {
		cout << endl << "Office: 1, Scientific: 2, Quit: 3 \nEnter >> ";
		cin >> menuSelect;
		if (menuSelect == 1) {
			cout << endl << "Office Calculator // +: 1, -: 2, *: 3, /: 4 \nEnter >> ";
			cin >> menuSelect;
			cout << endl << "Enter 2 numbers >> ";
			cin >> n1 >> n2;
			switch (menuSelect){
			case 1:
				cout << "add: " << p->add(n1, n2) << endl;
				break;
			case 2:
				cout << "subtract: " << p->subtract(n1, n2) << endl;
				break;
			case 3:
				cout << "multiply: " << p->multiply(n1, n2) << endl;
				break;
			case 4:
				cout << "divide: " << p->divide(n1, n2) << endl;
				break;
			default:
				cout << "Error occured; Try Again" << endl;
			}
		}
		else if (menuSelect == 2) {
			cout << endl << "Scientific Calculator // +: 1, -: 2, *: 3, /: 4, power: 5, log: 6 \nEnter >> ";
			cin >> menuSelect;
			cout << endl << "Enter 2 numbers >> ";
			cin >> n1 >> n2;
			switch (menuSelect) {
			case 1:
				cout << "add: " << SC.add(n1, n2) << endl;
				break;
			case 2:
				cout << "subtract: " << SC.subtract(n1, n2) << endl;
				break;
			case 3:
				cout << "multiply: " << SC.multiply(n1, n2) << endl;
				break;
			case 4:
				cout << "divide: " << SC.divide(n1, n2) << endl;
				break;
			case 5:
				cout << "power: " << SC.power(n1, n2) << endl;
				break;
			case 6:
				cout << "log: " << SC.log(n1, n2) << endl;
				break;
			default:
				cout << "Error occured; Try Again" << endl;
			}
		}
		else if (menuSelect == 3) {
			cout << "Program quit." << endl;
			break;
		}
	}
	
	delete p;
}
*/