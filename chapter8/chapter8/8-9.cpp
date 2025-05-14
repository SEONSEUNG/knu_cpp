#include <iostream>
#include <string>
using namespace std;

class seat {
	string name;
public:
	seat(string name = "---") {
		this->name = name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

class schedule {
	seat seats[8];
	string name;
public:
	schedule() {};
	void setName(string name) {
		this->name = name;
	}
	void show() {
		cout << name << ": ";
		for (int i = 0; i < 8; i++) {
			cout << '\t' << seats[i].getName();
		}
		cout << endl;
	}
	void addReserv(int seatNum, string seatName){
		seats[seatNum].setName(seatName);
	}
	void cancelReserv(int seatNum, string seatName) {
		if (seats[seatNum].getName() == seatName) {
			seats[seatNum].setName("---");
		}
	}
};

int main() {
	int menuSelect, timeSelect;
	int resNum;
	string resName;

	schedule flight[3];
	flight[0].setName("07시");
	flight[1].setName("12시");
	flight[2].setName("15시");

	cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl;
	while (1) {
		cout << endl << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
		cin >> menuSelect;
		if (menuSelect == 1) {
			cout << "07시:1, 12시:2, 17시:3>> ";
			cin >> timeSelect;
			timeSelect -= 1;

			flight[timeSelect].show();
			cout << "좌석 번호>> ";
			cin >> resNum;
			cin.ignore();
			cout << "이름 입력>> ";
			getline(cin, resName);
			flight[timeSelect].addReserv(resNum-1, resName);
		}
		if (menuSelect == 2) {
			cout << "07시:1, 12시:2, 17시:3>> ";
			cin >> timeSelect;
			timeSelect -= 1;

			flight[timeSelect].show();
			cout << "좌석 번호>> ";
			cin >> resNum;
			cin.ignore();
			cout << "이름 입력>> ";
			getline(cin, resName);
			flight[timeSelect].cancelReserv(resNum - 1, resName);
		}
		if (menuSelect == 3) {
			flight[0].show();
			flight[1].show();
			flight[2].show();
		}
		if (menuSelect == 4) {
			cout << "예약 시스템을 종료합니다." << endl;
			break;
		}
	}
}