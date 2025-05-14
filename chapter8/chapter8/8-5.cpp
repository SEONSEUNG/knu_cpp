#include <iostream>
using namespace std;
/*
class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capaticy = 100) {
		this->capacity = capaticy; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
	int front, rear;
public:
	MyQueue(int cap = 100) : BaseArray(cap){
		this->front = 0;
		this->rear = 0;
	}
	void enqueue(int x) {
		if (rear < getCapacity()) {
			put(rear, x);
			rear += 1;
		}
	}
	int dequeue() {
		int temp;
		if (front < rear) {
			temp = get(front);
			front += 1;
			return temp;
		}
		return -1; // 오류 처리 (큐가 비었을 경우)
	}
	int capacity() {
		return getCapacity();
	}
	int length() {
		return rear - front;
	}
};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}
*/