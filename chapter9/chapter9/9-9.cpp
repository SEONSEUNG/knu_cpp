#include <iostream>
#include <string>
using namespace std;

/*
class Printer {
    string model, manufacturer;
    int printedCount, availableCount;
public:
    Printer(string model, string manufacturer, int availableCount) {
        this->model = model;
        this->manufacturer = manufacturer;
        this->availableCount = availableCount;
    }
    virtual ~Printer() {}
    bool isAvailToPrint(int count) {
        if (availableCount < count) {
            cout << "용지가 부족하여 프린트할 수 없습니다" << endl;
            return false;
        }
        else
            return true;
    }
    virtual void print(int count) {
        availableCount -= count;
        printedCount += count;
    }
    virtual void show() {
        cout << model << ", " << manufacturer << ", 남은종이 " << availableCount << "장, ";
    }
};

class InkJetPrinter : public Printer {
    int availableInk;
public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) : Printer(model, manufacturer, availableCount) {
        this->availableInk = availableInk;
    }
    virtual ~InkJetPrinter() {}
    virtual void print(int count) {
        if (availableInk < count) {
            cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
            return;
        }
        if (Printer::isAvailToPrint(count)) {
            Printer::print(count);
            availableInk -= count;
            cout << "프린트하였습니다." << endl;
        }
    }
    virtual void show() {
        cout << "잉크젯 : ";
        Printer::show();
        cout << "남은 잉크 " << availableInk << endl;
    }
};

class LaserPrinter : public Printer {
    int availableTonner;
public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableTonner) : Printer(model, manufacturer, availableCount) {
        this->availableTonner = availableTonner;
    }
    virtual ~LaserPrinter() {}
    virtual void print(int count) {
        if (availableTonner < count) {
            cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
            return;
        }
        if (Printer::isAvailToPrint(count)) {
            Printer::print(count);
            availableTonner -= count;
            cout << "프린트하였습니다." << endl;
        }
    }
    virtual void show() {
        cout << "레이저 : ";
        Printer::show();
        cout << "남은 토너 " << availableTonner << endl;
    }
};

class Menu {
    Printer* printers[2];
    int printerCount = 2;
public:
    ~Menu() {
        for (int i = 0; i < printerCount; i++)
            if (printers[i]) delete printers[i];
    }
    void run() {
        printers[0] = new InkJetPrinter("Officejet V40", "HP", 5, 10);
        printers[1] = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

        cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;

        for (int i = 0; i < printerCount; i++) {
            printers[i]->show();
        }

        int selectPrinter, printCount;
        char temp;
        while (true) {
            cout << endl;
            cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >> ";
            cin >> selectPrinter >> printCount;
            switch (selectPrinter) {
            case 1:
                printers[0]->print(printCount);
                break;
            case 2:
                printers[1]->print(printCount);
                break;
            }

            for (int i = 0; i < printerCount; i++) {
                printers[i]->show();
            }

            cout << "계속 프린트 하시겠습니까?(y/n) >> ";
            cin >> temp;
            if (temp == 'n')
                break;
        }
    }
};
int main() {
    Menu print;
    print.run();
}
*/