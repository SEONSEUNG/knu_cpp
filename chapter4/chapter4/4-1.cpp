#include <iostream>
using namespace std;

/*
class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);
	Color* p;
	p = &screenColor; //(1) p가 scrrenColor의 주소를 가지도록 코드 작성
	p->show(); //(2) p가 show()를 이용하여 scrrenColor 색 출력
	Color colors[3]; //(3) Color의 일차원 배열 colors 선언. 원소는 3개
	p = colors; //(4) p가 colors 배열을 가리키도록 코드 작성

	//(5) p와 setColor()를 이용하여 colors[0], colors[1], colors[2]가
	//    각각 빨강, 초록, 파랑색을 가지도록 코드 작성
	p->setColor(255, 0, 0);
	(p + 1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

	//(6) p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력. for 문 이용
	for (int i = 0; i < 3; i++) {
		(p + i)->show();
	}
}
*/