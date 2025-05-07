#include <iostream>
#include <string>
/*
using namespace std;

class Client {

	int id;
	string name;
	int attendance;
	int bonus;

public:
	Client() {
		id = 0;
		name = "None";
		attendance = 0;
		bonus = 0;
	}
	Client(int id, string name, int attendance = 0, int bonus = 0) {
		this->id = id;
		this->name = name;
		this->attendance = attendance;
		this->bonus = bonus;
	}
	void input(int id, string name, int attendance) {
		this->id = id;
		this->name = name;
		this->attendance = attendance;
	}
	Client operator+ (Client op2) {
		Client tmp;
		tmp.id = id;
		tmp.name = name;
		tmp.attendance = attendance;
		tmp.bonus = op2.bonus + op2.attendance / 2;
		return tmp;
	}
	void show() {
		cout << "ID: " << id << ", Name: " << name << ", Attendance: " << attendance << ", Bonus: " << bonus << endl;
	}

};

int main() {
	Client* client = new Client[10];

	int tmp_id, tmp_attendance, tmp_bonus;
	string tmp;

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << "번째 Client 정보 입력" << endl;
		cout << "ID >> ";
		cin >> tmp_id;
		cout << "Name >> ";
		cin >> tmp;
		cout << "Attendance >> ";
		cin >> tmp_attendance;
		client[i].input(tmp_id, tmp, tmp_attendance);
		cout << endl;
	}

	cout << endl << "Bonus 점수 부여 전 출력" << endl;

	for (int i = 0; i < 10; i++) {
		client[i].show();
	}

	cout << endl;

	for (int i = 0; i < 10; i++) {
		client[i] = client[i] + client[i];
	}

	cout << endl << "Bonus 점수 부여 후 출력 (출석 2회당 1점 부여)" << endl;

	for (int i = 0; i < 10; i++) {
		client[i].show();
	}

}
*/