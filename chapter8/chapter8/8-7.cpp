#include <iostream>
using namespace std;
/*
class BaseMemory
{
	char* mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	void burnMem(char x[], int burn){
		for (int i = 0; i < burn; i++)
			mem[i] = x[i];
	}
	char getMem(int i){
		return mem[i];
	}
	void setMem(int i, char x){
		mem[i] = x;
	}
};

class ROM : protected BaseMemory
{
	int RomSize, burn;
	char x[];
public:
	ROM(int size, char x[], int burn) : BaseMemory(size){
		this->RomSize = size;
		this->burn = burn;
		burnMem(x, burn);
	}
	char read(int i){
		return getMem(i);
	}
};

class RAM : protected BaseMemory{
	int RamSize;
public:
	RAM(int size) : BaseMemory(size){
		RamSize = size;
	}
	void write(int i, char x){
		setMem(i, x);
	}
	char read(int i){
		return getMem(i);
	}
};

int main(){
	char x[5] = { 'h' , 'e', 'l', 'l', 'o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}
*/