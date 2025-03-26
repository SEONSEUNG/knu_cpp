#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
class SelectableRandom {
public:
    SelectableRandom();
    int next();
    int nextInRange(int s, int e);
};

SelectableRandom::SelectableRandom() {}

int SelectableRandom::next() {
    int num = rand();
    while (1) {
        if (num % 2 == 0) {
            break;
        }
        else {
            num = rand();
        }
    }
    return num;
}

int SelectableRandom::nextInRange(int s, int e) {
    int num = s + rand() % (e - s + 1);
    while (1) {
        if (num % 2 == 1) {
            break;
        }
        else {
            num = s + rand() % (e - s + 1);
        }
    }
    return num;
}

int main() {

    srand((unsigned)time(0));

    SelectableRandom r;
    cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개 --" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next();
        cout << n << ' ';
    }
    cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 9);
        cout << n << ' ';
    }
    cout << endl;

}
*/