#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
class EvenRandom {
public:
    EvenRandom();
    int next();
    int nextInRange(int s, int e);
};

EvenRandom::EvenRandom() {}

int EvenRandom::next() {
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

int EvenRandom::nextInRange(int s, int e) {
    int num = s + rand() % (e - s + 1);
    while (1) {
        if (num % 2 == 0) {
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

    EvenRandom r;
    cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 �� --" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next();
        cout << n << ' ';
    }
    cout << endl << endl << "-- 2���� " << "10 ������ ���� ���� 10 �� --" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 10);
        cout << n << ' ';
    }
    cout << endl;

}
*/