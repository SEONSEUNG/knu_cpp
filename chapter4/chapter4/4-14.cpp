#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
public:
	string name;
};

class GamblingGame {
public:
	bool Shuffle();
};

bool GamblingGame::Shuffle() {
	cout << '\t' << '\t';
	srand((unsigned)time(0));
	int n1 = rand()%3;
	int n2 = rand()%3;
	int n3 = rand()%3;

	cout << n1 << '\t' << n2 << '\t' << n3 << '\t';
	if (n1 == n2 && n2 == n3) return true;
	else return false;
}

int main() {

	Player* player = new Player[2];
	GamblingGame games;
	int wave = 0;
	string enter;

	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	cout << "첫번째 선수 이름>>";
	cin >> player[0].name;
	cout << "두번째 선수 이름>>";
	cin >> player[1].name;
	getline(cin, enter, '\n');

	while (1) {
		cout << player[wave % 2].name << ":";
		getline(cin, enter, '\n');
		if (games.Shuffle()) {
			cout << player[wave % 2].name << "님 승리!!" << endl;
			break;
		}
		else {
			cout << "아쉽군요!" << endl;
			wave += 1;
		}
		
	}

}