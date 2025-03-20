#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*
class Date{
	int year, month, day;
public:
	Date(int y, int m, int d);
	Date(string s);
	void show();
	int getYear();
	int getMonth();
	int getDay();
};

Date::Date(int y, int m, int d) {
	year = y; month = m; day = d;
}

Date::Date(string s){
	int find1 = s.find('/');
	int find2 = s.find('/', find1 + 1);
	year = stoi(s.substr(0,find1));
	month = stoi(s.substr(find1 + 1, find2));
	day = stoi(s.substr(find2 + 1));
}

int Date::getYear() {
	return year;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

void Date::show() {
	cout << year << "³â" << month << "¿ù" << day << "ÀÏ" << endl;
}

int main() {

	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;

}
*/