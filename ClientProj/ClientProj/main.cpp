#include <iostream>
#include <string>
using namespace std;

class Client {
public:
	string name;
	string level;
	string id;
	string pw;
	string gender;
	string address;
	string phone;
	int age;
	Client(string name, string level = "none", string id="none", string pw="none", string gender="none", string address="none", string phone="none", int age=0) {
		this->name = name;
		this->level = level;
		this->id = id;
		this->pw = pw;
		this->gender = gender;
		this->address = address;
		this->phone = phone;
		this->age = age;
	}
};

class Clientmanager {
public:
	Client* clientlist[50];
	int numberclient;
	Clientmanager();
	void addClient(Client* cli);
	void displayClinet();
	void addClient_keyinput();
	void deleteClient(string name);
	void deleteClient_keyinput();
};

Clientmanager::Clientmanager() {
	numberclient = 0;
	cout << "***** client manager started *****" << endl << endl;
}

void Clientmanager::addClient(Client* cli) {
	clientlist[numberclient++] = cli;
	cout << "to add clients " << cli->name << endl;
}

void Clientmanager::addClient_keyinput() {
	string name, level;
	cout << endl << "***** Add Client with keyboard input *****" << endl;
	cout << "please enter name > ";
	getline(cin, name);
	cout << "please enter level > ";
	getline(cin, level);

	addClient(new Client(name, level));
	cout << "********************" << endl;
}

void Clientmanager::deleteClient(string name) {
	for (int i = 0; i < numberclient; i++) {
		if (clientlist[i]->name == name) {
			delete clientlist[i];
			cout << endl << "client " << name << " deleted" << endl;
			for (int j = i; j < numberclient - 1; j++) {
				clientlist[j] = clientlist[j + 1];
			}
			numberclient--;
		}
	}
}

void Clientmanager::deleteClient_keyinput() {
	string name;
	cout << endl << "***** Delete Client with keyboard input *****" << endl;
	cout << "please enter name to delete > ";
	getline(cin, name);

	deleteClient(name);
	cout << "********************" << endl;
}

void Clientmanager::displayClinet() {
	cout << endl << "***** Display Client *****" << endl;
	for (int i = 0; i < numberclient; i++) {
		cout << "client " << i+1 << ":" << endl;
		cout << "name: " << clientlist[i]->name << endl;
		cout << "level: " << clientlist[i]->level << endl;
		cout << "id: " << clientlist[i]->id << endl;
		cout << "pw: " << clientlist[i]->pw << endl;
		cout << "gender: " << clientlist[i]->gender << endl;
		cout << "address: " << clientlist[i]->address << endl;
		cout << "phone: " << clientlist[i]->phone << endl;
		cout << "age: " << clientlist[i]->age << endl << endl;
	}
	cout << "********************" << endl;
}

int main() {
	Clientmanager cmanager;

	//to add clients;
	cmanager.addClient(new Client("cherlhee", "A+", "id1", "pw1"));
	cmanager.addClient(new Client("jcradar", "B", "id2", "pw2"));
	cmanager.addClient(new Client("knu", "C", "id3", "pw3"));

	cmanager.addClient_keyinput();
	cmanager.addClient_keyinput();
	cmanager.addClient_keyinput();

	cmanager.deleteClient("cherlhee");
	cmanager.deleteClient_keyinput();

	cmanager.displayClinet();

	return 0;
}
