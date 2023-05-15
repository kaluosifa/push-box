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
        char ch = '\0';
        InitMap();
        g_flag = true;

        system("cls");
        printf("\n");
        printf("-------------------- Push Box --------------------\n");
        printf("\n");
        PrintMap(g_current_map);
        printf("\n");
        printf("Press 's' to start game or 'q' to quit \n");

        while (ch != 'q' && ch != 's')
            ch = getch();

        switch (ch)
        {
        case 'q':
            return;
        case 's':
            PlayGame();
            break;
        default:
            break;
        }
    }

    return;
}

void PlayGame()
{
    char ch = '\0';

    while (g_flag) {
        system("cls");
        PrintMap(g_current_map);

        ch = getch();
        if (ch == 'q')
        {
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
