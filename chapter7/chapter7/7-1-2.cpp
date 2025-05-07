#include <iostream>
using namespace std;
/*
class Book
{
	string title;
	int price, pages;
public:
	Book(string title = " ", int price = 0, int pages = 0)
	{
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	friend Book& operator += (Book& op, int x);
	friend Book& operator -= (Book& op, int x);

	void show()
	{
		cout << title << ' ' << price << "원 " << pages << "페이지" << endl;
	}
	string getTitle() { return title; }
};

Book& operator += (Book& op, int x)
{
	op.price += x;
	return op;
}

Book& operator -= (Book& op, int x)
{
	op.price -= x;
	return op;
}

int main()
{
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}
*/