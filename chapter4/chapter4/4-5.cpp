#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
int main() {

	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;

	while (1) {

		string str;

		cout << ">>";
		getline(cin, str);

		if (str == "exit") break;

		int len = str.length();

		srand((unsigned)time(0));
		int random_alphabet = 97 + rand() % 26; //아스키코드로 a~z인 랜덤 상수 생성
		int random_index = rand() % len; //str의 길이에 맞게 랜덤 index 상수 생성

		str[random_index] = char(random_alphabet);

		cout << str << endl;
		
	}
}
*/