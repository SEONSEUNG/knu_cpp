#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(4);
	v.push_back(16);
	v.push_back(169);

	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		int n = *it;
		n = sqrt(n);
		*it = n;
	}

	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}