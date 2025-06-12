#include "pch.h"
#include "ClientManager.h"

void ClientManager::AddClient(const Client& client) {
	clientVector.push_back(client);
}

void ClientManager::Clear() {
	clientVector.clear();
}