#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*
int main() {

	char str[10000];

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�.\n �ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�.\n";
	cin.getline(str, 10000, ';');

	int len = strlen(str);
	int alphabet = 0;
	//cout << "�� ���ĺ� �� " << len;

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

	cout << "�� ���ĺ� �� " << alphabet << '\n';

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " (" << alpha_amount[i] << ") \t: ";
		for (int j = 0; j < alpha_amount[i]; j++) {
			cout << '*';
		}
		cout << "\n";
	}

}
*/