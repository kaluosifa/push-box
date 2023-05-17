#include "../include/game.h"

bool g_flag = true;

void StartInterface()
{
    system("cls");
    system("chcp 65001");   // 更换字符编码为UTF-8
    system("mode con cols=50 lines=20");

    char ch = '\0';

    while (true) {
        // 初始化
        ch = '\0';
        InitMap();
        g_flag = true;

        system("cls");
        printf("\n");
        printf("-------------------- Push Box --------------------\n");
        printf("\n");
        PrintMap(g_current_map);
        printf("\n");
        printf("Press 's' to start game or 'q' to quit \n");

        while (ch != 'q' && ch != 's' && ch != 'c')
            ch = getch();

        switch (ch)
        {
        case 'q':
            return;
        case 'c':
            {
                LoadMap();
            }
        case 's':
            {
                PlayGame();
            }
            break;
        }
    }

    return;
}

void PlayGame()
{
    char ch = '\0';
    bool ch_flag = false;

    while (g_flag) {
        ch = '\0';
        ch_flag = false;
        system("cls");
        PrintMap(g_current_map);

        while (!ch_flag)
        {
            ch = getch();
            switch (ch)
            {
            case 'q':
            case 'w':
            case 's':
            case 'a':
            case 'd':
            case 'x':
                ch_flag = true;
                break;
            default:
                break;
            }
        }

        if (ch == 'q')
        {
            Exit();
            continue;
        }
        else if (ch == 'x')
        {
            SaveMap();
            Exit();
            continue;
        }
        else
        {
            ManMove(ch);
            if (Pass())
            {
                g_flag = false;
            }
        }
    }

    return;
}

void StartGame()
{
    StartInterface();

    return;
}

void Exit()
{
    // 保存当前地图，作为游戏进度
    g_flag = false;

    return;
}

