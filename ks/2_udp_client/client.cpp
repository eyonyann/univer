#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

void handleError(const char* errorMessage) {
    cerr << "Error: " << errorMessage << " - " << WSAGetLastError() << endl;
    WSACleanup();
    exit(EXIT_FAILURE);
}

int main()
{
    char buf[100], b[100];
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        handleError("WSAStartup failed");
    }

    SOCKET s;
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s == INVALID_SOCKET) {
        handleError("Failed to create socket");
    }

    sockaddr_in add;
    add.sin_family = AF_INET;
    add.sin_port = htons(1024);
    inet_pton(AF_INET, "127.0.0.1", &add.sin_addr);

    int t;
    t = sizeof(add);
    cout << "Enter the string, please" << endl;
    cin.getline(buf, sizeof(buf), '\n'); // use sizeof(buf) instead of hardcoding 100

    int sentBytes = sendto(s, buf, strlen(buf), 0, (struct sockaddr*)&add, t);
    if (sentBytes == SOCKET_ERROR) {
        handleError("sendto failed");
    }

    int rv = recvfrom(s, b, sizeof(b), 0, (struct sockaddr*)&add, &t);
    if (rv == SOCKET_ERROR) {
        handleError("recvfrom failed");
    }
    b[rv] = '\0';
    cout << "Received message: " << b << endl;

    closesocket(s);

    WSACleanup();
    return 0;
}
