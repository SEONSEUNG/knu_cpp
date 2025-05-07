#include <iostream>
#include <string>
using namespace std;
/*
class Color
{
	int r, g, b;
public:
	Color(int r = 0, int g = 0, int b = 0)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}

	friend Color operator + (Color op, Color op1);
	friend bool operator == (Color op, Color op1);

	void show();
};

Color operator + (Color op, Color op1) {
	Color tmp;
	tmp.r = op.r + op1.r;
	tmp.g = op.g + op1.g;
	tmp.b = op.b + op1.b;
	return tmp;
}

bool operator == (Color op, Color op1) {
	if (op.r == op1.r && op.g == op1.g && op.b == op1.b) return true;
	else return false;
}

void Color::show()
{
	cout << r << ' ' << g << ' ' << b << endl;
}

int main()
{
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}
*/