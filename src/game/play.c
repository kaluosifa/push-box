#include "../include/play.h"

bool Pass()
{
    bool is_passed = false;
    int num = 0;

    for (int i = 0; i < g_current_map.box_number; ++i)
    {
        if (g_current_map.boxes[i].x == g_current_map.target[i].x && \
                g_current_map.boxes[i].y == g_current_map.target[i].y)
        {
            ++num;
        }
    }

    if (num == g_current_map.box_number)
    {
        system("cls");
        printf("                  恭喜你通关!                  \n");
        printf("\n按任意键退出到主界面:\n");
        char ch = '\0';
        ch = getch();
        is_passed = true;
    }

    return is_passed;
}

void ManMove(char ch)
{
    switch (ch)
    {
    case 'w':
        ManTopMove();
        break;
    case 's':
        ManDownMove();
        break;
    case 'a':
        ManLeftMove();
        break;
    case 'd':
        ManRightMove();
        break;
    default:
        break;
    }

    return;
}