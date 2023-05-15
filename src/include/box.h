// Copyright (c). 2023. All rights reserved.
// Author: kaluosifa
// Date: 2023-05-15

#ifndef SRC_INCLUDE_BOX_H_
#define SRC_INCLUDE_BOX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "map.h"

extern struct Point g_man;
extern struct Map g_maps[MAP_NUBMER];
extern struct Map g_current_map;

bool BoxTopMove(struct Point * box);
bool BoxDownMove(struct Point * box);
bool BoxLeftMove(struct Point * box);
bool BoxRightMove(struct Point * box);
bool BoxMove(char ch);

// 哪个箱子动
int WhichBox(char ch);

#ifdef __cplusplus
}
#endif

#endif  // SRC_INCLUDE_BOX_H_
