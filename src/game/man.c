#include "../include/man.h"

void ManTopMove()
{
    switch (g_current_map.m[g_man.x - 1][g_man.y])
    {
    case ' ':
        {
            // 判断人物是否踩在目标点上
            if (ManOnTarget() && !BoxOnTarget())
            {
                g_current_map.m[g_man.x][g_man.y] = 'x';
            }
            else
            {
                g_current_map.m[g_man.x][g_man.y] = ' ';
            }
            --g_man.x;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    case '@':
        {
            // 箱子动了，人才能动(相当于人推箱子)
            if (BoxMove('w'))
            {
                // 判断人物是否踩在目标点上
                if (ManOnTarget() && !BoxOnTarget())
                {
                    g_current_map.m[g_man.x][g_man.y] = 'x';
                }
                else
                {
                    g_current_map.m[g_man.x][g_man.y] = ' ';
                }
                --g_man.x;
                g_current_map.m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    case 'x':
        {
            // 玩家能移动到目标点上，从目标点上移出后目标点重新显示
            g_current_map.m[g_man.x][g_man.y] = ' ';
            --g_man.x;
            g_current_map.m[g_man.x][g_man.y] = '$';
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
            // 判断人物是否踩在目标点上
            if (ManOnTarget() && !BoxOnTarget())
            {
                g_current_map.m[g_man.x][g_man.y] = 'x';
            }
            else
            {
                g_current_map.m[g_man.x][g_man.y] = ' ';
            }
            ++g_man.x;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    case '@':
        {
            // 箱子动了，人才能动(相当于人推箱子)
            if (BoxMove('s'))
            {
                // 判断人物是否踩在目标点上
                if (ManOnTarget() && !BoxOnTarget())
                {
                    g_current_map.m[g_man.x][g_man.y] = 'x';
                }
                else
                {
                    g_current_map.m[g_man.x][g_man.y] = ' ';
                }
                ++g_man.x;
                g_current_map.m[g_man.x][g_man.y] = '$';
            }

        }
        break;
    case 'x':
        {
            // 玩家能移动到目标点上，从目标点上移出后目标点重新显示
            g_current_map.m[g_man.x][g_man.y] = ' ';
            ++g_man.x;
            g_current_map.m[g_man.x][g_man.y] = '$';
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
            // 判断人物是否踩在目标点上
            if (ManOnTarget() && !BoxOnTarget())
            {
                g_current_map.m[g_man.x][g_man.y] = 'x';
            }
            else
            {
                g_current_map.m[g_man.x][g_man.y] = ' ';
            }
            --g_man.y;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    case '@':
        {
            // 箱子动了，人才能动(相当于人推箱子)
            if (BoxMove('a'))
            {
                // 判断人物是否踩在目标点上
                if (ManOnTarget() && !BoxOnTarget())
                {
                    g_current_map.m[g_man.x][g_man.y] = 'x';
                }
                else
                {
                    g_current_map.m[g_man.x][g_man.y] = ' ';
                }
                --g_man.y;
                g_current_map.m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    case 'x':
        {
            g_current_map.m[g_man.x][g_man.y] = ' ';
            --g_man.y;
            g_current_map.m[g_man.x][g_man.y] = '$';
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
            // 判断人物是否踩在目标点上
            if (ManOnTarget() && !BoxOnTarget())
            {
                g_current_map.m[g_man.x][g_man.y] = 'x';
            }
            else
            {
                g_current_map.m[g_man.x][g_man.y] = ' ';
            }
            ++g_man.y;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    case '@':
        {
            // 箱子动了，人才能动(相当于人推箱子)
            if (BoxMove('d'))
            {
                // 判断人物是否踩在目标点上
                if (ManOnTarget() && !BoxOnTarget())
                {
                    g_current_map.m[g_man.x][g_man.y] = 'x';
                }
                else
                {
                    g_current_map.m[g_man.x][g_man.y] = ' ';
                }
                ++g_man.y;
                g_current_map.m[g_man.x][g_man.y] = '$';
            }
        }
        break;
    case 'x':
        {
            g_current_map.m[g_man.x][g_man.y] = ' ';
            ++g_man.y;
            g_current_map.m[g_man.x][g_man.y] = '$';
        }
        break;
    default:
        break;
    }

    return;
}