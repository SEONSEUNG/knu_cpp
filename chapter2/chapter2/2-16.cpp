#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*
int main() {

	char str[10000];

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n 텍스트의 끝은 ; 입니다. 10000개까지 가능합니다.\n";
	cin.getline(str, 10000, ';');

	int len = strlen(str);
	int alphabet = 0;
	//cout << "총 알파벳 수 " << len;

	char alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int alpha_amount[26] = { 0 };

	for (int i = 0; i < len; i++) {

		if (isalpha(str[i]) == 0) {
			str[i] = ' ';
		}
		else {
			str[i] = tolower(str[i]);
			alphabet += 1;
			for (int j = 0; j < 26; j++) {
				if (str[i] == alpha[j]) {
					alpha_amount[j] += 1;
					break;
				}
			}
		}

	}

	cout << "총 알파벳 수 " << alphabet << '\n';

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " (" << alpha_amount[i] << ") \t: ";
		for (int j = 0; j < alpha_amount[i]; j++) {
			cout << '*';
		}
		cout << "\n";
	}

}
*/