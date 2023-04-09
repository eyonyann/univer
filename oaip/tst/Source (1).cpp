#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void goToXY(short x, short y);
void goToCenter();
void printCenteredMessage(const std::string& message);

//void ConsoleCursorVisible(bool show, short size)
//{
//  CONSOLE_CURSOR_INFO structCursorInfo;
//  GetConsoleCursorInfo(hStdOut, &structCursorInfo);
//  structCursorInfo.bVisible = show; 
//  structCursorInfo.dwSize = size; 
//  SetConsoleCursorInfo(hStdOut, &structCursorInfo);
//}

int main()
{
    SetConsoleTitle(L"Medical center");

    //ConsoleCursorVisible(false, 100);

    printCenteredMessage("Hello world");

    return 0;
}

void goToCenter()
{
    HWND console = GetConsoleWindow();
    HDC hdc = GetDC(console);
    RECT rect;
    GetClientRect(console, &rect);
    int centerX = (rect.right - rect.left) / 2;
    int centerY = (rect.bottom - rect.top) / 2;
    SetCursorPos(centerX, centerY);
    ReleaseDC(console, hdc);
}


void goToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, { x, y });
}

void printCenteredMessage(const std::string& message)
{
    // ѕолучаем дескриптор консольного окна
    HWND console = GetConsoleWindow();

    // ѕолучаем контекст устройства дл€ консольного окна
    HDC hdc = GetDC(console);

    // ѕолучаем размеры консольного окна
    RECT rect;
    GetClientRect(console, &rect);

    // ¬ычисл€ем координаты центра консольного окна
    int centerX = (rect.right - rect.left) / 2;
    int centerY = (rect.bottom - rect.top) / 2;

    // ”станавливаем позицию курсора в центре консольного окна
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(centerX - message.size() / 2), static_cast<short>(centerY) });

    // ¬ыводим сообщение в установленной позиции
    std::cout << message;

    // ќсвобождаем контекст устройства
    ReleaseDC(console, hdc);
}