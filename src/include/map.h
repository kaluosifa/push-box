// Copyright (c). 2023. All rights reserved.
// Author: kaluosifa
// Date: 2023-05-14

#ifndef SRC_INCLUDE_MAP_H_
#define SRC_INCLUDE_MAP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOX_NUMBER 10
#define MAP_NUBMER 2
#define MAP_ROW 10
#define MAP_COL 10

struct Point {
    int x;
    int y;
};

struct Map {
    char m[50][50];     // 字符地图
    int row;   // 地图的大小
    struct Point man;   // 地图中人物的初始位置
    int box_number;
    struct Point boxes[BOX_NUMBER];   // 箱子的初始位置
    struct Point target[BOX_NUMBER];    // 目标点的初始位置
};

// 打印当前地图
void PrintMap(struct Map m);

// 设置当前地图
void SetMap();

// 初始化当前地图
void InitMap();

// 加载地图
bool LoadMap();

// 保存地图
bool SaveMap();

#ifdef __cplusplus
}
#endif

#endif  // SRC_INCLUDE_MAP_H_