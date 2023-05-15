// Copyright (c). 2023. All rights reserved.
// Author: kaluosifa
// Date: 2023-05-14

#ifndef SRC_INCLUDE_GAME_H_
#define SRC_INCLUDE_GAME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "play.h"
#include "map.h"

extern struct Point g_man;
extern struct Map g_maps[MAP_NUBMER];
extern struct Map g_current_map;

// 开始界面
void StartInterface();

// 开始游戏
void PlayGame();

// 启动游戏
void StartGame();

// 退出
void Exit();

#ifdef __cplusplus
}
#endif

#endif  // SRC_INCLUDE_GAME_H_
