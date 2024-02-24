#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

void handleError(const char* errorMessage) {
    std::cerr << "Error: " << errorMessage << " - " << WSAGetLastError() << std::endl;
    WSACleanup();
    exit(EXIT_FAILURE);
}


int main() {
    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD(2, 2);
    int result = WSAStartup(wVersionRequested, &wsaData);
    if (result != 0) {
        handleError("WSAStartup failed");
    }

    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(1280);
    inet_pton(AF_INET, "127.0.0.1", &peer.sin_addr);

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        handleError("Socket creation failed");
    }

    result = connect(s, (struct sockaddr*)&peer, sizeof(peer));
    if (result == SOCKET_ERROR) {
        handleError("Connection failed");
    }

    char buf[255], b[255];
    std::cout << "Enter the string, please: ";
    std::cin.getline(buf, sizeof(buf));

    result = send(s, buf, strlen(buf), 0);
    if (result == SOCKET_ERROR) {
        handleError("Sending data failed");
    }

    int bytesReceived = recv(s, b, sizeof(b), 0);
    if (bytesReceived > 0) {
        b[bytesReceived] = '\0'; // Убедимся, что строка завершается нулевым символом
        std::cout << "Reversed string from server: " << b << std::endl;
    }
    else if (bytesReceived == 0) {
        std::cerr << "Connection closed by server" << std::endl;
    }
    else {
        handleError("Receiving data failed");
    }

    closesocket(s);
    WSACleanup();

    return 0;
}