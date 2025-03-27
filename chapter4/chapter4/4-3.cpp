#include <iostream>
#include <string>

using namespace std;

/*
//4-3-1
int main() {

	string str;
	cout << "문자열 입력>>";
	getline(cin, str);

	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a') count += 1;
	}

	cout << "문자 a는 " << count << "개 있습니다." << endl;

}
*/

/*
//4-3-2
int main() {

	string str;
	cout << "문자열 입력>>";
	getline(cin, str);
	int hi = 0;
	int count = 0;
	int index = -1;
	while (1) {
		index = str.find('a', index+1);
		if (index >= str.size()) break;
		count += 1;
	}

	cout << "문자 a는 " << count << "개 있습니다." << endl;

}
*/