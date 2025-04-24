#include <iostream>
#include <string>
using namespace std;

/*

class Histogram {
	string str;
	string str_plus;
	string str_alphabetOnly;
public:
	Histogram(string input);
	void put(string input);
	void putc(char input_c);
	void print();
};

Histogram::Histogram(string input) {
	this->str = input;
}

void Histogram::put(string input) {
	str_plus.append(input);
}

void Histogram::putc(char input_c) {
	string input_char;
	input_char = input_c;
	str_plus.append(input_char);
}

void Histogram::print() {

	int n1 = str.length();
	int n2 = str_plus.length();
	int histo[26] = { 0 };

	for (int i = 0; i < n1; i++) {
		if (isalpha(str[i])) {
			str_alphabetOnly.push_back(tolower(str[i]));
		}
	}
	for (int i = 0; i < n2; i++) {
		if (isalpha(str_plus[i])) {
			str_alphabetOnly.push_back(tolower(str_plus[i]));
		}
	}

	for (int i = 0; i < str_alphabetOnly.length(); i++) {
		//97~122
		for (int j = 97; j < 123; j++) {
			if (int(str_alphabetOnly[i]) == j) {
				histo[j-97] += 1;
			}
		}
	}

	cout << this->str << endl;
	cout << this->str_plus << endl << endl;

	cout << "ÃÑ ¾ËÆÄºª ¼ö " << str_alphabetOnly.length() << endl << endl;

	for (int i = 0; i < 26; i++) {
		cout << char(i+97) << " (" << histo[i] << ")\t: ";
		for (int j = 1; j <= histo[i]; j++) {
			cout << '*';
		}
		cout << endl;
	}

}

int main() {

	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();

}
*/