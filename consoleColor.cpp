//
// Created by milan on 10.08.2021.
//

#include<windows.h>

void setConsoleColor(int foreground, int background)
{
    WORD consoleColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        consoleColor = (foreground + (background * 16));
        SetConsoleTextAttribute(hStdOut, consoleColor);
    }
}