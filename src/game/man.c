#include "../include/man.h"

void ManTopMove()
{
    switch (g_current_map.m[g_man.x - 1][g_man.y])
    {
    case ' ':
        {
            g_current_map.m[g_man.x][g_man.y] = ' ';
            --g_man.x;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    case '@':
        {
            // 箱子动了，人才能动(相当于人推箱子)
            if (BoxMove('w'))
            {
                g_current_map.m[g_man.x][g_man.y] = ' ';
                --g_man.x;
                g_current_map.m[g_man.x][g_man.y] = '$';
            }

        }
        break;
    case 'x':
        {

        }
        break;
    default:
        break;
    }

    return;
}

void ManDownMove()
{
    switch (g_current_map.m[g_man.x + 1][g_man.y])
    {
    case ' ':
        {
            g_current_map.m[g_man.x][g_man.y] = ' ';
            ++g_man.x;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    case '@':
        {
            // 箱子动了，人才能动(相当于人推箱子)
            if (BoxMove('s'))
            {
                g_current_map.m[g_man.x][g_man.y] = ' ';
                ++g_man.x;
                g_current_map.m[g_man.x][g_man.y] = '$';
            }

        }
        break;
    case 'x':
        {

        }
        break;
    default:
        break;
    }

    return;
}

void ManLeftMove()
{
    switch (g_current_map.m[g_man.x][g_man.y - 1])
    {
    case ' ':
        {
            g_current_map.m[g_man.x][g_man.y] = ' ';
            --g_man.y;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    case '@':
        {
            // 箱子动了，人才能动(相当于人推箱子)
            if (BoxMove('a'))
            {
                g_current_map.m[g_man.x][g_man.y] = ' ';
                --g_man.y;
                g_current_map.m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    case 'x':
        {

        }
        break;
    default:
        break;
    }

    return;
}

void ManRightMove()
{
    switch (g_current_map.m[g_man.x][g_man.y + 1])
    {
    case ' ':
        {
            g_current_map.m[g_man.x][g_man.y] = ' ';
            ++g_man.y;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    case '@':
        {
            // 箱子动了，人才能动(相当于人推箱子)
            if (BoxMove('d'))
            {
                g_current_map.m[g_man.x][g_man.y] = ' ';
                ++g_man.y;
                g_current_map.m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    case 'x':
        {

        }
        break;
    default:
        break;
    }

    return;
}