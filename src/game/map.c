#include "../include/map.h"

struct Point g_man; // 玩家位置

struct Map g_maps[MAP_NUBMER] = {
    {
        {
            "##########",
            "##########",
            "#        #",
            "# x @  $ #",
            "#        #",
            "##  ### ##",
            "##   @ x #",
            "##       #",
            "##########",
            "##########",
        },
        10,
        {3, 7},
        2,
        { {3, 4}, {6, 5} },
        { {3, 2}, {6, 7} }
    },
    {
        {
            "##########",
            "##########",
            "#        #",
            "# x @  $ #",
            "#        #",
            "###### @ #",
            "###### x #",
            "######   #",
            "##########",
            "##########",
        },
        10,
        {3, 7},
        2,
        { {3, 4}, {5, 7} },
        { {3, 2}, {6, 7} }
    }
};

int g_map_nubmer;
struct Map g_current_map;   // 当前地图数据

char map_file_path[100] = "E:/Qt Projects/learn C/PushBox/PushBox/map.conf";

void PrintMap(struct Map m)
{
    for (int i = 0; i < m.row; ++i)
    {
        printf("                    ");
        printf("%s", m.m[i]);
        printf("                    \n");
    }

    return;
}

void SetMap(struct Map t_map)
{
    for (int i = 0; i < t_map.row; ++i)
    {
        strcpy(g_current_map.m[i], t_map.m[i]);

        g_current_map.row = t_map.row;

        g_current_map.man.x = t_map.man.x;
        g_current_map.man.y = t_map.man.y;

        g_current_map.box_number = t_map.box_number;

        for (int j = 0; j < t_map.box_number; ++j)
        {
            g_current_map.boxes[i].x = t_map.boxes[i].x;
            g_current_map.boxes[i].y = t_map.boxes[i].y;

            g_current_map.target[i].x = t_map.target[i].x;
            g_current_map.target[i].y = t_map.target[i].y;
        }
    }

    g_man.x = t_map.man.x;
    g_man.y = t_map.man.y;

    return;
}

void InitMap()
{
    SetMap(g_maps[0]);

    return;
}

bool LoadMap()
{
    FILE *f = fopen(map_file_path, "r");
    if (!f)
    {
        printf("地图文件打开失败!\n");
        return false;
    }

    struct Map map;

}

bool SaveMap()
{
    return false;
}