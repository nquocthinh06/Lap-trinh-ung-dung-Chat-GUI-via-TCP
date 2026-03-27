#include <iostream>
#include <thread>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstring>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

vector<SOCKET> clients;

void broadcast(const string& msg, SOCKET sender) {
    for (SOCKET client : clients) {
        if (client != sender) {
            send(client, msg.c_str(), (int)msg.length(), 0);
        }
    }
}

void handleClient(SOCKET clientSocket) {
    char buffer[1024];

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(clientSocket, buffer, sizeof(buffer), 0);

        if (bytes <= 0) {
            cout << "Client disconnected\n";
            closesocket(clientSocket);
            break;
        }

        string msg(buffer);
        cout << "Received: " << msg << endl;

        broadcast(msg, clientSocket);
    }
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    cout << "Server started on port 8888...\n";

    while (true) {
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);

        if (clientSocket == INVALID_SOCKET) {
            cout << "Accept failed!\n";
            continue;
        }

        clients.push_back(clientSocket);
        cout << "Client connected!\n";

        thread t(handleClient, clientSocket);
        t.detach();
    }

    closesocket(serverSocket);
    WSACleanup();
}