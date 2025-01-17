#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "joke.h"

// 设置控制台编码为 UTF-8
void setConsoleUTF8() {
    SetConsoleOutputCP(CP_UTF8);
}

void moveMouseRandomly() {
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    int direction = rand() % 4;
    switch (direction) {
        case 0: // Up
            cursorPos.y--;
            break;
        case 1: // Down
            cursorPos.y++;
            break;
        case 2: // Left
            cursorPos.x--;
            break;
        case 3: // Right
            cursorPos.x++;
            break;
    }
    SetCursorPos(cursorPos.x, cursorPos.y);
}

void printCharByChar(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        putchar(str[i]);
        Sleep(100); // 调整这个时间可以控制打印速度
    }
    putchar('\n');
}

int main() {
    setConsoleUTF8();
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char timeStr[1000];
    sprintf(timeStr,"你好打工人~现在是公元 %d 年 %d 月 %d 日 %d 时 %d 分，距离春节还有%d天\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min,29-timeinfo->tm_mday);

    printCharByChar(timeStr);

    srand((unsigned int)time(NULL));
    while (1) {
        moveMouseRandomly();
        Sleep(50000);
    }
    return 0;
}