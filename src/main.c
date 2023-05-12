#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>

#define BOX_NUMBER 2

void ChooseMap(void);
void InitGame(void);
void StartGame(void);
void PrintMap(int n);
void Move(char ch);
bool Succeed(void);

struct Point {
    int x;
    int y;
};

struct Point g_man;

struct Map {
    char m[50][50];
    int row;
    int col;
    struct Point man;
    struct Point box[BOX_NUMBER];
    struct Point target[BOX_NUMBER];
};

struct Map g_maps[2] = {
    {},
    {
        {
            "##########",
            "#        #",
            "# x 0  $ #",
            "#      0 #",
            "######   #",
            "###### x #",
            "######   #",
            "##########",
        },
        8,
        10,
        {2, 7},
        { {2, 4}, {3, 7} },
        { {2, 2}, {5, 7} }
    }
};

struct Map g_map;
int g_map_number = 0;

int main()
{
    InitGame();
    StartGame();

    return 0;
}

void ChooseMap(void)
{
    puts("----Push Box----");
    puts("    1. 地图一    ");
    printf("\n");
    printf("请选择地图(1)：");

    while (g_map_number == 0) {
        char ch = getch();
        if (isdigit(ch)) {
            g_map_number = ch - '0';
        }
    }

    return;
}

void InitGame(void)
{
    system("chcp 65001");
    ChooseMap();
    g_man.x = g_maps[g_map_number].man.x;
    g_man.y = g_maps[g_map_number].man.y;

    system("cls");
    PrintMap(g_map_number);

    return;
}

void StartGame()
{
    char ch = '\0';

    while (!Succeed()) {
        ch = getch();
        Move(ch);
        system("cls");
        PrintMap(g_map_number);
    }

    printf("恭喜通关！\n");

    return;
}

void PrintMap(int n)
{
    for (int i = 0; i < g_maps[n].row; ++i) {
        puts(g_maps[n].m[i]);
    }

    return;
}

void Move(char ch)
{
    switch (ch) {
    case 's':
        {
            if (g_maps[g_map_number].m[g_man.x + 1][g_man.y] == '0' &&
                    (g_maps[g_map_number].m[g_man.x + 2][g_man.y] == ' ' ||
                    g_maps[g_map_number].m[g_man.x + 2][g_man.y] == 'x')) {
                g_maps[g_map_number].m[g_man.x][g_man.y] = ' ';
                ++g_man.x;
                g_maps[g_map_number].m[g_man.x + 1][g_man.y] = '0';
                g_maps[g_map_number].m[g_man.x][g_man.y] = '$';
            }
            if (g_maps[g_map_number].m[g_man.x + 1][g_man.y] == ' ') {
                g_maps[g_map_number].m[g_man.x][g_man.y] = ' ';
                ++g_man.x;
                g_maps[g_map_number].m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    case 'w':
        {
            if (g_maps[g_map_number].m[g_man.x - 1][g_man.y] == '0' &&
                    g_maps[g_map_number].m[g_man.x - 2][g_man.y] == ' ') {
                g_maps[g_map_number].m[g_man.x][g_man.y] = ' ';
                --g_man.x;
                g_maps[g_map_number].m[g_man.x - 1][g_man.y] = '0';
                g_maps[g_map_number].m[g_man.x][g_man.y] = '$';
            }
            if (g_maps[g_map_number].m[g_man.x - 1][g_man.y] == ' ') {
                g_maps[g_map_number].m[g_man.x][g_man.y] = ' ';
                --g_man.x;
                g_maps[g_map_number].m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    case 'a':
        {
            if (g_maps[g_map_number].m[g_man.x][g_man.y - 1] == '0' &&
                    g_maps[g_map_number].m[g_man.x][g_man.y - 2] == ' ') {
                g_maps[g_map_number].m[g_man.x][g_man.y] = ' ';
                --g_man.y;
                g_maps[g_map_number].m[g_man.x][g_man.y - 1] = '0';
                g_maps[g_map_number].m[g_man.x][g_man.y] = '$';
            }
            if (g_maps[g_map_number].m[g_man.x][g_man.y - 1] == ' ') {
                g_maps[g_map_number].m[g_man.x][g_man.y] = ' ';
                --g_man.y;
                g_maps[g_map_number].m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    case 'd':
        {
            if (g_maps[g_map_number].m[g_man.x][g_man.y + 1] == '0' &&
                    g_maps[g_map_number].m[g_man.x][g_man.y + 2] == ' ') {
                g_maps[g_map_number].m[g_man.x][g_man.y] = ' ';
                ++g_man.y;
                g_maps[g_map_number].m[g_man.x][g_man.y + 1] = '0';
                g_maps[g_map_number].m[g_man.x][g_man.y] = '$';
            }
            if (g_maps[g_map_number].m[g_man.x][g_man.y + 1] == ' ') {
                g_maps[g_map_number].m[g_man.x][g_man.y] = ' ';
                ++g_man.y;
                g_maps[g_map_number].m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    }

    return;
}

bool Succeed(void)
{
    for (int i = 0; i < BOX_NUMBER; ++i) {
        if (g_maps[g_map_number].box[i].x == g_maps[g_map_number].target[i].x &&
                g_maps[g_map_number].box[i].y == g_maps[g_map_number].target[i].y) {
            return true;
        } else {
            return false;
        }
    }
}
