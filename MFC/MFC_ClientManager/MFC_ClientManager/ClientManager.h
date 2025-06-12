#pragma once
#include <afxwin.h>
#include "Client.h"
#include <vector>

class ClientManager :
    public CWnd
{
public:
    vector<Client> clientVector;

    void AddClient(const Client& client);
    void Clear();
};

