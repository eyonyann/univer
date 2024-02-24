#include <iostream>
#include <winsock2.h>

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

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        handleError("Socket creation failed");
    }

    sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(1280);
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    result = bind(s, (struct sockaddr*)&local, sizeof(local));
    if (result == SOCKET_ERROR) {
        handleError("Binding failed");
    }

    result = listen(s, 5);
    if (result == SOCKET_ERROR) {
        handleError("Listening failed");
    }

    SOCKET s2;
    sockaddr_in remote_addr;
    int size = sizeof(remote_addr);

    while (true) {
        s2 = accept(s, (struct sockaddr*)&remote_addr, &size);
        if (s2 == INVALID_SOCKET) {
            handleError("Accepting connection failed");
        }

        char buf[255], res[255];
        int bytesReceived = recv(s2, buf, sizeof(buf), 0);
        if (bytesReceived > 0) {
            buf[bytesReceived] = '\0';

            int len = strlen(buf);
            for (int i = 0; i < len; ++i) {
                res[i] = buf[len - i - 1];
            }
            res[len] = '\0';

            result = send(s2, res, strlen(res), 0);
            if (result == SOCKET_ERROR) {
                handleError("Sending data failed");
            }
        }
        else if (bytesReceived == 0) {
            std::cerr << "Connection closed by client" << std::endl;
        }
        else {
            handleError("Receiving data failed");
        }

        closesocket(s2);
    }

    WSACleanup();
    return 0;
}