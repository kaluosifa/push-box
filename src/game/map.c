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
        MAP_COL,
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
        MAP_COL,
        {3, 7},
        2,
        { {3, 4}, {5, 7} },
        { {3, 2}, {6, 7} }
    }
};

int g_map_nubmer;
struct Map g_current_map;   // 当前地图数据

char map_file_path[100] = "./map.config";

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
        printf("地图配置文件打开失败!\n");
        return false;
    }

    // 判断文件是否为空
    if (feof(f))
    {
        printf("地图配置文件中没有保存进度!\n");
        return false;
    }

    char ch = '\0';
    int row = 0;
    int col = 0;
    // 检测地图有多少列
    while (fgetc(f) != '\n')
    {
        ++col;
    }

    // 检测地图有多少行
    rewind(f);
    while (fgetc(f) == '#')
    {
        fseek(f, col + 1, SEEK_CUR); // 移动文件指针到下一行, 加1是因为换行符
        ++row;
    }

    // 读取地图
    rewind(f);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            g_current_map.m[i][j] = fgetc(f);
        }
        fgetc(f);   // 读取换行符
    }
    // 读取地图行数
    fscanf(f, "%d\n", &g_current_map.row);
    // 读取人物坐标
    fscanf(f, "%d, %d\n", &g_man.x, &g_man.y);
    // 读取箱子个数
    fscanf(f, "%d\n", &g_current_map.box_number);
    // 读取箱子坐标
    fscanf(f, "{");
    for (int i = 0; i < g_current_map.box_number; ++i)
    {
        fscanf(f, "{%d, %d}", &g_current_map.boxes[i].x, &g_current_map.boxes[i].y);
        if (i < g_current_map.box_number - 1)
            fscanf(f, ", ");
    }
    fscanf(f, "}\n");
    // 读取目标点坐标
    fscanf(f, "{");
    for (int i = 0; i < g_current_map.box_number; ++i)
    {
        fscanf(f, "{%d, %d}", &g_current_map.target[i].x, &g_current_map.target[i].y);
        if (i < g_current_map.box_number - 1)
            fscanf(f, ", ");
    }
    fscanf(f, "}\n");

    fclose(f);
    return true;
}

bool SaveMap()
{
    FILE *f = fopen(map_file_path, "w+");
    if (!f)
    {
        printf("保存文件失败!\n");
        return false;
    }

    // 写入地图
    for (int i = 0; i < g_current_map.row; ++i)
    {
        fprintf(f, "%s\n", g_current_map.m[i]);
    }
    // 写入地图行数
    fprintf(f, "%d\n", g_current_map.row);
    // 写入人物坐标
    fprintf(f, "%d, %d\n", g_man.x, g_man.y);
    // 写入箱子个数
    fprintf(f, "%d\n", g_current_map.box_number);
    // 写入箱子的坐标
    fprintf(f, "{");
    for (int i = 0; i < g_current_map.box_number; ++i)
    {
        fprintf(f, "{%d, %d}", g_current_map.boxes[i].x, \
            g_current_map.boxes[i].y);
        if (i < g_current_map.box_number - 1)
            fprintf(f, ", ");
    }
    fprintf(f, "}\n");
    // 写入目标点的坐标
    fprintf(f, "{");
    for (int i = 0; i < g_current_map.box_number; ++i)
    {
        fprintf(f, "{%d, %d}", g_current_map.target[i].x, \
            g_current_map.target[i].y);
        if (i < g_current_map.box_number - 1)
            fprintf(f, ", ");
    }
    fprintf(f, "}\n");

    fclose(f);
    return true;
}