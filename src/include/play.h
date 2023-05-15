// Copyright (c). 2023. All rights reserved.
// Author: kaluosifa
// Date: 2023-05-14

#ifndef SRC_INCLUDE_PLAY_H_
#define SRC_INCLUDE_PLAY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include "map.h"
#include "box.h"
#include "man.h"

extern struct Point g_man;
extern struct Map g_maps[MAP_NUBMER];
extern struct Map g_current_map;

// 人物移动
void ManMove(char ch);

// 判断是否通关
bool Pass();

#ifdef __cplusplus
}
#endif

#endif  // SRC_INCLUDE_PLAY_H_
