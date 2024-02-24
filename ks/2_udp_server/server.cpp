#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

void handleError(const char* errorMessage) {
    cerr << "Error: " << errorMessage << " - " << WSAGetLastError() << endl;
    WSACleanup();
    exit(EXIT_FAILURE);
}

int main() {
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

    struct sockaddr_in ad;
    ad.sin_port = htons(1024);
    ad.sin_family = AF_INET;
    ad.sin_addr.s_addr = INADDR_ANY;

    if (bind(s, (struct sockaddr*)&ad, sizeof(ad)) == SOCKET_ERROR) {
        handleError("Bind failed");
    }

    char b[200];
    int l = sizeof(ad);

    int rv = recvfrom(s, b, sizeof(b), 0, (struct sockaddr*)&ad, &l);
    if (rv == SOCKET_ERROR) {
        handleError("recvfrom failed");
    }
    b[rv] = '\0';
    cout << "Received message: " << b << endl;

    int length = strlen(b);
    if (length % 2 == 0) {
        if (length >= 5) {
            // Удаляем 3 первых символа
            for (int i = 0; i < length - 3; ++i) {
                b[i] = b[i + 3];
            }
            // Удаляем 2 последних символа
            b[length - 5] = '\0';
        }
        else {
            // Если длина строки меньше 5, то просто возвращаем пустую строку
            b[0] = '\0';
        }
    }

    if (sendto(s, b, strlen(b), 0, (struct sockaddr*)&ad, l) == SOCKET_ERROR) {
        handleError("sendto failed");
    }

    closesocket(s);
    WSACleanup();
    return 0;
}
