#include <iostream>
#include <string>

using namespace std;

/*
class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

Person::Person() { }

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {

	Person person[3];
	string name, tel, str;
	int blank;
	string find;

	cout << "이름과 전화 번호를 입력해 주세요" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1 << ">> ";
		getline(cin, str);

		blank = str.find(' ');
		name = str.substr(0, blank);
		tel = str.substr(blank + 1, str.size());

		person[i].set(name, tel);
	}

	cout << "모든 사람의 이름은 " << person[0].getName() << " " << person[1].getName() << " " << person[2].getName() << endl;

	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	cin >> find;

	for (int i = 0; i < 3; i++) {
		if (person[i].getName() == find) {
			cout << "전화 번호는 " << person[i].getTel() << endl;
			break;
		}
	}
}
*/