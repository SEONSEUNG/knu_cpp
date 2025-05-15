//2. to create calculator class;
//- quiz; to add exponential and log function;

#include <iostream>
using namespace std;

/*
class Calculator {
	int a;
	int b;

public:
	Calculator();

	int add(int a, int b);
	int minus(int a, int b);
	int multiply(int a, int b);
	float divide(int a, int b);
	int power(int a, int b);
	int log(int a, int b);

};

Calculator::Calculator() {}

int Calculator::add(int a, int b) {
	int result;
	result = a + b;
	cout << "add; " << result << endl;

	return result;
}

int Calculator::minus(int a, int b) {
	int result;

	result = a - b;
	cout << "minus; " << result << endl;

	return result;
}

int Calculator::multiply(int a, int b) {
	int result;

	result = a * b;
	cout << "multiply; " << result << endl;

	return result;

}

float Calculator::divide(int a, int b) {
	float result;

	result = float(a) / float(b);
	cout << "divide; " << result << endl;

	return result;
}

int Calculator::power(int a, int b) {
	int result = a; //1번 제곱 (a와 동일)
	for (int i = 2; i <= b; i++) { //2번 제곱부터 b번 거듭제곱
		result *= a;
	}
	cout << "power; " << result << endl;

	return result;
}
int Calculator::log(int a, int b) { //loga(b)형태
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

	cout << "log; " << result << endl;
	return result;
	
}

int main() {
	Calculator cal;

	cal.add(3, 4); //3+4
	cal.minus(3, 4); //3-4
	cal.multiply(3, 4); //3*4
	cal.divide(3, 4); //3/4
	cal.power(3, 4); //3^4
	cal.log(3, 81); //log3(81)

	return 0;
}
*/
