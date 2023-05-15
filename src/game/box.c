#include "../include/box.h"

bool BoxTopMove(struct Point * box)
{
    bool top_moved = false;

    switch (g_current_map.m[box->x - 1][box->y])
    {
    case ' ':
        {
            g_current_map.m[box->x][box->y] = ' ';
            --box->x;
            g_current_map.m[box->x][box->y] = '@';

            top_moved = true;
        }
        break;
    case 'x':
        {
            g_current_map.m[box->x][box->y] = ' ';
            --box->x;
            g_current_map.m[box->x][box->y] = ' ';

            top_moved = true;
        }
        break;
    default:
        break;
    }

    return top_moved;
}

bool BoxDownMove(struct Point * box)
{
    bool down_moved = false;

    switch (g_current_map.m[box->x + 1][box->y])
    {
    case ' ':
        {
            g_current_map.m[box->x][box->y] = ' ';
            ++box->x;
            g_current_map.m[box->x][box->y] = '@';

            down_moved = true;
        }
        break;
    case 'x':
        {
            g_current_map.m[box->x][box->y] = ' ';
            ++box->x;
            g_current_map.m[box->x][box->y] = ' ';

            down_moved = true;
        }
        break;
    default:
        break;
    }

    return down_moved;
}

bool BoxLeftMove(struct Point * box)
{
    bool left_moved = false;

    switch (g_current_map.m[box->x][box->y - 1])
    {
    case ' ':
        {
            g_current_map.m[box->x][box->y] = ' ';
            --box->y;
            g_current_map.m[box->x][box->y] = '@';

            left_moved = true;
        }
        break;
    case 'x':
        {
            g_current_map.m[box->x][box->y] = ' ';
            --box->y;
            g_current_map.m[box->x][box->y] = ' ';

            left_moved = true;
        }
        break;
    default:
        break;
    }

    return left_moved;
}

bool BoxRightMove(struct Point * box)
{
    bool right_moved = false;

    switch (g_current_map.m[box->x][box->y + 1])
    {
    case ' ':
        {
            g_current_map.m[box->x][box->y] = ' ';
            ++box->y;
            g_current_map.m[box->x][box->y] = '@';

            right_moved = true;
        }
        break;
    case 'x':
        {
            g_current_map.m[box->x][box->y] = ' ';
            ++box->y;
            g_current_map.m[box->x][box->y] = ' ';

            right_moved = true;
        }
        break;
    default:
        break;
    }

    return right_moved;
}

bool BoxMove(char ch)
{
    bool moved = false;  // 箱子移动的标志
    int boxIndex = 0;
    struct Point box;

    // 判断动的是哪一个箱子
    boxIndex = WhichBox(ch);

    switch (ch)
    {
    case 'w':
        moved = BoxTopMove(&g_current_map.boxes[boxIndex]);
        break;
    case 's':
        moved = BoxDownMove(&g_current_map.boxes[boxIndex]);
        break;
    case 'a':
        moved = BoxLeftMove(&g_current_map.boxes[boxIndex]);
        break;
    case 'd':
        moved = BoxRightMove(&g_current_map.boxes[boxIndex]);
        break;
    default:
        break;
    }

    return moved;
}

int WhichBox(char ch)
{
    struct Point box = {0, 0};
    int boxIndex = 0;

    switch (ch)
    {
    case 'w':
        {
            box.x = g_man.x - 1;
            box.y = g_man.y;
        }
        break;
    case 's':
        {
            box.x = g_man.x + 1;
            box.y = g_man.y;
        }
        break;
    case 'a':
        {
            box.x = g_man.x;
            box.y = g_man.y - 1;
        }
        break;
    case 'd':
        {
            box.x = g_man.x;
            box.y = g_man.y + 1;
        }
        break;
    default:
        break;
    }

    for (int i = 0; i < g_current_map.box_number; ++i)
    {
        if (g_current_map.boxes[i].x == box.x && \
            g_current_map.boxes[i].y == box.y)
        {
            boxIndex = i;
            break;
        }
    }

    return boxIndex;
}