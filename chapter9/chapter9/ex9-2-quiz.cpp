#include <iostream>
using namespace std;

/*
class Calculator {
public:
	virtual float add(float x, float y) { cout << "Calculator add called: ";  return int(x + y); };
};

class upgradeCalculator : public Calculator {
public:
	virtual float add(float x, float y) { cout << "upgradeCalculator add called: "; return x + y; };
};

int main() {
	upgradeCalculator Cadd, * pUpg;
	pUpg = &Cadd;
	cout << "upgradeCalculator -> (3.3, 4.2): " << pUpg->add(3.3, 4.2) << endl; //upgradeCalculator::add()호출

	Calculator* pCal;
	pCal = pUpg;
	cout << "Calculator -> (3.2, 4.2): " << pCal->add(3.2, 4.2) << endl; //오버라이딩->upgradeCalculator::add() 호출
}
*/